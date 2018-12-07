#include <bits/stdc++.h>

using namespace std;

int a[] = {1, 1, 2, 2, 2, 8};

int main() {
  for (int i = 0; i < 6; i++) {
    if (i) {
      printf(" ");
    }

    int x;
    cin >> x;

    int ans = a[i] - x;
    cout << ans;
  }

  cout << endl;

  return 0;
}