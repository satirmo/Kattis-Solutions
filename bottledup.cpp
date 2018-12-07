#include <bits/stdc++.h>

using namespace std;

int main() {
  int s, v1, v2;
  cin >> s >> v1 >> v2;

  int ans1 = -1, ans2 = -1;
  int minn = 1 << 30;
  for (int i = 0; i <= s; i += v1) {
    if ((s - i) % v2 == 0) {
      int t1 = i / v1;
      int t2 = (s - i) / v2;
      int t = t1 + t2;

      if (t < minn) {
        ans1 = t1;
        ans2 = t2;
      }
    }
  }

  if (ans1 == -1) {
    puts("Impossible");
  }

  else {
    printf("%d %d\n", ans1, ans2);
  }

  return 0;
}