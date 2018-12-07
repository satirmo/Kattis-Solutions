#include <bits/stdc++.h>

using namespace std;

int main() {
  string x, y;
  cin >> x >> y;

  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());

  string ans = max(x, y);
  cout << ans << endl;

  return 0;
}