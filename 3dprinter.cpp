#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  int ans = 1;
  int printers = 1;

  while (printers < n) {
    ans++;
    printers <<= 1;
  }

  cout << ans << endl;

  return 0;
}