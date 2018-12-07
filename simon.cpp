#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  cin.ignore();

  string simon = "simon says";

  while (t--) {
    string line;
    getline(cin, line);

    if (line.size() < simon.size()) {
      puts("");
      continue;
    }

    if (line.substr(0, simon.size()) != simon) {
      puts("");
      continue;
    }

    string s;
    stringstream ss(line);

    ss >> s;
    ss >> s;

    bool flag = false;
    while (ss >> s) {
      if (flag) {
        printf(" ");
      }

      cout << s;
      flag = true;
    }

    cout << endl;
  }

  return 0;
}