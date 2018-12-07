#include <bits/stdc++.h>

using namespace std;

const int maxn = 205;

int n, k;
long long dp[maxn][maxn][maxn], a[maxn][maxn];

long long F(int r, int c, int used) {
  if (r == n) {
    return 0LL;
  }

  long long &ret = dp[r][c][used];

  if (ret != -1LL) {
    return ret;
  }

  ret = 0LL;

  if (used < k) {
    ret = a[r][c] + F(r + 1, c, used + 1);
  }

  if (k - used < n - r) {
    long long o1 = a[r][c] + a[r][c ^ 1] + F(r + 1, c, used);
    long long o2 = a[r][c] + a[r][c ^ 1] + F(r + 1, c ^ 1, used);

    ret = max(ret, max(o1, o2));
  }

  return ret;
}

int main() {
  while (cin >> n >> k, n != 0 || k != 0) {
    memset(dp, -1LL, sizeof dp);

    for (int i = 0; i < n; i++) {
      scanf("%lld %lld", &a[i][0], &a[i][1]);
    }

    long long ans = max(F(0, 0, 0), F(0, 1, 0));
    cout << ans << endl;
  }

  return 0;
}