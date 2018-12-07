#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  for (int i = 0; i < s.size();) {
    cout << s[i];

    int l = i;
    while (i < s.size() && s[i] == s[l]) {
      i++;
    }
  }
  cout << endl;

  return 0;
}