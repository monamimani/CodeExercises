// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)

  if (A.empty()) {
    return 0;
  }

  const int length = A.size();
  // The starting positions of the disks clamped between 0 and A.size()
  std::vector<int> startDiskPos(length, 0);

  // The number of circle that start at that index
  std::vector<int> counterStartPos(length, 0);

  // The end positions of the disks clamped between 0 and A.size()
  std::vector<int> endDiskPos(length, 0);

  // The number of circle that end at that index
  std::vector<int> counterEndPos(length, 0);

  for (int i = 0; i < length; i++) {
    const auto &radius = A[i];
    const auto startDisk = i - radius;
    const auto endDisk = i + radius;
    auto posStart = std::max(0, startDisk);
    startDiskPos[i] = posStart;
    auto posEnd = std::min(length - 1, endDisk);
    endDiskPos[i] = posEnd;

    std::cout << posStart;
    std::cout << " ";
    std::cout << posEnd;
    std::cout << "\n";

    counterStartPos[posStart]++;
    counterEndPos[posEnd]++;
  }

  std::cout << "startDiskPos\n";
  for (int i = 0; i < length; i++) {
    std::cout << startDiskPos[i];
  }
  std::cout << "\n";

  std::cout << "endDiskPos\n";
  for (int i = 0; i < length; i++) {
    std::cout << endDiskPos[i];
  }
  std::cout << "\n";

  std::cout << "counterStartPos\n";
  for (int i = 0; i < length; i++) {
    std::cout << counterStartPos[i];
  }
  std::cout << "\n";

  std::cout << "counterEndPos\n";
  for (int i = 0; i < length; i++) {
    std::cout << counterEndPos[i];
  }
  std::cout << "\n";

  std::vector<int> cumulativecCntStartPos(length, 0);
  std::vector<int> cumulativeCntEndPos(length, 0);
  cumulativecCntStartPos[0] = counterStartPos[0];
  cumulativeCntEndPos[0] = counterEndPos[0];

  for (int i = 1; i < length; i++) {
    cumulativecCntStartPos[i] =
        counterStartPos[i] + cumulativecCntStartPos[i - 1];
    cumulativeCntEndPos[i] = counterEndPos[i] + cumulativeCntEndPos[i - 1];
  }

  std::cout << "cumulativecCntStartPos\n";
  for (int i = 0; i < length; i++) {
    std::cout << cumulativecCntStartPos[i];
  }
  std::cout << "\n";

  std::cout << "cumulativeCntEndPos\n";
  for (int i = 0; i < length; i++) {
    std::cout << cumulativeCntEndPos[i];
  }
  std::cout << "\n";
  std::cout << "\n";

  int nbIntersections = 0;
  for (int i = 1; i < length; i++) {
    int intersecDiskAtPosI = (cumulativecCntStartPos[i] -
                              cumulativeCntEndPos[i - 1] - counterStartPos[i]);
    int selfIntersecDiskAtPosI =
        counterStartPos[i] * (counterStartPos[i] - 1) / 2.0;

    std::cout << intersecDiskAtPosI << "\n";
    std::cout << selfIntersecDiskAtPosI << "\n";
    nbIntersections +=
        intersecDiskAtPosI * counterStartPos[i] + selfIntersecDiskAtPosI;

    std::cout << nbIntersections << "\n";
    std::cout << "\n";
  }

  if (nbIntersections > 1e7) {
    return -1;
  }

  return nbIntersections;
}
