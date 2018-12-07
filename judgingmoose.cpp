#include <bits/stdc++.h>

using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  int m = max(x, y);

  if (m == 0) {
    puts("Not a moose");
  }

  else {
    string s = (x == y) ? "Even " : "Odd ";
    string ans = s + to_string(2 * m);

    cout << ans << endl;
  }

  return 0;
}