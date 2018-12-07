#include <bits/stdc++.h>

using namespace std;

int probability[50];

int main() {
  int n, m;

  while (cin >> n >> m) {
    memset(probability, 0, sizeof probability);

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int sum = i + j;
        probability[sum]++;
      }
    }

    int idx = 2;
    vector<int> ans = {};

    for (int i = 2; i <= n + m; i++) {
      if (probability[i] > probability[idx]) {
        idx = i;

        ans.clear();
        ans.push_back(i);
      }

      else if (probability[i] == probability[idx]) {
        ans.push_back(i);
      }
    }

    for (int v : ans) {
      cout << v << endl;
    }

    break;
  }

  return 0;
}