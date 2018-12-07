#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

vector<int> heights;
string a[maxn];

void AddHeights(int idx) {
  for (char c : a[idx]) {
    if (c == '*') {
      heights.push_back(idx);
    }
  }

  a[idx] = string(a[0].size(), '.');
}

int main() {
  bool flag = false;

  while (getline(cin, a[0])) {
    if (flag) {
      puts("");
    }
    flag = true;
    heights.clear();

    int n = 1;
    AddHeights(0);

    while (getline(cin, a[n])) {
      if (a[n] == "") {
        break;
      }

      AddHeights(n++);
    }

    sort(heights.begin(), heights.end());
    reverse(heights.begin(), heights.end());

    for (int i = 0; i < a[0].size(); i++) {
      a[heights[i]][i] = '*';
    }

    for (int i = 0; i < n; i++) {
      cout << a[i] << endl;
    }
  }

  return 0;
}