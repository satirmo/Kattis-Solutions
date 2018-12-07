#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;

  while (cin >> n) {
    string ans = (n % 2 == 0) ? "Bob" : "Alice";
    cout << ans << endl;
  }

  return 0;
}