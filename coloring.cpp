#include <bits/stdc++.h>

using namespace std;

const int maxn = 15;

int n;
int maxColor;
int color[maxn];
set<int> G[maxn];

bool dfs(vector<int> nodes) {
  if (nodes.size() == 0) {
    return true;
  }

  /* for( int k : nodes ){
          printf( "%3d", k );
  }
  puts( "" ); */

  int u = nodes[nodes.size() - 1];
  nodes.pop_back();

  for (int c = 0; c < maxColor; c++) {
    bool flag = true;

    for (int v : G[u]) {
      if (color[v] == c) {
        flag = false;
      }
    }

    if (flag) {
      color[u] = c;

      bool val = dfs(nodes);
      if (val) {
        return true;
      }

      color[u] = -1;
    }
  }

  return false;
}

int main() {
  cin >> n;
  cin.ignore();

  for (int u = 0; u < n; u++) {
    string input;
    getline(cin, input);
    stringstream ss(input);

    int v;
    while (ss >> v) {
      G[u].insert(v);
    }
  }

  /* for( int i = 0; i < n; i++ ){
          printf( "NODE %3d : ", i );
          for( int j : G[ i ] ){
                  printf( "%4d", j );
          }
          puts( "" );
  } */

  for (int candidate = 1; candidate <= n; candidate++) {
    maxColor = candidate;

    memset(color, -1, sizeof color);
    color[0] = 0;
    color[*(G[0].begin())] = 1;

    vector<int> v = {};
    for (int i = 1; i < n; i++) {
      if (i != *(G[0].begin())) {
        v.push_back(i);
      }
    }

    // printf( "CANDIDATE: k = %3d\n", candidate );
    if (dfs(v)) {
      cout << candidate << endl;
      break;
    }
  }

  return 0;
}