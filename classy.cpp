#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

struct data {
  long long v;
  string s;
};

data a[maxn];

bool Cmp(data a, data b) {
  if (a.v != b.v) {
    return a.v > b.v;
  }

  return a.s < b.s;
}

long long CalcRank(string rank) {
  long long ret = 0;
  long long m = 1000000000000000LL;

  for (int i = rank.size() - 1, j = 0; 0 <= i || j < 15; i--, j++, m /= 10LL) {
    if (i < 0) {
      ret += 2 * m;
      continue;
    }

    while (i > 0 && rank[i - 1] != '-') {
      i--;
    }

    if (i == 1) {
      i--;
    }

    if (rank[i] == 'u') {
      ret += 3 * m;
    }

    else if (rank[i] == 'm') {
      ret += 2 * m;
    }

    else {
      ret += m;
    }

    while (0 < i && rank[--i] != '-');
  }

  return ret;
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
      string name, rank, cs;
      cin >> name >> rank >> cs;

      long long v = CalcRank(rank);

      a[i].s = name;
      a[i].v = v;
    }

    sort(a, a + n, Cmp);

    for (int i = 0; i < n; i++) {
      cout << a[i].s.substr(0, a[i].s.size() - 1) << endl;
    }

    cout << "==============================" << endl;
  }

  return 0;
}