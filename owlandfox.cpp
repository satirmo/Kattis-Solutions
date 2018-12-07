#include <bits/stdc++.h>

using namespace std;

int main() {
  int test;
  cin >> test;

  while (test--) {
    string s;
    cin >> s;

    int ns = stoi(s);

    int ans = ns;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] != '0') {
        string t = s;
        t[i]--;

        ans = stoi(t);
      }
    }

    cout << ans << endl;
  }

  return 0;
}