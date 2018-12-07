#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;

set<int> a[maxn];

int main() {
  int n;
  cin >> n;

  int maxh = 0;

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);

    a[x].insert(i);
    maxh = max(maxh, x);
  }

  int ans = 0;

  while (maxh > 0) {
    int x = -1;
    int height = maxh;

    while (true) {
      auto itnx = a[height].upper_bound(x);

      if (itnx == a[height].end()) {
        break;
      }

      int nx = *itnx;
      a[height].erase(itnx);

      x = nx;
      height--;
    }

    ans++;

    while (maxh > 0 && a[maxh].size() == 0) {
      maxh--;
    }
  }

  cout << ans << endl;

  return 0;
}