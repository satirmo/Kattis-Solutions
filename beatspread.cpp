#include <bits/stdc++.h>

using namespace std;

int main() {
  int test;
  cin >> test;

  while (test--) {
    int sum, diff;
    cin >> sum >> diff;

    int a = -1, b = -1;

    for (int i = 0; i <= sum; i++) {
      int j = sum - i;

      if (abs(i - j) == diff) {
        a = i, b = j;
      }
    }

    if (a == -1) {
      puts("impossible");
    }

    else {
      printf("%d %d\n", a, b);
    }
  }

  return 0;
}