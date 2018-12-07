#include <bits/stdc++.h>

using namespace std;

int main() {
  int x, n;
  cin >> x >> n;

  int ans = x;

  while (n--) {
    int p;
    cin >> p;

    ans += x - p;
  }

  cout << ans << endl;

  return 0;
}