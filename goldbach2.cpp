#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> ii;

const int maxn = 32005;

bitset<maxn> bit;
vector<long long> prime;
vector<ii> ans;

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

void GeneratePairs(int n) {
  ans.clear();

  for (long long p : prime) {
    if (p > n - p) {
      break;
    }

    if (binary_search(prime.begin(), prime.end(), n - p)) {
      ans.push_back(ii(p, n - p));
    }
  }
}

int main() {
  int test;
  cin >> test;

  Sieve();

  for (int t = 0; t < test; t++) {
    if (t) {
      cout << endl;
    }

    int n;
    cin >> n;
    GeneratePairs(n);

    printf("%d has %d representation(s)\n", n, (int)ans.size());
    for (auto p : ans) {
      printf("%lld+%lld\n", p.first, p.second);
    }
  }
  return 0;
}