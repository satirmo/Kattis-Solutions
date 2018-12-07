#include <bits/stdc++.h>

using namespace std;

const int maxr = 50005;

string a[maxr];

int main() {
  int r, c;
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    cin >> a[i];
  }

  a[r] = string(maxr, '#');

  for (int j = 0; j < c; j++) {
    int cnt = 0;

    for (int i = 0; i <= r; i++) {
      if (a[i][j] == 'a') {
        a[i][j] = '.';
        cnt++;
      }

      if (a[i][j] == '#') {
        while (cnt > 0) {
          a[i - cnt][j] = 'a';
          cnt--;
        }
      }
    }
  }

  for (int i = 0; i < r; i++) {
    cout << a[i] << endl;
  }

  return 0;
}