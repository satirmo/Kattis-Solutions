#include <bits/stdc++.h>

using namespace std;

vector<string> v;

int main() {
  int test;
  cin >> test;
  cin.ignore();

  while (test--) {
    v.clear();

    string text;
    getline(cin, text);
    stringstream ss(text);

    string s;
    while (ss >> s) {
      v.push_back(s);
    }

    while (true) {
      string s;
      getline(cin, s);

      if (s == "what does the fox say?") {
        break;
      }

      stringstream ss(s);
      for (int i = 0; i < 3; i++) {
        string t;
        ss >> t;

        if (i == 2) {
          for (int j = 0; j < v.size(); j++) {
            if (v[j] == t) {
              v[j] = "";
            }
          }
        }
      }
    }

    bool space = false;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == "") {
        continue;
      }

      if (space) {
        printf(" ");
      }

      space = true;
      printf("%s", v[i].c_str());
    }
    puts("");
  }
}