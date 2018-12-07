#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

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

long long Exp(long long b, int p) {
  long long ret = 1LL;

  while (p--) {
    ret *= b;
  }

  return ret;
}

long long FindSum(long long x) {
  long long ret = 1LL;

  for (long long p : prime) {
    long long t = x;
    long long cnt = 0;

    while (t % p == 0LL) {
      cnt++;
      t /= p;
    }

    if (cnt == 0LL) {
      continue;
    }

    long long num = Exp(p, cnt + 1) - 1LL;
    long long den = p - 1LL;

    ret *= num;
    ret /= den;
  }

  return ret - x;
}

int main() {
  Sieve();

  long long n;

  while (cin >> n) {
    long long sum = FindSum(n);

    if (sum == n) {
      printf("%lld perfect\n", n);
    }

    else if (abs(sum - n) <= 2) {
      printf("%lld almost perfect\n", n);
    }

    else {
      printf("%lld not perfect\n", n);
    }
  }

  return 0;
}