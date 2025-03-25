// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void increase(vector<int> &counters, int counterIndex) {
  counters[counterIndex]++;
}

void maxCounter(vector<int> &counters) {
  auto maxElem = std::max_element(std::begin(counters), std::end(counters));
  std::fill(std::begin(counters), std::end(counters), *maxElem);
}

vector<int> solution(int N, vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)
  std::vector<int> counters(N, 0);

  auto &operations = A;

  for (const auto &operationVal : operations) {
    if ((operationVal >= 1) && (operationVal <= N)) {
      increase(counters, operationVal-1);
    }

    if (operationVal == N + 1) {
      maxCounter(counters);
    }
  }

  return counters;



////////// OR

// you can use includes, for example:
#include <algorithm>
#include <cstdint>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void maxCounter(vector<int> &counters) {
  auto maxElem = std::max_element(std::begin(counters), std::end(counters));
  std::fill(std::begin(counters), std::end(counters), *maxElem);
}

vector<int> solution(int N, vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)
  std::vector<int> counters(N, 0);

  auto &operations = A;

  int32_t max = 0;
  int32_t effectiveMaxValue = 0;

  for (const auto &operationVal : operations) {
    uint32_t operationValIndex = operationVal - 1;
    auto &counter = counters[operationValIndex];

    // if the current counter value is smaller than the cached maxvalue we set
    // it to it before doing the operation
    if (counter < effectiveMaxValue) {
      counter = effectiveMaxValue;
    }

    // Operation is increase
    if ((operationVal >= 1) && (operationVal <= N)) {
      counter++;
      max = std::max(counter, max);
    }

    // Operation is max but instead of setting it, we cache the max
    if (operationVal == N + 1) {
      effectiveMaxValue = max;
    }
  }

  for (auto &counter : counters) {
    if (counter < effectiveMaxValue) {
      counter = effectiveMaxValue;
    }
  }

  return counters;
}