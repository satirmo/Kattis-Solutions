#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

int n, m;
int mov[ 4 ][ 2 ] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
string a[ maxn ];

void floodFill( int x, int y ){
	a[ x ][ y ] = '#';

	for( int i = 0; i < 4; i++ ){
		int nx = x + mov[ i ][ 0 ];
		int ny = y + mov[ i ][ 1 ];

		if( nx < 0 || nx == n || ny < 0 || ny == m ){
			continue;
		}

		if( a[ nx ][ ny ] == '#' ){
			continue;
		}

		floodFill( nx, ny );
	}
}

int main(){
	for( int t = 1; cin >> n >> m; t++ ){
		cin.ignore();

		for( int i = 0; i < n; i++ ){
			cin >> a[ i ];
		}

		int ans = 0;
		for( int i = 0; i < n; i++ ){
			for( int j = 0; j < m; j++ ){
				if( a[ i ][ j ] == '-' ){
					ans++;
					floodFill( i, j );
				}
			}
		}

		printf( "Case %d: %d\n", t, ans );
	}
	return 0;
}