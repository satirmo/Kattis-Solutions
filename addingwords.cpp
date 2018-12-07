#include <bits/stdc++.h>

using namespace std;

map<string, int> mapa;

int main() {
  string line;

  while (getline(cin, line)) {
    if (line == "clear") {
      mapa.clear();
      continue;
    }

    if (line[0] == 'd') {
      stringstream ss(line);

      int val;
      string def, word;

      ss >> def >> word >> val;
      mapa[word] = val;
    }

    else {
      stringstream ss(line);

      int sum = 0;
      bool found = true;

      string op;
      string ans = "";

      while (ss >> op) {
        if (op != "calc") {
          ans += " " + op;
        }

        if (op == "=") {
          break;
        }

        string word;
        ss >> word;

        if (ans != "") {
          ans += " ";
        }

        if (word != "calc") {
          ans += word;
        }

        if (mapa.count(word) == 0) {
          found = false;
        }

        else {
          int val = mapa[word];

          if (op == "-") {
            sum -= val;
          }

          else {
            sum += val;
          }
        }
      }

      bool isWord = false;

      for (auto it : mapa) {
        if (sum == it.second && found) {
          ans += " " + it.first;
          isWord = true;
        }
      }

      if (!isWord) {
        ans += " unknown";
      }

      cout << ans << endl;
    }
  }

  return 0;
}