#include <bits/stdc++.h>

using namespace std;

const int maxn = 55;

int par[maxn];
int visit[maxn];
vector<string> v;
vector<int> G[maxn];
map<string, int> name2id;
map<int, string> id2name;

int DFS(int u, int t) {
  visit[u] = 1;

  for (int v : G[u]) {
    if (visit[v] == 0) {
      par[v] = u;

      if (v == t) {
        return 1;
      }

      int val = DFS(v, t);

      if (val == 1) {
        return 1;
      }
    }
  }

  return 0;
}

int GetId(string s) {
  if (name2id.count(s) == 0) {
    int x = name2id.size();

    name2id[s] = x;
    id2name[x] = s;
  }

  return name2id[s];
}

int main() {
  int n;
  cin >> n;
  cin.ignore();

  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);

    stringstream ss(line);

    string su, sv;
    ss >> su;

    int u = GetId(su);

    while (ss >> sv) {
      int v = GetId(sv);

      G[u].push_back(v);
      G[v].push_back(u);
    }
  }

  string line, s, t;
  getline(cin, line);
  stringstream ss(line);
  ss >> s >> t;

  if (name2id.count(s) == 0 || DFS(name2id[s], name2id[t]) == 0) {
    puts("no route found");
  }

  else {
    for (int u = name2id[t]; u != name2id[s]; u = par[u]) {
      v.push_back(id2name[u]);
    }

    v.push_back(s);
    reverse(v.begin(), v.end());

    bool flag = false;

    for (string s : v) {
      if (flag) {
        cout << " ";
      }

      flag = true;
      cout << s;
    }

    puts("");
  }

  return 0;
}