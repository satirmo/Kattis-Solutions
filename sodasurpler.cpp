#include <bits/stdc++.h>

using namespace std;

int main() {
  int e, f, c;
  cin >> e >> f >> c;

  int ans = 0;
  int empty = e + f;

  while (empty >= c) {
    int full = empty / c;
    empty %= c;

    ans += full;
    empty += full;
  }

  cout << ans << endl;

  return 0;
}