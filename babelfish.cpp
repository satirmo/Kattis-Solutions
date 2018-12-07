#include <bits/stdc++.h>

using namespace std;

map<string, string> translation;

int main() {
  string input;

  while (getline(cin, input), input != "") {
    stringstream ss(input);

    string word, foreign;
    ss >> word >> foreign;

    translation[foreign] = word;
  }

  while (cin >> input) {
    string ans = (translation.count(input)) ? translation[input] : "eh";
    cout << ans << endl;
  }

  return 0;
}