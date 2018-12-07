#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

long long a[maxn];
long long b[maxn];
long long sum[5];

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;

    b[i % 3] += x;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      sum[(i + j) % 3] += a[i] * b[j];
    }
  }

  printf("%lld %lld %lld\n", sum[0], sum[1], sum[2]);

  return 0;
}