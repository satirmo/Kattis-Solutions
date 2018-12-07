#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

string m[maxn];

int main() {
  int r, c, zr, zc;
  cin >> r >> c >> zr >> zc;
  cin.ignore();

  for (int i = 0; i < r; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < c; j++) {
      char v = s[j];

      for (int k = 0; k < zr; k++) {
        m[zr * i + k] += string(zc, v);
      }
    }
  }

  for (int i = 0; i < zr * r; i++) {
    cout << m[i] << endl;
  }

  return 0;
}