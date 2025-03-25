// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)
  auto N = A.size();

  bool isPresent[N]{};

  for (const uint32_t &elem : A) {
    if (elem > N) {
      // the value elem is bigger than the number of elem it therefore can't be
      // a permutation
      return false;
    } else if (isPresent[elem - 1]) {
      // it is the second time we would set it to true therefore one number will
      // be missing in the end
      return false;
    } else {
      // Set the element as present
      isPresent[elem - 1] = true;
    }
  }

  // if we pass here each element where there only once and in there range [1,N]
  return true;
}