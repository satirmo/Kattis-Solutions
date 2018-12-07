#include <bits/stdc++.h>

using namespace std;

const int maxn = 35;

long long dp[maxn];

int main() {
  int test;
  cin >> test;

  while (test--) {
    int t, n, m, k;
    cin >> t >> n >> m >> k;

    memset(dp, 0, sizeof dp);
    dp[0] = 1LL;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        if (j % k == m) {
          continue;
        }

        dp[i] += dp[i - j];
      }
    }

    printf("%d %lld\n", t, dp[n]);
  }

  return 0;
}