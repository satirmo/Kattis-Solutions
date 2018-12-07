#include <bits/stdc++.h>

using namespace std;

const int maxn = 55;

bitset<maxn> bit;

int main() {
  for (int i = 0; i < 10; i++) {
    int x;
    cin >> x;

    bit[x % 42] = true;
  }

  int ans = bit.count();
  cout << ans << endl;

  return 0;
}