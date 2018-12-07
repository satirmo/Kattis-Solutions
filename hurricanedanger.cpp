#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
const double eps = 1e-9;
const double inf = 1e20;

struct City{
	long long x, y;
	string name;

	City( int x, int y, string name ) : x( x ), y( y ), name( name ){

	}
};

vector < City > cities;
vector < string > ans;

void FindClosestCitiesParallel( int component, int x ){
	long long minn = 1LL << 60;

	for( City c : cities ){
		long long x1 = ( component == 0 ) ? c.x : c.y;
		long long dx = abs( x - x1 );

		if( minn > dx ){
			minn = dx;
			ans.clear();
		}

		if( minn == dx ){
			ans.push_back( c.name );
		}
		// printf( "checking %3d City: %s, dist = %lld\n", component, c.name.c_str(), dx );
	}
}

void FindClosestCities( int x1, int y1, int x2, int y2 ){
	if( x1 == x2 ){
		FindClosestCitiesParallel( 0, x1 );
		return;
	}

	if( y1 == y2 ){
		FindClosestCitiesParallel( 1, y1 );
		return;
	}

	double minn = inf;

	long long dx = x1 - x2;
	long long dy = y1 - y2;

	long long a = dy;
	long long b = - dx;
	long long c = dx * y1 - dy * x1;

	for( City it : cities ){
		double num = (double) abs( a * it.x + b * it.y + c );
		double den = hypot( a, b );
		double dist = num / den;

		if( dist < minn ){
			minn = dist;
			ans.clear();
		}

		if( abs( dist - minn ) < eps ){
			ans.push_back( it.name );
		}
	}

	/*
	double dx = (double) x1 - x2;
	double dy = (double) y1 - y2;
	double hx = x1;
	double hy = y1;
	double hm = dy / dx;
	double cm = - dx / dy;

	for( City c : cities ){
		double cx = c.x;
		double cy = c.y;
		string cname = c.name;

		double num = hm * hx - cm * cx - hy + cy;
		double den = hm - cm;

		double ix = 
	}
	*/
}

int main(){
	int test;
	cin >> test;

	while( test-- ){
		cities.clear();
		ans.clear();

		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int n;
		cin >> n;

		for( int i = 0; i < n; i++ ){
			int x, y;
			string name;

			cin.ignore();
			cin >> name >> x >> y;

			cities.push_back( City( x, y, name ) );
		}

		FindClosestCities( x1, y1, x2, y2 );

		bool space = false;

		for( string name : ans ){
			if( space ){
				printf( " " );
			}

			space = true;
			cout << name;
		}

		cout << endl;
	}

	return 0;
}