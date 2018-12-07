#include <bits/stdc++.h>

using namespace std;

int main() {
  string line;

  while (getline(cin, line)) {
    string name = "";

    double sum = 0;
    int cnt = 0;

    string s;
    stringstream ss(line);

    while (ss >> s) {
      if (isalpha(s[0])) {
        if (name.size() != 0) {
          name += " ";
        }

        name += s;
      }

      else {
        sum += stod(s);
        cnt++;
      }
    }

    if (cnt == 0) {
      cnt++;
    }

    double average = (double)sum / cnt;

    printf("%.6lf %s\n", average, name.c_str());
  }

  return 0;
}