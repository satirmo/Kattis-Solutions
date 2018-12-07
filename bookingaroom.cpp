#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

bitset<maxn> room;

int main() {
  int n, r;
  cin >> n >> r;

  while (r--) {
    int x;
    cin >> x;

    room[x] = true;
  }

  if (room.count() == n) {
    cout << "too late" << endl;
  }

  else {
    for (int i = 1; i <= n; i++) {
      if (room[i] == false) {
        cout << i << endl;
        break;
      }
    }
  }

  return 0;
}