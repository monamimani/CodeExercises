// you can use includes, for example:
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    double distance = Y-X;
    double jmpDist = D;

    int nbJmps = std::ceil(distance/jmpDist);
    return nbJmps;
}