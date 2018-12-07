#include <bits/stdc++.h>

using namespace std;

int main() {
  string line;

  while (getline(cin, line)) {
    for (int i = 0; i < line.size(); i++) {
      line[i] = tolower(line[i]);
    }

    int pos = line.find("problem");

    cout << (pos == -1 ? "no" : "yes") << endl;
  }

  return 0;
}