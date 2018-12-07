#include <bits/stdc++.h>

using namespace std;

int CalculateSum(int x) {
  int sum = 0;

  while (x) {
    sum += x % 10;
    x /= 10;
  }

  return sum;
}

int main() {
  int n;

  while (cin >> n, n != 0) {
    int sum = CalculateSum(n);
    int ans = -1;

    for (int i = 11; true; i++) {
      if (CalculateSum(i * n) == sum) {
        ans = i;
        break;
      }
    }

    cout << ans << endl;
  }

  return 0;
}