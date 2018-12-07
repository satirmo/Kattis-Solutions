#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> ii;

const int maxn = 1005;

long long x[maxn], y[maxn], xs[maxn], ys[maxn];

long long GetSum(long long n, long long u, long long xs, long long x) {
  return n * u * u + xs - 2LL * u * x;
}

long long GetDistance(long long n, ii point) {
  long long u = point.first;
  long long v = point.second;

  return GetSum(n, point.first, xs[n], x[n]) +
         GetSum(n, point.second, ys[n], y[n]);
}

ii GetClosestPoint(int n) {
  ii ret = ii(0, 0);

  for (int i = 0; i < maxn; i++) {
    for (int j = 0; j < maxn; j++) {
      long long current = GetDistance(n, ret);

      ii candidate = ii(i, j);
      long long potential = GetDistance(n, candidate);

      if (current > potential) {
        ret = candidate;
      }
    }
  }

  return ret;
}

int main() {
  int n;

  while (cin >> n, n != 0) {
    for (int i = 1; i <= n; i++) {
      long long u, v;
      cin >> u >> v;

      x[i] = u + x[i - 1];
      y[i] = v + y[i - 1];
      xs[i] = u * u + xs[i - 1];
      ys[i] = v * v + ys[i - 1];
    }

    ii ans = GetClosestPoint(n);
    cout << ans.first << " " << ans.second << endl;
  }

  return 0;
}