#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> ii;

ii Traverse(string path) {
  long long num = 1LL;
  long long den = 1LL;

  for (char c : path) {
    if (c & 1) {
      num += den;
    }

    else {
      den += num;
    }
  }

  return ii(num, den);
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    long long t, n;
    cin >> t >> n;

    string path = "";

    while (n > 1) {
      path += to_string(n & 1);
      n >>= 1;
    }

    reverse(path.begin(), path.end());
    ii ans = Traverse(path);

    printf("%lld %lld/%lld\n", t, ans.first, ans.second);
  }
  return 0;
}