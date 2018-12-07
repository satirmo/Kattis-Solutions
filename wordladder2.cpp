#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> is;

const int maxn = 1005;
const int inf = 1 << 30;

string s[maxn];
int G[maxn][maxn];
int dist[maxn][maxn];
queue<int> qu;

int Difference(int it, int jt) {
  int ret = 0;

  for (int i = 0; i < s[it].size(); i++) {
    if (s[it][i] != s[jt][i]) {
      ret++;
    }
  }

  return ret;
}

void BFS(int st, int n) {
  memset(dist[st], -1, sizeof dist[st]);

  dist[st][st] = 0;
  qu.push(st);

  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();

    for (int v = 0; v < n; v++) {
      if (G[u][v] == 1 && dist[st][v] == -1) {
        dist[st][v] = dist[st][u] + 1;
        qu.push(v);
      }
    }
  }
}

is InsertWord(int n) {
  is ret = is(inf, "zzzzzzzzz");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (Difference(i, j) == 2 && dist[0][i] != -1 && dist[1][j] != -1) {
        int candidate = 2 + dist[0][i] + dist[1][j];

        bool flag = true;
        string word1 = s[i];
        string word2 = s[j];

        for (int k = 0; k < s[i].size(); k++) {
          if (s[i][k] != s[j][k]) {
            word1[k] = s[j][k];
            word2[k] = s[i][k];

            break;
          }
        }

        string word = min(word1, word2);

        if (candidate < ret.first ||
            (candidate == ret.first && word < ret.second)) {
          ret.first = candidate;
          ret.second = word;
        }
      }
    }
  }

  return ret;
}

int main() {
  int n;

  while (cin >> n) {
    cin.ignore();

    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        G[i][j] = (Difference(i, j) == 1) ? 1 : 0;
        // printf("%3d", G[i][j]);
      }

      // puts("");
    }

    // cout << "n = " << n << endl;

    for (int i = 0; i < n; i++) {
      BFS(i, n);

      /* for (int j = 0; j < n; j++) {
              printf("%s -> %s : %3d\n", s[ i ].c_str(), s[ j ].c_str(),
      dist[i][j]);
      } */
    }

    int minInitial = (dist[0][1] == -1) ? inf : dist[0][1];
    is minInsert = InsertWord(n);

    if (minInitial == inf && minInsert.first == inf) {
      puts("0");
      puts("-1");
    }

    else if (minInsert.first < minInitial) {
      printf("%s\n", minInsert.second.c_str());
      printf("%d\n", minInsert.first);
    }

    else {
      puts("0");
      printf("%d\n", minInitial);
    }
  }

  return 0;
}