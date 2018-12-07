#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int x;
    cin >> x;

    if (x % 2 == 0) {
      cout << to_string(x) + " is even" << endl;
    }

    else {
      cout << to_string(x) + " is odd" << endl;
    }
  }

  return 0;
}