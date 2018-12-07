#include <bits/stdc++.h>

using namespace std;

const int maxn = 35;
const int inf = 1 << 30;

int main() {
  int n;

  for (int t = 1; cin >> n; t++) {
    int minn = inf;
    int maxx = -inf;

    while (n--) {
      int x;
      cin >> x;

      minn = min(minn, x);
      maxx = max(maxx, x);
    }

    printf("Case %d: %d %d %d\n", t, minn, maxx, maxx - minn);
  }

  return 0;
}