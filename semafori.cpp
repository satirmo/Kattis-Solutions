#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int maxn = 1005;

ii stoplight[maxn];

int main() {
  int n, l;
  cin >> n >> l;

  while (n--) {
    int d, r, g;
    cin >> d >> r >> g;

    stoplight[d] = ii(r, g);
  }

  int tim = 0;

  for (int i = 0; i < l; i++) {
    if (stoplight[i] == ii(0, 0)) {
      tim++;
    }

    else {
      int r = stoplight[i].first;
      int g = stoplight[i].second;

      int timCycle = tim % (r + g);

      if (timCycle < r) {
        tim += r - timCycle;
      }

      tim++;
    }
  }

  cout << tim << endl;

  return 0;
}