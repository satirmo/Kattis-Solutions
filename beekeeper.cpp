#include <bits/stdc++.h>

using namespace std;

vector<char> vowel = {'a', 'e', 'i', 'o', 'u', 'y'};

int CountE(string s) {
  int ret = 0;

  for (int i = 1; i < s.size(); i++) {
    for (char v : vowel) {
      if (v == s[i] && v == s[i - 1]) {
        i++;
        ret++;
        break;
      }
    }
  }

  return ret;
}

int main() {
  int n;

  while (cin >> n, n != 0) {
    cin.ignore();

    int maxx = -1;
    string ans = "";

    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;

      int scnt = CountE(s);

      if (scnt > maxx) {
        maxx = scnt;
        ans = s;
      }
    }

    cout << ans << endl;
  }

  return 0;
}