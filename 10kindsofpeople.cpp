#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;
const int mov[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

string m[maxn];
int par[maxn * maxn];

int FindSet(int x) {
  while (x != par[x]) {
    int &p = par[x];

    p = par[p];
    x = par[p];
  }

  return x;
}

void Unite(int x, int y) {
  int sx = FindSet(x);
  int sy = FindSet(y);

  par[sx] = sy;
}

int GetId(int x, int y, int c) { return x * c + y; }

void Preprocess(int r, int c) {
  for (int i = 0; i < maxn; i++) {
    for (int j = 0; j < maxn; j++) {
      int ij = GetId(i, j, c);
      par[ij] = ij;
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      for (int k = 0; k < 4; k++) {
        int x = i + mov[k][0];
        int y = j + mov[k][1];

        if (x < 0 || x == r || y < 0 || y == c) {
          continue;
        }

        if (m[i][j] == m[x][y]) {
          int ij = GetId(i, j, c);
          int xy = GetId(x, y, c);

          Unite(ij, xy);
        }
      }
    }
  }
}

string Query(int a, int b, int x, int y, int c) {
  int ab = GetId(a, b, c);
  int xy = GetId(x, y, c);

  int sab = FindSet(ab);
  int sxy = FindSet(xy);

  if (sab != sxy) {
    return "neither";
  }

  string ret = (m[a][b] == '0') ? "binary" : "decimal";
  return ret;
}

int main() {
  int r, c;
  cin >> r >> c;
  cin.ignore();

  for (int i = 0; i < r; i++) {
    cin >> m[i];
  }

  Preprocess(r, c);

  int q;
  cin >> q;

  while (q--) {
    int a, b, p, q;
    cin >> a >> b >> p >> q;

    string result = Query(a - 1, b - 1, p - 1, q - 1, c);
    cout << result << endl;
  }

  return 0;
}