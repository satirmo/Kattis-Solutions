#include <bits/stdc++.h>

using namespace std;

const int maxn = 55;

long long comb[maxn][maxn];

void Pascal() {
  for (int i = 0; i < maxn; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        comb[i][j] = 1;
      }

      else {
        comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
      }
    }
  }
}

string GetVerdict(int n, int v1, int v2, int w) {
  int votesLeft = n - v1 - v2;
  int votesToWin = (n + 2) / 2;
  long long possibleWins = 0LL;
  long long possibleOutcomes = 1LL << votesLeft;

  for (int i = 0; i <= votesLeft; i++) {
    if (v1 + i >= votesToWin) {
      possibleWins += comb[votesLeft][i];
    }
  }

  if (100LL * possibleWins > w * possibleOutcomes) {
    return "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!";
  }

  else if (possibleWins == 0LL) {
    return "RECOUNT!";
  }

  return "PATIENCE, EVERYONE!";
}

int main() {
  Pascal();

  int test;
  cin >> test;

  while (test--) {
    int n, v1, v2, w;
    cin >> n >> v1 >> v2 >> w;

    string ans = GetVerdict(n, v1, v2, w);
    cout << ans << endl;
  }

  return 0;
}