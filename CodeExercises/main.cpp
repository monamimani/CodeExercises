#include "fuzztest/fuzztest.h"
#include "fuzztest/init_fuzztest.h"
#include "benchmark/benchmark.h"
#include "gtest/gtest.h"

import std;


TEST(MyTestSuite, OnePlustTwoIsTwoPlusOne) {
  EXPECT_EQ(1 + 2, 2 + 1);
}

void IntegerAdditionCommutes(int a, int b) {
  EXPECT_EQ(a + b, b + a);
}
FUZZ_TEST(MyTestSuite, IntegerAdditionCommutes);

std::vector<unsigned> createTestNumbers() {
  std::vector<unsigned> v;
  for (int i = 0; i < 25; ++i) v.emplace_back(i);
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(v.begin(), v.end(), g);
  return v;
}

template <class T> unsigned fibonacci(T n) {
  return n == 0 ? 0 : n == 1 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

// template <class T> T fastFibonacci(T i) {
//   if (i == 0)
//     return 0;
//   T a[2] = {1, 1};
//   while (i-- > 2)
//     a[i & 1] = a[0] + a[1];
//   return a[0];
// }

void BMfibonacci(benchmark::State& state) {
  auto numbers = createTestNumbers();
  for (auto _ : state) {
    for (auto v : numbers) benchmark::DoNotOptimize(fibonacci(v));
  }
}

BENCHMARK(BMfibonacci);

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);

  fuzztest::ParseAbslFlags(argc, argv);
  fuzztest::InitFuzzTest(&argc, &argv);

  std::println("Runnings tests.");
  auto testsResults = RUN_ALL_TESTS();

  benchmark::Initialize(&argc, argv);
  std::println("\nRunnings benchmarks.");
  auto benchmarkResults = benchmark::RunSpecifiedBenchmarks();
  benchmark::Shutdown();

  return (testsResults==0) && (benchmarkResults>0)? 0 : 1;
}
