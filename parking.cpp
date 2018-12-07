#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

int cost[maxn];
int cars[maxn];

int main() {
  for (int i = 1; i <= 3; i++) {
    cin >> cost[i];
    cost[i] *= i;
  }

  for (int i = 0; i < 3; i++) {
    int x, y;
    cin >> x >> y;

    while (x < y) {
      cars[x]++;
      x++;
    }
  }

  int ans = 0;

  for (int i = 0; i < maxn; i++) {
    ans += cost[cars[i]];
  }

  cout << ans << endl;

  return 0;
}