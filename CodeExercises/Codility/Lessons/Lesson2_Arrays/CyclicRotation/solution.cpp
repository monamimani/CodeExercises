// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
  // write your code in C++14 (g++ 6.2.0)

  //   if ((A.size() == 0) || (A.size() == 1) || (K == 0) ||
  //       static_cast<size_t>(K) % A.size() == 0) {
  //     return A;
  //   }

  //   if (A.size() == 2) {
  //     if (K % 2 == 0) {
  //       return A;
  //     } else {
  //       std::reverse(std::begin(A), std::end(A));
  //       return A;
  //     }
  //   }

  //   if (static_cast<size_t>(K) == (A.size() - 1)) {
  //     std::reverse(std::begin(A), std::end(A));
  //     return A;
  //   }

  if ((A.size() == 0) || (K == 0)) {
    return A;
  }

  size_t rotateSteps = K;
  if (rotateSteps > A.size()) {
    rotateSteps = K % A.size();
  }

  //   std::reverse(std::begin(A), std::end(A));
  //   std::rotate(std::begin(A), std::begin(A) + (A.size() - rotateSteps + 1),
  //               std::end(A));
  //   std::reverse(std::begin(A), std::end(A));

  std::rotate(std::rbegin(A), std::rbegin(A) + rotateSteps, std::rend(A));

  return A;
}