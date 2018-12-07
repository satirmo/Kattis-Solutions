#include <bits/stdc++.h>

using namespace std;

const int maxn = 55;
const int mov[][2] = {{1, 0}, {1, 1}, {0, -1}, {-1, 1}};

string m[maxn];

int CalculateHandshakes(int r, int s) {
  int ret = 0;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < s; j++) {
      if (m[i][j] == 'o') {
        for (int k = 0; k < 4; k++) {
          int ni = i + mov[k][0];
          int nj = j + mov[k][1];

          if (ni < 0 || ni == r || nj < 0 || nj == s) {
            continue;
          }

          if (m[ni][nj] == 'o') {
            ret++;
          }
        }
      }
    }
  }

  return ret;
}

int main() {
  int r, s;
  cin >> r >> s;
  cin.ignore();

  for (int i = 0; i < r; i++) {
    cin >> m[i];
  }

  int ans = CalculateHandshakes(r, s);

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < s; j++) {
      if (m[i][j] == '.') {
        m[i][j] = 'o';

        int t = CalculateHandshakes(r, s);
        ans = max(ans, t);

        m[i][j] = '.';
      }
    }
  }

  cout << ans << endl;

  return 0;
}