#include <bits/stdc++.h>

using namespace std;

int CalculateBarSize(int k) {
  int ret = 1;

  while (ret < k) {
    ret <<= 1;
  }

  return ret;
}

int CalculateBarBreak(int barSize, int k) {
  int ret = 0;

  while (true) {
    if (barSize <= k) {
      k -= barSize;
    }

    if (k == 0) {
      break;
    }

    ret++;
    barSize >>= 1;
  }

  return ret;
}

int main() {
  int k;

  while (cin >> k) {
    int barSize = CalculateBarSize(k);
    int pieces = CalculateBarBreak(barSize, k);

    printf("%d %d\n", barSize, pieces);
  }

  return 0;
}