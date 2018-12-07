#include <bits/stdc++.h>

using namespace std;

long long GetOctal(int n) {
  long long ret = 0LL;
  string sn = to_string(n);

  for (char c : sn) {
    if (c >= '8') {
      return 0;
    }

    ret = 8LL * ret + c - '0';
  }

  return ret;
}

long long GetHexadecimal(int n) {
  long long ret = 0LL;
  string sn = to_string(n);

  for (char c : sn) {
    ret = 16LL * ret + c - '0';
  }

  return ret;
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int t, n;
    cin >> t >> n;

    long long ov = GetOctal(n);
    long long dv = n;
    long long hv = GetHexadecimal(n);

    printf("%d %lld %lld %lld\n", t, ov, dv, hv);
  }

  return 0;
}