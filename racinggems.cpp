#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> ll;

const int maxn = 100005;

ll a[maxn];
int f[maxn];
long long b[maxn];

int lis(int n, long long r) {
  int k = 0;

  for (int i = 0; i < n; i++) {
    f[i] = upper_bound(b, b + k, a[i].second) - b;

    k = max(k, f[i] + 1);
    b[f[i]] = a[i].second;
  }

  return k;
}

int main() {
  int n;
  long long r, w, h;

  cin >> n >> r >> w >> h;

  for (int i = 0; i < n; i++) {
    long long x, y;
    scanf("%lld %lld\n", &x, &y);

    long long nx = y + x * r;
    long long ny = y - x * r;

    a[i].first = nx;
    a[i].second = ny;
  }

  sort(a, a + n);

  int ans = lis(n, r);
  cout << ans << endl;

  return 0;
}