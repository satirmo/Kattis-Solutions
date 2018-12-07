#include <bits/stdc++.h>

using namespace std;

const int maxn = 25;

int G[maxn][maxn];

bool IsTriangle(int a, int b, int c) {
  if (a == b || a == c || b == c) {
    return false;
  }

  return G[a][b] && G[b][c] && G[c][a];
}

int main() {
  int n;

  while (cin >> n, n != -1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> G[i][j];
      }
    }

    bool flag = false;

    for (int i = 0; i < n; i++) {
      bool isWeak = true;

      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (IsTriangle(i, j, k)) {
            isWeak = false;
          }
        }
      }

      if (isWeak) {
        if (flag) {
          printf(" ");
        }

        flag = true;
        printf("%d", i);
      }
    }

    puts("");
  }

  return 0;
}