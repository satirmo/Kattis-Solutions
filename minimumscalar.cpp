#include <bits/stdc++.h>

using namespace std;

const int maxn = 805;

long long a[maxn], b[maxn];

long long F(int n) {
  sort(a, a + n);
  sort(b, b + n);

  long long ret = 0LL;

  for (int i = 0; i < n; i++) {
    ret += a[i] * b[n - 1 - i];
  }

  return ret;
}

int main() {
  int test;
  cin >> test;

  for (int t = 1; t <= test; t++) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
    }

    for (int i = 0; i < n; i++) {
      scanf("%lld", &b[i]);
    }

    long long ans = F(n);
    printf("Case #%d: %lld\n", t, ans);
  }

  return 0;
}