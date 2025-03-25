// you can use includes, for example:
#include <algorithm>
#include <array>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
// explaination https://www.youtube.com/watch?v=4SyckIAmYXk

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
  // write your code in C++14 (g++ 6.2.0)
  const int A_VAL = 1;
  const int C_VAL = 2;
  const int G_VAL = 3;
  const int T_VAL = 4;
  const int NucleotidesCount = 4;

  const auto &dnaSequence = S;
  const int dnaSequenceCount = dnaSequence.size();

  auto dna = std::vector<std::array<int, NucleotidesCount>>(dnaSequenceCount,
                                                            {0, 0, 0, 0});
  int aCnt = 0;
  int cCnt = 0;
  int gCnt = 0;
  int tCnt = 0;

  for (int i = 0; i < dnaSequenceCount; i++) {
    switch (dnaSequence[i]) {
    case 'A': {
      aCnt++;
    } break;
    case 'C': {
      cCnt++;
    } break;
    case 'G': {
      gCnt++;
    } break;
    case 'T': {
      tCnt++;
    } break;
    }

    dna[i][0] = aCnt;
    dna[i][1] = cCnt;
    dna[i][2] = gCnt;
    dna[i][3] = tCnt;

    // std::cout << "i " << i << "    " << dna[i][0] << " " << dna[i][1] << " "
    //           << dna[i][2] << " " << dna[i][3] << "\n";
  }

  const auto &queryStartIndicies = P;
  const auto &queryEndIndicies = Q;
  const int queriesCount = queryStartIndicies.size();

  auto results = std::vector<int>();
  results.reserve(queriesCount);

  for (int K = 0; K < queriesCount; K++) {

    const auto &startPos = queryStartIndicies[K];
    const auto &endPos = queryEndIndicies[K];
    const auto &startSequence = dna[startPos];
    const auto &endSequence = dna[endPos];

    if (startPos == endPos) {
      if (dnaSequence[startPos] == 'A') {
        results.push_back(A_VAL);
      } else if (dnaSequence[startPos] == 'C') {
        results.push_back(C_VAL);
      } else if (dnaSequence[startPos] == 'G') {
        results.push_back(G_VAL);
      } else if (dnaSequence[startPos] == 'T') {
        results.push_back(T_VAL);
      }

      //   switch (dnaSequence[startPos]) {
      //   case 'A': {
      //     results.push_back(A_VAL);
      //   } break;
      //   case 'C': {
      //     results.push_back(C_VAL);
      //   } break;
      //   case 'G': {
      //     results.push_back(G_VAL);
      //   } break;
      //   case 'T': {
      //     results.push_back(T_VAL);
      //   } break;
      //   }

    } else {

      if ((startSequence[0] < endSequence[0]) ||
          (dnaSequence[startPos] == 'A')) {
        results.push_back(A_VAL);
      } else if ((startSequence[1] < endSequence[1]) ||
                 (dnaSequence[startPos] == 'C')) {
        results.push_back(C_VAL);
      } else if ((startSequence[2] < endSequence[2]) ||
                 (dnaSequence[startPos] == 'G')) {
        results.push_back(G_VAL);
      } else if ((startSequence[3] < endSequence[3]) ||
                 (dnaSequence[startPos] == 'T')) {
        results.push_back(T_VAL);
      }
    }
  }

  return results;
}


//Other solution
// public static int[] genome(String S, int[] P, int[] Q) {
//    int len = S.length();
//    int[][] arr = new int[len][4];
//    int[] result = new int[P.length];
   
//    for(int i = 0; i < len; i++){
//      char c = S.charAt(i);
//      if(c == 'A') arr[i][0] = 1;
//      if(c == 'C') arr[i][1] = 1;
//      if(c == 'G') arr[i][2] = 1;
//      if(c == 'T') arr[i][3] = 1;
//    }
//    // compute prefixes
//    for(int i = 1; i < len; i++){
//      for(int j = 0; j < 4; j++){
//        arr[i][j] += arr[i-1][j];
//      }
//    }	
   
//    for(int i = 0; i < P.length; i++){
//      int x = P[i];
//      int y = Q[i];
     
//      for(int a = 0; a < 4; a++){
//        int sub = 0;
//        if(x-1 >= 0) sub = arr[x-1][a];
//        if(arr[y][a] - sub > 0){
//          result[i] = a+1;
//          break;
//        }
//      }
     
//    }
//    return result;
//  }