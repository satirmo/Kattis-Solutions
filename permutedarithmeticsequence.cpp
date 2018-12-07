#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

int a[maxn], b[maxn];

int main() {
  int test;
  cin >> test;

  while (test--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }

    sort(b, b + n);

    bool arithmetic = true;
    for (int i = 1; i < n; i++) {
      if (b[1] - b[0] != b[i] - b[i - 1]) {
        arithmetic = false;
      }
    }

    int s1 = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        s1 &= 0;
      }
    }

    int s2 = 1;
    reverse(b, b + n);
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        s2 &= 0;
      }
    }

    bool sorted = s1 | s2;

    if (arithmetic) {
      if (sorted) {
        cout << "arithmetic" << endl;
      }

      else {
        cout << "permuted arithmetic" << endl;
      }
    }

    else {
      cout << "non-arithmetic" << endl;
    }
  }
}