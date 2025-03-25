// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    bool isThereLeaf[X] {};

    for (int i = 0; i < A.size(); i++) {
        auto position = A[i] - 1;
        if (!isThereLeaf[position]) {
            isThereLeaf[position] = true;

            if (--X == 0) {
                return i;
            }
        }

    }

    return -1;
}