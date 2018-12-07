#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;

const int maxn = 1005;
const int maxq = 100005;
const int mov[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int G[maxn][maxn];
vector<iiii> queries;

int par[maxn * maxn];
set<int> parents;
vector<int> anss;

int Find(int x) {
  while (x != par[x]) {
    int &p = par[x];

    p = par[p];
    x = par[p];
  }

  return x;
}

void Unite(int x, int y) {
  int sx = Find(x);
  int sy = Find(y);

  par[sx] = sy;

  if (sx != sy) {
    parents.erase(sx);
  }
}

void AddCellToSet(int x, int y, int m) {
  int idx = x * m + y;

  par[idx] = idx;
  parents.insert(idx);

  // printf( "adding cell %3d %3d, idx = %3d\n", x, y, idx );
}

bool IsValid(int x, int y, int n, int m) {
  return (0 <= x && x < n && 0 <= y && y < m);
}

void UniteAdjacentCells(int x, int y, int n, int m) {
  for (int k = 0; k < 4; k++) {
    int nx = x + mov[k][0];
    int ny = y + mov[k][1];

    if (IsValid(nx, ny, n, m) == false) {
      continue;
    }

    if (G[nx][ny] != 0) {
      continue;
    }

    int idx = x * m + y;
    int nidx = nx * m + ny;

    if (par[idx] == -1 || par[nidx] == -1) {
      continue;
    }

    // printf( "\tattempting to unite %3d %3d  (%3d) and %3d %3d (%3d)\n", x, y,
    // idx, nx, ny, nidx );

    Unite(idx, nidx);
  }
}

int main() {
  int n, m, q;
  cin >> m >> n >> q;

  for (int i = 0; i < q; i++) {
    int ax, ay, bx, by;
    scanf("%d %d %d %d", &ay, &ax, &by, &bx);

    ax--;
    ay--;
    bx--;
    by--;

    if (ax == bx) {
      int x = ax;

      for (int y = ay; y <= by; y++) {
        G[x][y]++;
        // printf( "coloring %3d %3d\n", x+1, y+1 );
      }
    }

    else {
      int y = ay;

      for (int x = ax; x <= bx; x++) {
        G[x][y]++;
        // printf( "coloring %3d %3d\n", x+1, y+1 );
      }
    }

    if (i > 0) {
      queries.push_back(iiii(ii(ax, ay), ii(bx, by)));
    }
  }

  reverse(queries.begin(), queries.end());
  memset(par, -1, sizeof par);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (G[i][j] != 0) {
        continue;
      }

      AddCellToSet(i, j, m);
      UniteAdjacentCells(i, j, n, m);
    }
  }

  // for( int i = 0; i < n; i++ ){
  // 	for( int j = 0; j < m; j++ ){
  // 		printf( "%3d", G[ i ][ j ] );
  // 	}
  // 	puts( "" );
  // }

  anss.push_back(parents.size());

  for (iiii query : queries) {
    int ax = query.first.first;
    int ay = query.first.second;
    int bx = query.second.first;
    int by = query.second.second;

    // printf( "parents before:" );
    // for( int x : parents ){
    // 	cout << " " << x;
    // }
    // puts( "" );

    if (ax == bx) {
      int x = ax;

      for (int y = ay; y <= by; y++) {
        G[x][y]--;
        // printf( "unpainting %3d %3d\n", x, y );

        if (G[x][y] == 0) {
          AddCellToSet(x, y, m);
          UniteAdjacentCells(x, y, n, m);
        }
      }
    }

    else {
      int y = ay;

      for (int x = ax; x <= bx; x++) {
        G[x][y]--;
        // printf( "unpainting %3d %3d\n", x, y );

        if (G[x][y] == 0) {
          AddCellToSet(x, y, m);
          UniteAdjacentCells(x, y, n, m);
        }
      }
    }

    anss.push_back(parents.size());

    // printf( "parents after:" );
    // for( int x : parents ){
    // 	cout << " " << x;
    // }
    // puts( "" );

    // for( int i = 0; i < n; i++ ){
    // 	for( int j = 0; j < m; j++ ){
    // 		printf( "%3d", G[ i ][ j ] );
    // 	}
    // 	puts( "" );
    // }
    // puts( "---------------------" );
  }

  reverse(anss.begin(), anss.end());

  for (int ans : anss) {
    printf("%d\n", ans);
  }

  return 0;
}