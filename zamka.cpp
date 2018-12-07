#include <bits/stdc++.h>

using namespace std;

const int inf = 1 << 30;

int CalculateSum(int x) {
  int ret = 0;

  while (x) {
    ret += x % 10;
    x /= 10;
  }

  return ret;
}

int main() {
  int l, d, x;
  cin >> l >> d >> x;

  int minn = inf;
  int maxx = -inf;

  for (int i = l; i <= d; i++) {
    int summ = CalculateSum(i);

    if (summ == x) {
      minn = min(minn, i);
      maxx = max(maxx, i);
    }
  }

  cout << minn << endl;
  cout << maxx << endl;

  return 0;
}