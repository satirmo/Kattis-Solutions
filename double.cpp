#include <bits/stdc++.h>

using namespace std;

const int maxn = 805;

int n, k;
int contains[maxn];
int before[maxn];
bool visit[maxn];

int H(int x) {
  int group = x % k;

  int pos = contains[group] - (x / k);
  int ret = before[group] + pos + group;

  return ret;
}

long long F(int x, int s) {
  if (x == s) {
    return 0;
  }

  visit[x] = true;

  int nx = H(x);
  return 1 + F(nx, s);
}

int main() {
  while (cin >> n >> k, n != 0) {
    for (int i = 0; i < maxn; i++) {
      visit[i] = false;
      contains[i] = (n - 1 - i) / k;

      if (i > 0) {
        before[i] = before[i - 1] + contains[i - 1];
      }
    }

    long long ans = 1LL;

    for (int i = 0; i < n; i++) {
      if (visit[i]) {
        continue;
      }

      // printF( "%4d", i );

      long long t = 1 + F(H(i), i);

      long long g = __gcd(t, ans);

      t /= g;
      ans *= t;
    }

    cout << ans << endl;
  }

  return 0;
}