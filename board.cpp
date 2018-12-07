#include <bits/stdc++.h>

using namespace std;

const int maxn = 35;

string board[maxn];

bool Check(int x, int y) {
  char c = '?';

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      char bxy = board[x + i][y + j];

      if (bxy == '?') {
        continue;
      }

      if (bxy == 'W') {
        return false;
      }

      if (c != '?' && c != bxy) {
        return false;
      }

      c = bxy;
    }
  }

  return true;
}

void Update(int x, int y) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[x + i][y + j] = '?';
    }
  }
}

int main() {
  int n, m;

  while (cin >> n >> m) {
    cin.ignore();

    for (int i = 0; i < n; i++) {
      cin >> board[i];
    }

    int iterations = n * m;
    n -= 2;
    m -= 2;

    while (iterations--) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (Check(i, j)) {
            Update(i, j);
          }
        }
      }
    }

    n += 2;
    m += 2;

    bool ans = true;

    for (int i = 0; i < n; i++) {
      for (char c : board[i]) {
        if (c == 'R' || c == 'B' || c == 'G') {
          ans = false;
        }
      }
    }

    cout << (ans ? "YES" : "NO") << endl;
  }

  return 0;
}