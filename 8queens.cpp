#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

string a[10];
vector<ii> v;

int main() {
  for (int i = 0; i < 8; i++) {
    cin >> a[i];
  }

  bool flag = false;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (a[i][j] == '*') {
        for (ii t : v) {
          int x = t.first;
          int y = t.second;

          if (x == i || y == j) {
            flag = true;
          }

          if (abs(x - i) == abs(y - j)) {
            flag = true;
          }
        }

        v.push_back(ii(i, j));
      }
    }
  }

  cout << ((!flag && v.size() == 8) ? "valid" : "invalid") << endl;
  return 0;
}