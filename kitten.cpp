#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;

int t[maxn];

int main() {
  int k;
  cin >> k;
  cin.ignore();

  string s;
  while (true) {
    getline(cin, s);

    if (s == "-1") {
      break;
    }

    stringstream ss(s);

    int a, b;
    ss >> a;
    while (ss >> b) {
      t[b] = a;
    }
  }

  bool flag = false;
  while (k != 0) {
    if (flag) {
      printf(" ");
    }

    flag = true;
    cout << k;
    k = t[k];
  }

  return 0;
}