#include <bits/stdc++.h>

using namespace std;

const int maxr = 105;

char mat[maxr][maxr];

int main() {
  int test;
  cin >> test;
  cin.ignore();

  while (test--) {
    string s;
    cin >> s;

    int r = sqrt(s.size() + 1);
    int m = r * r;

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < r; j++) {
        int k = i * r + j;

        mat[i][j] = (k < s.size()) ? s[k] : '*';
      }
    }

    string ans = "";

    for (int i = 0; i < r; i++) {
      for (int j = r - 1; j >= 0; j--) {
        if (mat[j][i] != '*') {
          ans += mat[j][i];
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}