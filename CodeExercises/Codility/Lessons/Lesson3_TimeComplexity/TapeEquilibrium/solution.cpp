// you can use includes, for example:
#include <cmath>
#include <cstdint>
#include <limits>
#include <sys/types.h>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)
  std::vector<int64_t> sums;
  size_t N = A.size();
  sums.reserve(N);

  int64_t sum = 0;

  for (const auto &elem : A) {
    sum += elem;
    sums.push_back(sum);
  }

  int64_t minDiff = std::numeric_limits<int64_t>::max();
  
  for (size_t i = 0; i < (N - 1); i++) {
    int64_t diff = std::abs(2 * sums[i] - sum);
    minDiff = std::min(minDiff, diff);
  }

  return minDiff;
}