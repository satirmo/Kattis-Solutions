#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  if (b < a) {
    b += 360;
  }

  int ans = b - a;

  if (ans > 180) {
    ans = ans - 360;
  }

  cout << ans << endl;

  return 0;
}