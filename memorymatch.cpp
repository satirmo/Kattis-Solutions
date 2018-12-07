#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

struct Data {
  string s;
  bool taken;

  Data() {
    this->s = "";
    this->taken = false;
  }
};

Data a[maxn];

int main() {
  int n;
  while (cin >> n) {
    int k;
    cin >> k;

    for (int i = 0; i < n; i++) {
      a[i] = Data();
    }

    while (k--) {
      int x, y;
      string sx, sy;
      scanf("%d %d\n", &x, &y);
      cin >> sx >> sy;

      a[x].s = sx;
      a[y].s = sy;

      if (sx == sy) {
        a[x].taken = true;
        a[y].taken = true;
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i].s != "" && a[i].taken == false) {
        for (int j = i + 1; j <= n; j++) {
          if (a[j].s == a[i].s && a[j].taken == false) {
            ans++;
            a[i].taken = true;
            a[j].taken = true;
            break;
          }
        }
      }
    }

    int known = 0;
    int notKnown = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i].s != "" && a[i].taken == false) {
        known++;
      }

      if (a[i].s == "") {
        notKnown++;
      }
    }

    if (known == notKnown) {
      ans += notKnown;
    }

    else if (notKnown == 2 && known == 0) {
      ans++;
    }

    else if (notKnown == 0) {
      ans += known / 2;
    }

    cout << ans << endl;
  }

  return 0;
}