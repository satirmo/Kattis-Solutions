#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;

long long cnt[maxn];

int main() {
  while (true) {
    int n;
    int l = 1, r = 10;

    while (cin >> n, n != 0) {
      cin.ignore();
      string response;
      getline(cin, response);

      if (response == "right on") {
        break;
      }

      if (response == "too high") {
        r = min(r, n - 1);
      }

      if (response == "too low") {
        l = max(l, n + 1);
      }
    }

    if (n == 0) {
      break;
    }

    string ans =
        (l <= n && n <= r) ? "Stan may be honest" : "Stan is dishonest";
    cout << ans << endl;
  }

  return 0;
}