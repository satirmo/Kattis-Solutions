#include <bits/stdc++.h>

using namespace std;

string F(long long p, long long q) {
  if (p == 1LL && q == 1LL) {
    return "1";
  }

  if (p < q) {
    return "0" + F(p, q - p);
  }

  return "1" + F(p - q, q);
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    long long t, p, q;
    scanf("%lld %lld/%lld", &t, &p, &q);

    string sans = F(p, q);
    reverse(sans.begin(), sans.end());

    long long ans = stoll(sans, 0, 2);
    printf("%lld %lld\n", t, ans);
  }

  return 0;
}