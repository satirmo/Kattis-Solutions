#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

string s;
int dp[maxn][maxn];

int F(int x, int y) {
  if (x >= y) {
    return 0;
  }

  int &ret = dp[x][y];

  if (ret != -1) {
    return ret;
  }

  ret = 1 << 30;

  if (s[x] == s[y]) {
    ret = min(ret, F(x + 1, y - 1));
  }

  if (y == s.size() - 1) {
    ret = min(ret, 1 + F(x + 1, y));
  }

  ret = min(ret, 1 + F(x + 1, y - 1));

  return ret;
}

int main() {
  while (cin >> s) {
    memset(dp, -1, sizeof dp);

    int ans = F(0, s.size() - 1);
    cout << ans << endl;
  }
  return 0;
}