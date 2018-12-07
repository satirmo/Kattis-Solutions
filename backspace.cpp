#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;

  while (cin >> s) {
    int it = 0;
    string t = s;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '<') {
        it--;
        continue;
      }

      else {
        t[it++] = s[i];
      }
    }

    string ans = (it == 0) ? "" : t.substr(0, it);
    cout << ans << endl;
  }

  return 0;
}