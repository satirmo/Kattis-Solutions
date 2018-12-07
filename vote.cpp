#include <bits/stdc++.h>

using namespace std;

const int maxn = 15;

int a[maxn];

int main() {
  int test;
  cin >> test;

  while (test--) {
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }

    int maj = (sum / 2) + 1;
    int maxx = 0;
    bool winner = true;

    for (int i = 1; i < n; i++) {
      if (a[i] > a[maxx]) {
        maxx = i;
        winner = true;
      }

      else if (a[i] == a[maxx]) {
        winner = false;
      }
    }

    if (winner) {
      cout << (maj <= a[maxx] ? "majority" : "minority") << " winner "
           << to_string(maxx + 1) << endl;
    }

    else {
      cout << "no winner" << endl;
    }
  }

  return 0;
}