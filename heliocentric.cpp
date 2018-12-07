#include <bits/stdc++.h>

using namespace std;

int main() {
  int e, m;
  for (int t = 1; cin >> e >> m; t++) {
    int ans = 0;

    while ((e + ans) % 365 != (m + ans) % 687) {
      ans++;
    }

    printf("Case %d: %d\n", t, ans);
  }

  return 0;
}