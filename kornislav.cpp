#include <bits/stdc++.h>

using namespace std;

int length[10];

int main() {
  while (cin >> length[0]) {
    for (int i = 1; i < 4; i++) {
      cin >> length[i];
    }

    sort(length, length + 4);

    int ans = 0;

    do {
      if (length[0] < length[2] || length[1] < length[3]) {
        continue;
      }

      int area = length[2] * length[3];
      ans = max(ans, area);

    } while (next_permutation(length, length + 4));

    cout << ans << endl;
  }

  return 0;
}