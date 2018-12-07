#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;

  while (cin >> n, n != -1) {
    int prevTime = 0;
    int ans = 0;

    while (n--) {
      int dist, currTime;
      cin >> dist >> currTime;

      ans += dist * (currTime - prevTime);
      prevTime = currTime;
    }

    printf("%d miles\n", ans);
  }

  return 0;
}