#include <bits/stdc++.h>

using namespace std;

int radius[] = {20, 40, 60, 80, 100, 120, 140, 160, 180, 200};

long long GetScore(int x, int y) {
  int dist = x * x + y * y;

  for (int i = 0; i < 10; i++) {
    int allowed = radius[i] * radius[i];

    if (allowed >= dist) {
      return 10 - i;
    }
  }

  return 0LL;
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int n;
    cin >> n;

    long long ans = 0LL;

    while (n--) {
      int x, y;
      cin >> x >> y;

      ans += GetScore(x, y);
    }

    cout << ans << endl;
  }

  return 0;
}