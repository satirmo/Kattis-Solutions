#include <bits/stdc++.h>

using namespace std;

const int maxn = 25;

string a[maxn];

int main() {
  for (int t = 1;; t++) {
    int n;
    cin >> n;
    cin.ignore();

    if (n == 0) {
      break;
    }

    for (int i = 0; i < n; i++) {
      int idx = (i & 1) ? n - 1 - (i / 2) : (i / 2);
      cin >> a[idx];
    }

    printf("SET %d\n", t);
    for (int i = 0; i < n; i++) {
      cout << a[i] << endl;
    }
  }

  return 0;
}