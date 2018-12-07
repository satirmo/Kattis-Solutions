#include <bits/stdc++.h>

using namespace std;

const int maxn = 46340;

vector<long long> prime;
bitset<maxn> bit;

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

bool IsPrime(long long x) {
  for (long long p : prime) {
    if (p >= x) {
      break;
    }

    if (x % p == 0LL) {
      return false;
    }
  }

  return true;
}

string NextPrime(long long x) {
  long long t = x << 1;

  while (!IsPrime(t)) {
    t++;
  }

  return to_string(t);
}

int main() {
  Sieve();

  long long n;

  while (scanf("%lld", &n), n != 0LL) {
    string sidenote = "";

    if (!IsPrime(n)) {
      sidenote = " (" + to_string(n) + " is not prime)";
    }

    string ans = NextPrime(n) + sidenote;
    printf("%s\n", ans.c_str());
  }

  return 0;
}