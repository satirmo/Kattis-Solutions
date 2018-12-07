#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;

int building[maxn];

bool CanTearDown(int moves) {
  for (int i = 0; i < moves; i++) {
    if (building[i] <= moves - i) {
      return true;
    }
  }

  return false;
}

int CalculateCharges(int n) {
  sort(building, building + n);
  reverse(building, building + n);

  int L = 1, R = n;

  while (L < R) {
    int m = (L + R) / 2;

    if (CanTearDown(m)) {
      R = m;
    }

    else {
      L = m + 1;
    }
  }

  return L;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> building[i];
  }

  int ans = CalculateCharges(n);
  cout << ans << endl;

  return 0;
}