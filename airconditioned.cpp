#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int maxn = 105;
const int inf = 1 << 30;

ii a[maxn];

int main() {
  int n;

  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);

    int ans = 0;
    int rmin = inf;

    for (int i = 0; i < n; i++) {
      if (a[i].first > rmin) {
        rmin = inf;
      }

      if (rmin == inf) {
        ans++;
      }

      rmin = min(rmin, a[i].second);
    }

    cout << ans << endl;

    break;
  }

  return 0;
}