#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;

vector<int> powers;
long long dp[maxn][15];

long long F(int n, int m) {
  memset(dp, 0, sizeof dp);
  powers.clear();

  dp[0][0] = 1;
  powers.push_back(1);

  while (m * powers.back() <= n) {
    dp[0][powers.size()] = 0;
    powers.push_back(m * powers.back());
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < powers.size(); j++) {
      for (int k = j; k < powers.size(); k++) {
        if (i + powers[k] <= n) {
          dp[i + powers[k]][k] += dp[i][j];
        }
      }
    }
  }

  long long ret = 0LL;

  for (int i = 0; i < powers.size(); i++) {
    ret += dp[n][i];
  }

  return ret;
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    long long t, m, n;
    cin >> t >> m >> n;

    long long ans = F(n, m);

    printf("%lld %lld\n", t, ans);
  }

  return 0;
}