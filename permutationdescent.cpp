#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
const int mod = 1001113;

int dp[maxn][maxn];

int countDescents(int n, int v) {
  memset(dp, 0, sizeof dp);

  for (int i = 0; i < maxn; i++) {
    dp[i][0] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= v; j++) {
      int add = (i - j) * dp[i - 1][j - 1];
      int stay = (j + 1) * dp[i - 1][j];

      dp[i][j] = (add + stay) % mod;
    }
  }

  return dp[n][v];
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int t, n, v;
    cin >> t >> n >> v;

    int ans = countDescents(n, v);
    printf("%d %d\n", t, ans);
  }

  return 0;
}