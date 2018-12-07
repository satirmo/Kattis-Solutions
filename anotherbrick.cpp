#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;

int x[maxn];

int main() {
  int h, w, n;
  cin >> h >> w >> n;

  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  int sum = 0;
  int rows = 0;
  bool possible = true;

  for (int i = 0; i < n; i++) {
    sum += x[i];

    if (sum == w) {
      sum = 0;
      rows++;
    }

    else if (sum > w) {
      possible = false;
    }
  }

  if (rows < h) {
    possible = false;
  }

  string ans = (possible ? "YES" : "NO");
  cout << ans << endl;

  return 0;
}