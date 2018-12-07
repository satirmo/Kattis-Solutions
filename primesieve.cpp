#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000005;

bitset<maxn> bit;

int Sieve(int n) {
  bit.set();
  bit[0] = false;
  bit[1] = false;

  int ret = 0;

  for (long long i = 2; i <= n; i++) {
    if (bit[i]) {
      for (long long j = i * i; j <= n; j += i) {
        bit[j] = false;
      }

      ret++;
    }
  }

  return ret;
}

int main() {
  int n, q;
  cin >> n >> q;

  int cnt = Sieve(n);

  cout << cnt << endl;

  while (q--) {
    int x;
    scanf("%d", &x);

    cout << (bit[x] ? 1 : 0) << endl;
  }

  return 0;
}