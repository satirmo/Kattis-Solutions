#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;

long long a[maxn];

int main() {
  string s;

  while (cin >> s) {
    int ans = 0;

    for (int i = 1; i < s.size(); i++) {
      int upto = s.size() - i + 1;

      bool matches = true;
      for (int j = 0; j < upto; j++) {
        bool found = false;
        string t = s.substr(j, i);

        for (int k = 0; k < upto; k++) {
          if (j == k) {
            continue;
          }

          if (t == s.substr(k, i)) {
            found = true;
            break;
          }
        }

        if (!found) {
          matches = false;
          break;
        }
      }

      if (!matches) {
        break;
      }

      ans = i;
    }

    cout << ans << endl;
  }

  return 0;
}