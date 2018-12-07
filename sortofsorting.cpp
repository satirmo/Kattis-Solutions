#include <bits/stdc++.h>

using namespace std;

const int maxn = 205;

struct Data {
  int idx;
  string s;
};

Data a[maxn];

bool Cmp(Data a, Data b) {
  if (a.s[0] != b.s[0]) {
    return a.s[0] < b.s[0];
  }

  if (a.s[1] != b.s[1]) {
    return a.s[1] < b.s[1];
  }

  return a.idx < b.idx;
}

int main() {
  int n;
  bool flag = false;

  while (cin >> n, n != 0) {
    if (flag) {
      puts("");
    }

    flag = true;

    cin.ignore();

    for (int i = 0; i < n; i++) {
      a[i].idx = i;
      cin >> a[i].s;
    }

    sort(a, a + n, Cmp);

    for (int i = 0; i < n; i++) {
      cout << a[i].s << endl;
    }
  }

  return 0;
}