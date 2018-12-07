#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    long long n;
    cin >> n;

    long long sum = 0LL;

    for (int i = 0; i < n; i++) {
      long long candy;
      scanf("%lld", &candy);

      sum += (candy % n);
      sum %= n;
    }

    string ans = (sum == 0LL) ? "YES" : "NO";
    cout << ans << endl;
  }

  return 0;
}