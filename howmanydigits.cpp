#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;

double digits[maxn];

int main() {
  digits[0] = 1.0;
  for (int i = 1; i < maxn; i++) {
    digits[i] = digits[i - 1] + log10(i);
  }

  int n;

  while (cin >> n) {
    cout << (int)digits[n] << endl;
  }

  return 0;
}