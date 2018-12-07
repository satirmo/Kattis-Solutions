#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;

long long ans[maxn];
bitset<maxn> bit;
vector<long long> prime;

void Sieve() {
  bit.set();

  for (long long i = 2; i < maxn; i++) {
    if (bit[i]) {
      for (long long j = i * i; j < maxn; j += i) {
        bit[j] = false;
      }

      prime.push_back(i);
    }
  }
}

long long Phi(long long x) {
  long long ret = x;

  for (long long p : prime) {
    if (x % p == 0LL) {
      ret = (p - 1LL) * ret / p;
    }

    while (x % p == 0LL) {
      x /= p;
    }
  }

  if (x != 1LL) {
    ret = (x - 1LL) * ret / x;
  }

  return ret;
}

void GenerateSums() {
  ans[0] = 1LL;

  for (int i = 1; i < maxn; i++) {
    ans[i] = ans[i - 1] + Phi(i);
  }
}

int main() {
  int test;
  cin >> test;

  Sieve();
  GenerateSums();

  while (test--) {
    int t, n;
    cin >> t >> n;

    cout << t << " " << ans[n] << endl;
  }

  return 0;
}