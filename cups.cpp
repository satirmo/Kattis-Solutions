#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> is;

vector<is> v;

bool IsNum(string s) {
  for (char c : s) {
    if (!isdigit(c)) {
      return false;
    }
  }

  return true;
}

int main() {
  int n;
  cin >> n;
  cin.ignore();

  while (n--) {
    string sx, name;
    cin >> sx >> name;

    bool flag = false;

    if (!IsNum(sx)) {
      swap(sx, name);
      flag = true;
    }

    int x = stoi(sx) * (flag ? 2 : 1);
    v.push_back(is(x, name));
  }

  sort(v.begin(), v.end());

  for (auto it : v) {
    cout << it.second << endl;
  }

  return 0;
}