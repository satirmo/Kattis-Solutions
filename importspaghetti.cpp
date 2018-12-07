#include <bits/stdc++.h>

using namespace std;

const int maxn = 505;
const int inf = 1000005;

string convIToS[maxn];
map<string, int> convSToI;
int par[maxn][maxn];
int dist[maxn][maxn];

vector<string> FloydWarshall(int n) {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          par[i][j] = par[k][j];
        }
      }
    }
  }

  int minnidx = 0;
  bool hasCycle = false;

  for (int i = 0; i < n; i++) {
    if (dist[minnidx][minnidx] > dist[i][i]) {
      minnidx = i;
    }

    if (dist[i][i] != inf) {
      hasCycle = true;
    }
  }

  vector<string> ret = {};

  if (hasCycle == false) {
    return ret;
  }

  int u = minnidx;
  int v = minnidx;

  do {
    ret.push_back(convIToS[v]);
    v = par[u][v];
  } while (u != v);

  return ret;
}

int main() {
  for (int i = 0; i < maxn; i++) {
    for (int j = 0; j < maxn; j++) {
      dist[i][j] = inf;
      par[i][j] = i;
    }
  }

  int n;
  cin >> n;

  cin.ignore();

  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;

    convSToI[name] = i;
    convIToS[i] = name;
  }

  for (int i = 0; i < n; i++) {
    int m;
    string s;
    cin >> s >> m;
    cin.ignore();

    int si = convSToI[s];

    while (m--) {
      string line;
      getline(cin, line);

      for (int i = 6; i < line.size();) {
        while (i < line.size() && (line[i] == ' ' || line[i] == ',')) {
          i++;
        }

        if (i == line.size()) {
          break;
        }

        int j = i;

        while (j < line.size() && line[j] != ',' && line[j] != ' ') {
          j++;
        }

        string t = line.substr(i, j - i);
        int ti = convSToI[t];

        dist[ti][si] = 1;

        i = j;
      }
    }
  }

  vector<string> ans = FloydWarshall(n);

  if (ans.size() == 0) {
    puts("SHIP IT");
  }

  else {
    for (int i = 0; i < ans.size(); i++) {
      if (i) {
        printf(" ");
      }

      printf("%s", ans[i].c_str());
    }

    cout << endl;
  }

  return 0;
}