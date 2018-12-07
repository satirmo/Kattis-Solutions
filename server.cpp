#include <bits/stdc++.h>

using namespace std;

const int maxn = 35;
const int inf = 1 << 30;

int main() {
  int n, ti;
  cin >> n >> ti;

  int ans = 0;
  while (n--) {
    int r;
    cin >> r;

    ti -= r;

    if (ti >= 0) {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}