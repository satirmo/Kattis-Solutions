#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> ll;

ll FindSummands(long long n) {
  for (long long i = 2; true; i++) {
    long long sum = i * (i + 1LL) / 2LL;

    if (sum > n) {
      break;
    }

    if ((2LL * n) % i != 0LL) {
      continue;
    }

    long long t = ((2LL * n) / i) - i + 1LL;

    if (t % 2LL == 0) {
      long long st = t / 2LL;

      return ll(st, i);
    }
  }

  return ll(-1LL, -1LL);
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int n;
    cin >> n;

    ll ans = FindSummands(n);

    if (ans.first == -1LL) {
      puts("IMPOSSIBLE");
    }

    else {
      printf("%d", n);

      for (long long i = 0; i < ans.second; i++) {
        char op = (i == 0) ? '=' : '+';
        printf(" %c %lld", op, ans.first + i);
      }

      puts("");
    }
  }

  return 0;
}