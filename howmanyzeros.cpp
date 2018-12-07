#include <bits/stdc++.h>

using namespace std;

long long F(long long x) {
  if (x == -1LL) {
    return 0LL;
  }

  long long ret = 0LL;

  long long mult = 10LL;
  string num = to_string(x);

  // printf( "processing x = %10lld\n", x );

  /* count zeroes in middle digits */
  for (int i = num.size() - 2; i > 0; i--) {
    string sl = num.substr(0, i);
    long long l = stoll(sl);

    string sr = num.substr(i + 1);
    long long r = stoll(sr);

    long long add = 0LL;

    /* RHS is irrelevant if we are processing a zero */
    if (num[i] != '0') {
      add += mult * l;
    }

    /* RHS must be accounted for if we are processing a zero */
    else {
      add += mult * (l - 1LL) + r + 1LL;
    }

    ret += add;
    mult *= 10LL;

    // printf( "\tchecking %10s %10s : will add %10lld\n", sl.c_str(),
    // sr.c_str(), add );
  }

  /* right-most digit contributes */
  ret += 1 + (x / 10LL);
  // printf( "\tright digit : will add %10lld\n", 1 + ( x / 10LL ) );

  /* left-most digit contributes no zeroes */
  ret += 0LL;

  // printf( "f %10lld = %10lld\n", x, ret );

  return ret;
}

int main() {
  long long m, n;

  while (cin >> m >> n, m >= 0 && n >= 0) {
    if (m > n) {
      swap(m, n);
    }

    if (m == n) {
      if (m == 0) {
        puts("1");
        continue;
      }

      int ans = 0;

      while (m > 0) {
        ans += (m % 10 == 0);
        m /= 10;
      }

      cout << ans << endl;
      continue;
    }

    long long ans = F(n) - F(m - 1);
    cout << ans << endl;
    // puts( "----------------------" );
  }

  return 0;
}