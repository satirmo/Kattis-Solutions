#include <bits/stdc++.h>

using namespace std;

const int maxn = 1 << 15;

int a[maxn];
int f[maxn];
int dp[maxn];
bitset<maxn> bit;
vector<int> primes;

void Sieve() {
  bit.set();

  for (int i = 2; i < maxn; i++) {
    if (bit[i]) {
      primes.push_back(i);

      for (int j = i * i; j < maxn; j += i) {
        bit[j] = false;
      }
    }
  }
}

int CountDistinctFactors(int x) {
  int ret = 0;

  for (int p : primes) {
    if (p * p > x) {
      break;
    }

    if (x % p == 0) {
      ret++;

      while (x % p == 0) {
        x /= p;
      }
    }
  }

  if (x > 1) {
    ret++;
  }

  return ret;
}

void printMask(int msk, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", (msk >> i) & 1);
  }
  puts("");
}

int main() {
  Sieve();

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int upto = 1 << n;

  for (int msk = 0; msk < upto; msk++) {
    int sum = 0LL;

    for (int i = 0; i < n; i++) {
      if ((msk >> i) & 1) {
        sum += a[i];
      }
    }

    f[msk] = CountDistinctFactors(sum);
  }

  for (int msk = 0; msk < upto; msk++) {
    for (int msk1 = msk; msk1 > 0; msk1 = (msk1 - 1) & msk) {
      int msk2 = (msk & (~msk1));

      dp[msk] = max(dp[msk], f[msk1] + dp[msk2]);
    }
  }

  int idx = upto - 1;
  cout << dp[idx] << endl;

  return 0;
}