#include <bits/stdc++.h>

using namespace std;

const int maxn = 55;

long long dp[maxn];

long long F(int x) {
  if (x & 1) {
    return 0LL;
  }

  if (x == 0) {
    return 1;
  }

  long long &ret = dp[x];

  if (ret != -1LL) {
    return ret;
  }

  ret = F(x - 2);

  for (int i = 2; i <= x; i += 2) {
    ret += 2LL * F(x - i);
  }

  return ret;
}

int main() {
  int n;
  while (cin >> n, n != -1) {
    memset(dp, -1, sizeof dp);
    cout << F(n) << endl;
  }

  return 0;
}