#include <bits/stdc++.h>

using namespace std;

const int maxs = 205;
const int inf = 1 << 30;

int n, A, B, C;
int dp[maxs][maxs][maxs];

int F(int m, int b, int c) {
  if (m == 0) {
    return 0;
  }

  int &ret = dp[m][b][c];

  if (ret != -1) {
    return ret;
  }

  ret = inf;
  int a = A - (8 * (n - m) - 5 * (B - b) - 10 * (C - c));

  if (c > 0) {
    ret = min(ret, 1 + F(m - 1, b, c - 1));
  }

  if (c > 0 && a > 2) {
    ret = min(ret, 4 + F(m - 1, b + 1, c - 1));
  }

  if (b > 1) {
    ret = min(ret, 2 + F(m - 1, b - 2, c));
  }

  if (b > 0 && a > 2) {
    ret = min(ret, 4 + F(m - 1, b - 1, c));
  }

  if (a > 7) {
    ret = min(ret, 8 + F(m - 1, b, c));
  }

  return ret;
}

int main() {
  int test;
  cin >> test;

  memset(dp, -1, sizeof dp);

  while (test--) {
    cin >> n >> A >> B >> C;

    int ans = F(n, B, C);
    cout << ans << endl;
  }

  return 0;
}