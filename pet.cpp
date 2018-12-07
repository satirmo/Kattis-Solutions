#include <bits/stdc++.h>

using namespace std;

int sum[10];

int main() {
  int idx = 1;

  for (int i = 1; i <= 5; i++) {
    for (int j = 0; j < 4; j++) {
      int x;
      cin >> x;

      sum[i] += x;
    }

    if (sum[i] > sum[idx]) {
      idx = i;
    }
  }

  printf("%d %d\n", idx, sum[idx]);

  return 0;
}