// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    // the first n element in the series.
    uint64_t n = A.size()+1u;

    // The sum of the series of the element
    double seriesSum = (n*(1+n))/2.0;
    // Substract each element from the sum.
    for (const auto& elem : A) {
    seriesSum -= elem;
    }

    // After the substraction the value that is left is the element that was missing in the serie.
    return seriesSum;
}