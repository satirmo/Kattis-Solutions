#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
  string s;
  while (getline(cin, s)) {
    v.clear();
    stringstream ss(s);

    int t;
    while (ss >> t) {
      v.push_back(t);
    }

    for (int i = 0; i < (int)v.size(); i++) {
      int sum = 0;
      for (int j = 0; j < (int)v.size(); j++) {
        if (i != j) {
          sum += v[j];
        }
      }

      if (sum == v[i]) {
        cout << sum << endl;
        break;
      }
    }
  }

  return 0;
}