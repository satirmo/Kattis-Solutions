#include <bits/stdc++.h>

using namespace std;

bool IsVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
  string line;

  while (getline(cin, line)) {
    string ans = "";

    for (int i = 0; i < line.size(); i++) {
      ans += line[i];

      if (line.size() - i >= 3 && IsVowel(line[i]) && line[i] == line[i + 2] &&
          line[i + 1] == 'p') {
        i += 2;
      }
    }

    cout << ans << endl;
    break;
  }

  return 0;
}