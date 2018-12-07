#include <bits/stdc++.h>

using namespace std;

map<string, int> mapa;

int main() {
  int n, t = 1;
  while (cin >> n, n != 0) {
    mapa.clear();
    cin.ignore();

    for (int i = 0; i < n; i++) {
      string line;
      getline(cin, line);

      string s;
      stringstream ss(line);
      while (ss >> s);

      for (int j = 0; j < s.size(); j++) {
        s[j] = tolower(s[j]);
      }

      mapa[s]++;
    }

    printf("List %d:\n", t++);
    for (auto t : mapa) {
      printf("%s | %d\n", t.first.c_str(), t.second);
    }
  }

  return 0;
}