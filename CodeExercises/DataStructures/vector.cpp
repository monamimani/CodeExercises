#include "fuzztest/fuzztest.h"
#include "benchmark/benchmark.h"
#include "gtest/gtest.h"
#include <initializer_list>
#include <type_traits>

import std;

template <typename T>
class Vector
{
  public:

  Vector() = default;

  Vector(const std::initializer_list<T>& init)
  : m_size{init.size()}
  , m_capacity{m_size}
  , m_data{std::make_unique<T[]>(m_capacity)}
  {
    std::ranges::copy(init, m_data.get());
  }

  Vector(const std::span<const T>& span)
  : m_size{span.size()}
  , m_capacity{m_size}
  , m_data{std::make_unique<T[]>(m_capacity)}
  {
    std::ranges::copy(span, m_data.get());
  }

  auto size() const
  {
    return m_size;
  }
  auto capacity() const
  {
    return m_capacity;
  }

  auto empty() const
  {
    return m_size == 0;
  }

  auto view() const
  {
    return std::span<T>{m_data.get(), m_size};
  }

  void reserve(std::size_t newCapacity)
  {
    if(newCapacity > m_capacity)
    {
      auto newData = std::make_unique<T[]>(newCapacity);
      std::ranges::copy(view(), newData.get());
      m_data = std::move(newData);
      m_capacity = newCapacity;
    }
  }

  template <typename Self>
  auto data(this Self&& self) -> std::conditional_t<std::is_const_v<std::remove_reference_t<Self>>, const T*, T*>
  {
    return std::forward<Self>(self).m_data.get();
  }
  template <typename Self>
  auto operator[](this Self&& self, std::size_t index) -> std::conditional_t<std::is_const_v<std::remove_reference_t<Self>>, const T&, T&>
  {
    if (index < 0 || index >= std::forward<Self>(self).m_size || !std::forward<Self>(self).m_data)
    {
      throw std::out_of_range("Index out of range");
    }
    return std::forward<Self>(self).m_data[index];
  }


  private:
  std::size_t m_size = 0;
  std::size_t m_capacity = 0;
  std::unique_ptr<T[]> m_data;

};

TEST(DataStructures, VectorEmpty) {
  auto vec = Vector<int>{};
  EXPECT_EQ(vec.size(), 0);
  EXPECT_EQ(vec.capacity(), 0);
  EXPECT_EQ(vec.data(), nullptr);
  EXPECT_THROW(vec[0z], std::out_of_range);
  EXPECT_THROW(vec[static_cast<std::size_t>(-1)], std::out_of_range);
  EXPECT_THROW(vec[1z], std::out_of_range);

  const auto& vecConst = vec;
  static_assert(std::is_const_v<std::remove_pointer_t<decltype(vecConst.data())>>);
  static_assert(std::is_const_v<std::remove_reference_t<decltype(vecConst[0z])>>);
  EXPECT_THROW(vecConst[0z], std::out_of_range);
}

TEST(DataStructures, VectorInitializerList) {
  const auto vec = Vector<int>{1, 2, 3};
  EXPECT_EQ(vec.size(), 3);
  EXPECT_EQ(vec.capacity(), 3);
  EXPECT_NE(vec.data(), nullptr);
  EXPECT_EQ(vec[0z], 1);
  EXPECT_EQ(vec[1z], 2);
  EXPECT_EQ(vec[2z], 3);
  EXPECT_THROW(vec[3z], std::out_of_range);
  EXPECT_THROW(vec[static_cast<std::size_t>(-1)], std::out_of_range);
}

TEST(DataStructures, VectorSpan) {
  int buf[]{1, 2, 3};
  const auto vec = Vector<int>{std::span{buf}};
  EXPECT_EQ(vec.size(), 3);
  EXPECT_EQ(vec.capacity(), 3);
  EXPECT_NE(vec.data(), nullptr);
  EXPECT_EQ(vec[0z], 1);
  EXPECT_EQ(vec[1z], 2);
  EXPECT_EQ(vec[2z], 3);
  EXPECT_THROW(vec[3z], std::out_of_range);
  EXPECT_THROW(vec[static_cast<std::size_t>(-1)], std::out_of_range);
}

TEST(DataStructures, VectorReserve) {
  auto vec = Vector<int>{1, 2, 3};
  vec.reserve(6);
  EXPECT_EQ(vec.size(), 3);
  EXPECT_EQ(vec.capacity(), 6);
  EXPECT_NE(vec.data(), nullptr);
  EXPECT_EQ(vec[0z], 1);
  EXPECT_EQ(vec[1z], 2);
  EXPECT_EQ(vec[2z], 3);
}

void FuzzTestVectorSpan(const std::vector<int>& init) {
  auto vec = Vector<int>{std::span{init}};
  EXPECT_EQ(vec.size(), init.size());
  EXPECT_EQ(vec.capacity(), init.size());
  EXPECT_NE(vec.data(), nullptr);
  EXPECT_EQ(vec.view().size(), init.size());

  for (std::size_t i = 0; i < init.size(); ++i) {
    EXPECT_EQ(vec[i], init[i]);
  }
}
FUZZ_TEST(DataStructures, FuzzTestVectorSpan);
