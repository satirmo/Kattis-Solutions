#include <bits/stdc++.h>

using namespace std;

const int maxN = 200000;
vector<int> G[maxN];
bitset<maxN> visited;

void DepthFirstSearch(int start, int num) {
  visited[start] = true;

  for (int v : G[start]) {
    if (visited[v] == false) {
      DepthFirstSearch(v, num);
    }
  }
}

int main() {
  int n, m, house1, house2;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    G[i].clear();
  }

  for (int i = 0; i < m; i++) {
    scanf("%d %d", &house1, &house2);
    G[house1].push_back(house2);
    G[house2].push_back(house1);
  }

  visited.reset();
  DepthFirstSearch(1, n);

  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[i] == 0) {
      count++;
      printf("%d \n", i);
    }
  }

  if (count == 0) puts("Connected");

  return 0;
}