#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;

  while (cin >> n) {
    if (n <= 2) {
      cout << n << endl;
      continue;
    }

    int ans = n + (n - 2);
    cout << ans << endl;
  }

  return 0;
}