#include "fuzztest/fuzztest.h"
#include "./fuzztest/init_fuzztest.h"
#include "gtest/gtest.h"

#include <vector>

TEST(MyTestSuite, OnePlustTwoIsTwoPlusOne) {
  EXPECT_EQ(1 + 2, 2 + 1);
}

void IntegerAdditionCommutes(int a, int b) {
  EXPECT_EQ(a + b, b + a);
}
FUZZ_TEST(MyTestSuite, IntegerAdditionCommutes);


std::vector<int> v;

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);

  //auto i = v[10];

  fuzztest::ParseAbslFlags(argc, argv);
  fuzztest::InitFuzzTest(&argc, &argv);
  return RUN_ALL_TESTS();
}
