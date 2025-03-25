// you can use includes, for example:
#include <cfloat>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)
  auto size = A.size();
  double minAvg = DBL_MAX;
  int minIndex = 0;

  auto sum = 0.0;
  auto avg2 = 0.0;
  auto avg3 = 0.0;
  for (size_t i = 0; i < size - 2; i++) {

    sum = (double)(A[i] + A[i + 1]);
    avg2 = sum / 2.0;

    sum += (double)A[i + 2];
    avg3 = sum / 3.0;

    auto curMinAvg = std::min(avg2, avg3);
    if (curMinAvg < minAvg) {
      minAvg = curMinAvg;
      minIndex = i;
    }
  }

  sum = A[size - 2] + A[size - 1];
  avg2 = sum / 2.0;
  if (avg2 < minAvg) {
    minAvg = avg2;
    minIndex = size - 2;
  }

  return minIndex;
}
