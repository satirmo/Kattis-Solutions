#include <bits/stdc++.h>

using namespace std;

int a[25];

int main() {
  int test;
  cin >> test;

  for (int t = 1; t <= test; t++) {
    int x;
    cin >> x;

    int ans = 0;
    for (int i = 0; i < 20; i++) {
      cin >> a[i];

      for (int j = i; j > 0; j--) {
        if (a[j - 1] > a[j]) {
          swap(a[j], a[j - 1]);
          ans++;
        }
      }
    }

    cout << t << " " << ans << endl;
  }

  return 0;
}