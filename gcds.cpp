#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

vector<int> v;
bitset<maxn> bit;
int gcd[maxn][maxn];

void Preprocess() {
  for (int i = 1; i < maxn; i++) {
    for (int j = 1; j < maxn; j++) {
      gcd[i][j] = __gcd(i, j);
    }
  }
}

int CountGCD() {
  int ret = 0;

  for (int i = 1; i < maxn; i++) {
    int currentGCD = v[0];

    for (int x : v) {
      if (x % i != 0) {
        currentGCD = -1;
        continue;
      }

      if (currentGCD == -1) {
        currentGCD = x;
      }

      currentGCD = gcd[currentGCD][x];

      if (currentGCD == i) {
        ret++;
        break;
      }
    }
  }

  return ret;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  Preprocess();
  int ans = CountGCD();

  cout << ans << endl;

  return 0;
}