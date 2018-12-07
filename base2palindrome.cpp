#include <bits/stdc++.h>

using namespace std;

const int maxn = 50005;

vector<string> evens, odds;

int main() {
  int n;

  while (cin >> n) {
    if (n == 1) {
      puts("1");
      continue;
    }

    if (n == 2) {
      puts("3");
      continue;
    }

    int cnt = 2;
    int len = 2;
    int evens = 1;
    int odds = 1;

    for (int i = 3; cnt < n; i++) {
      int add = 1 << ((i - 1) / 2);
      cnt += add;

      if (i & 1) {
        odds += add;
      }

      else {
        evens += add;
      }

      len++;

      // printf( "at len = %3d, adding %10d\n", i, add );
    }

    // printf( "n = %6d, len = %3d\n", n, len );

    if (len & 1) {
      n -= evens;
    }

    else {
      n -= odds;
    }

    string s = "";
    int upto = (len + 1) / 2;

    for (int i = 0; i < upto; i++) {
      int m = n >> i;

      if (m == 0) {
        break;
      }

      s = to_string(m & 1) + s;
    }

    string t = (len & 1) ? s.substr(0, s.size() - 1) : s;
    reverse(t.begin(), t.end());

    string str = s + t;

    long long ans = 0LL;

    for (char c : str) {
      ans = (ans << 1) + (c == '1');
    }

    // printf( "ans = %s\n", str.c_str() );

    cout << ans << endl;
  }

  return 0;
}