#include <bits/stdc++.h>

using namespace std;

typedef vector<long long> vl;

const long long mod = 1000000000LL;

vector<vl> Multiply(vector<vl> A, vector<vl> B) {
  vector<vl> C;

  C.push_back({0LL, 0LL});
  C.push_back({0LL, 0LL});

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
      }
    }
  }

  return C;
}

long long CalculateFibonacci(long long p) {
  if (p == 1LL) {
    return 1LL;
  }

  if (p == 2LL) {
    return 1LL;
  }

  p -= 2;

  vector<vl> base, ret;

  base.push_back({1LL, 1LL});
  base.push_back({1LL, 0LL});

  ret.push_back({1LL, 0LL});
  ret.push_back({0LL, 1LL});

  while (p != 0LL) {
    if (p % 2 == 1LL) {
      ret = Multiply(ret, base);
    }

    base = Multiply(base, base);
    p >>= 1;
  }

  return (ret[0][0] + ret[0][1]) % mod;
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    long long t, y;
    cin >> t >> y;

    long long ans = CalculateFibonacci(y);
    printf("%lld %lld\n", t, ans);
  }

  return 0;
}