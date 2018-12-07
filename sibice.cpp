#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, w, h;
  cin >> n >> w >> h;

  int dist = w * w + h * h;

  while (n--) {
    int len;
    cin >> len;

    if (dist >= len * len) {
      puts("DA");
    }

    else {
      puts("NE");
    }
  }

  return 0;
}