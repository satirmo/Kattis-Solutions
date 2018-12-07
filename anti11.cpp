#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;
const int mod = 1000000007;

int dp[maxn];

int main() {
  dp[0] = 1;
  dp[1] = 2;

  for (int i = 2; i < maxn; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
  }

  int test;
  cin >> test;

  while (test--) {
    int n;
    cin >> n;

    cout << dp[n] << endl;
  }

  return 0;
}