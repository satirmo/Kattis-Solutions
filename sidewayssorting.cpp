#include <bits/stdc++.h>

using namespace std;

const int maxn = 25;

string a[maxn];
vector<string> v;

bool Cmp(string s, string t) {
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  transform(t.begin(), t.end(), t.begin(), ::tolower);

  return s > t;
}

int main() {
  int n, m;
  bool newLine = false;
  while (cin >> n >> m, n != 0 || m != 0) {
    if (newLine) {
      cout << endl;
    }

    newLine = true;
    v.clear();

    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    // create the vertical strings and store in vector v
    for (int i = 0; i < m; i++) {
      string s = "";

      for (int j = 0; j < n; j++) {
        s += a[j][i];
      }

      v.push_back(s);
    }

    // sort vector v
    for (int i = 0; i < v.size(); i++) {
      for (int j = 1; j < v.size(); j++) {
        if (Cmp(v[j - 1], v[j])) {
          swap(v[j - 1], v[j]);
        }
      }
    }

    // recreate and print horizontal strings
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        a[i][j] = v[j][i];
      }

      cout << a[i] << endl;
    }
  }

  return 0;
}