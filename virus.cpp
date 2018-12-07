#include <bits/stdc++.h>

using namespace std;

int main() {
  string s, t;
  while (cin >> s >> t) {
    int m = s.size();
    int n = t.size();
    int r = min(m, n);

    int a = 0;
    while (a < r) {
      if (s[a] != t[a]) {
        break;
      }
      a++;
    }

    int b1 = m - 1, b2 = n - 1;
    while (b1 >= 0 && b2 >= 0) {
      if (s[b1] != t[b2]) {
        break;
      }
      b1--, b2--;
    }

    int ans = max(max(0, b2 - b1), b2 - a + 1);
    cout << ans << endl;
  }

  return 0;
}