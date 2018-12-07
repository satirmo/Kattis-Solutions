#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;

int par[maxn];
int len[maxn];
bitset<maxn> bit;
vector<int> divisors[maxn];

void Sieve() {
  bit.set();

  for (long long i = 2; i < maxn; i++) {
    if (bit[i]) {
      for (long long j = i; j < maxn; j += i) {
        bit[j] = false;
        divisors[j].push_back(i);
      }
    }
  }
}

void Precompute() {
  len[1] = 1;

  for (int i = 2; i < maxn; i++) {
    for (int p : divisors[i]) {
      int j = i / p;

      if (len[i] < 1 + len[j]) {
        par[i] = j;
        len[i] = 1 + len[j];
      }
    }
  }
}

int main() {
  Sieve();
  Precompute();

  int n;
  cin >> n;

  int id = 1;

  for (int i = 1; i <= n; i++) {
    if (len[id] < len[i]) {
      id = i;
    }

    // printf( "len %3d = %3d\n", i, len[ i ] );
  }

  vector<int> ans;

  while (id != 1) {
    ans.push_back(id);
    id = par[id];
  }

  ans.push_back(1);

  reverse(ans.begin(), ans.end());

  cout << ans.size() << endl;

  for (int i = 0; i < ans.size(); i++) {
    if (i > 0) {
      printf(" ");
    }

    printf("%d", ans[i]);
  }

  puts("");

  return 0;
}