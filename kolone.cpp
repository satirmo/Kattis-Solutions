#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;

  while (cin >> n >> m) {
    cin.ignore();

    string s, t;
    cin >> s >> t;

    int tim;
    cin >> tim;

    reverse(s.begin(), s.end());
    string currentLine = s + t;

    while (tim--) {
      string nextLine = currentLine;

      for (int i = 1; i < currentLine.size(); i++) {
        int c1 = currentLine[i - 1];
        int c2 = currentLine[i];

        int set1 = (s.find(c1) != string::npos) ? 1 : 2;
        int set2 = (s.find(c2) != string::npos) ? 1 : 2;

        if (set1 == 1 && set2 == 2) {
          swap(nextLine[i - 1], nextLine[i]);
          i++;
        }
      }

      currentLine = nextLine;
    }

    cout << currentLine << endl;
  }

  return 0;
}