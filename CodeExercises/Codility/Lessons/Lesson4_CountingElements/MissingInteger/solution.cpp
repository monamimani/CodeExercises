// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)
  std::sort(std::begin(A), std::end(A));

  if (A.back() <= 0) {
    return 1;
  }

  if (A[0] > 1) {
    return 1;
  }

  for (uint32_t i = 0; i < A.size() - 1; i++) {
    if (A[i] <= 0) {
      if (A[i + 1] > 1) {
        return 1;
      }
      continue;
    }

    if ((A[i + 1] - A[i]) > 1) {
      return A[i] + 1;
    }
  }

  return A.back() + 1;
}