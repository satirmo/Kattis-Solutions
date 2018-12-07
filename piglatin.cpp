#include <bits/stdc++.h>

using namespace std;

bool IsVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
  string line;

  while (getline(cin, line)) {
    stringstream ss(line);
    string s;

    for (bool space = false; ss >> s; space = true) {
      if (space) {
        cout << " ";
      }

      if (IsVowel(s[0])) {
        string ans = s + "yay";
        cout << ans;
      }

      else {
        string a = "", b = "";

        for (int i = 0; i < s.size(); i++) {
          if (IsVowel(s[i])) {
            a = s.substr(i, s.size() - i);
            b = s.substr(0, i);
            break;
          }
        }

        string ans = a + b + "ay";
        cout << ans;
      }
    }

    puts("");
  }

  return 0;
}