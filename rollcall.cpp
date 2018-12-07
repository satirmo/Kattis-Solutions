#include <bits/stdc++.h>

using namespace std;

typedef pair<string, string> ss;

vector<ss> v;

bool Cmp(ss a, ss b) {
  if (a.second != b.second) {
    return a.second < b.second;
  }

  return a.first < b.first;
}

int main() {
  string fname, lname;

  while (cin >> fname >> lname) {
    v.push_back(ss(fname, lname));
  }

  sort(v.begin(), v.end(), Cmp);

  for (int i = 0; i < v.size(); i++) {
    bool unique = true;

    for (int j = 0; j < v.size(); j++) {
      if (i == j) {
        continue;
      }

      if (v[i].first == v[j].first) {
        unique = false;
      }
    }

    cout << v[i].first;

    if (!unique) {
      cout << " " << v[i].second;
    }

    cout << endl;
  }

  return 0;
}