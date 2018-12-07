#include <bits/stdc++.h>

using namespace std;

map<char, int> submissions;

int main() {
  string line;

  int solved = 0;
  int totalTime = 0;

  while (true) {
    getline(cin, line);
    stringstream ss(line);

    int t;
    ss >> t;

    if (t == -1) {
      break;
    }

    ss.ignore();

    char problem;
    string verdict;

    ss >> problem >> verdict;

    if (submissions.count(problem) == 0) {
      submissions[problem] = 0;
    }

    else {
      submissions[problem]++;
    }

    if (verdict == "right") {
      solved++;
      totalTime += t + 20 * submissions[problem];
    }
  }

  printf("%d %d\n", solved, totalTime);

  return 0;
}