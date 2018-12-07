#include <bits/stdc++.h>

using namespace std;

const int maxn = 450;

bitset<maxn> bit;
long long f[maxn][maxn];

void Factor(int x) {
  int t = x;
  for (int i = 2; i < maxn; i++) {
    f[x][i] = f[x - 1][i];
  }

  for (int i = 2; i <= x; i++) {
    while (bit[i] && t % i == 0) {
      t /= i;
      f[x][i]++;
    }
  }
}

void Sieve() {
  bit.set();
  bit.reset(0);
  bit.reset(1);

  for (int i = 2; i < maxn; i++) {
    if (bit[i]) {
      for (int j = i * i; j < maxn; j += i) {
        bit[j] = false;
      }
    }
  }
}

long long Calc(int a, int b) {
  long long ret = 1LL;

  for (int i = 2; i <= a; i++) {
    if (bit[i] == false) {
      continue;
    }

    long long m = f[a][i];
    if (i <= b) {
      m -= f[b][i];
    }
    if (i <= a - b) {
      m -= f[a - b][i];
    }

    ret *= (m + 1);
  }

  return ret;
}

int main() {
  int a, b;

  Sieve();
  for (int i = 2; i < maxn; i++) {
    Factor(i);
  }

  while (cin >> a >> b) {
    cout << Calc(a, b) << endl;
  }
}