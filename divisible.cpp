#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;

long long cnt[maxn];

int main() {
  int test;
  cin >> test;

  while (test--) {
    long long d, n;
    cin >> d >> n;

    long long sum = 0LL;

    cnt[0LL] = 1LL;

    for (int i = 0; i < n; i++) {
      long long t;
      scanf("%lld", &t);

      sum = (sum + t) % d;
      cnt[sum]++;

      // printf( "%3d : %10lld\n", i, sum );
    }

    long long ans = 0LL;

    for (int i = 0; i < maxn; i++) {
      long long t = cnt[i];
      ans += (t * t - t) / 2LL;

      cnt[i] = 0LL;
    }

    cout << ans << endl;
  }

  return 0;
}