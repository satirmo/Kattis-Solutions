#include <bits/stdc++.h>

using namespace std;

const int maxn = 25;

string name[maxn];

bool IsIncreasing(int n) {
  for (int i = 1; i < n; i++) {
    if (name[i - 1] > name[i]) {
      return false;
    }
  }

  return true;
}

bool IsDecreasing(int n) {
  for (int i = 1; i < n; i++) {
    if (name[i - 1] < name[i]) {
      return false;
    }
  }

  return true;
}

string DetermineOrder(int n) {
  if (IsIncreasing(n)) {
    return "INCREASING";
  }

  if (IsDecreasing(n)) {
    return "DECREASING";
  }

  return "NEITHER";
}

int main() {
  int n;

  while (cin >> n) {
    cin.ignore();

    for (int i = 0; i < n; i++) {
      cin >> name[i];
    }

    string ans = DetermineOrder(n);
    cout << ans << endl;
  }

  return 0;
}