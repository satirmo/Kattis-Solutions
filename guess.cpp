#include <bits/stdc++.h>

using namespace std;

int main() {
  int l = 1, r = 1000;

  while (true) {
    int m = (l + r) / 2;
    cout << m << endl;

    string response;
    cin >> response;

    if (response == "correct") {
      break;
    }

    else if (response == "lower") {
      r = m - 1;
    }

    else {
      l = m + 1;
    }
  }

  return 0;
}