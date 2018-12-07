#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
const int mov[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int a[maxn][maxn];
int b[maxn][maxn];
string s[maxn];

int main() {
  int n, m;
  cin >> n >> m;
  cin.ignore();

  for (int i = 0; i < n; i++) {
    cin >> s[i];

    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'T') {
        a[i + 1][j + 1] = -1;
      }
    }
  }

  int maxx = 0;

  for (int it = 1; it < maxn; it++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == -1) {
          bool foundIt = false;

          for (int k = 0; k < 4; k++) {
            int x = i + mov[k][0];
            int y = j + mov[k][1];

            if (a[x][y] == it - 1) {
              foundIt = true;
            }
          }

          if (foundIt) {
            b[i][j] = it;
            maxx = it;
          }
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (b[i][j] == it) {
          a[i][j] = b[i][j];
          b[i][j] = -1;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      string pad = ".";

      if (maxx >= 10 && a[i][j] < 10) {
        pad += ".";
      }

      if (a[i][j] == 0) {
        pad += ".";
      }

      else {
        pad += to_string(a[i][j]);
      }
      printf("%s", pad.c_str());
    }
    puts("");
  }

  return 0;
}