#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

bitset<3 * maxn> bit;

int main() {
  int n;
  while (cin >> n) {
    bit.reset();
    bit[0] = true;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      for (int j = 2 * maxn; j >= x; j--) {
        if (bit[j - x]) {
          bit[j] = true;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < 2 * maxn; i++) {
      if (bit[i] && abs(i - 1000) <= abs(ans - 1000)) {
        ans = i;
      }
    }

    cout << ans << endl;
  }

  return 0;
}