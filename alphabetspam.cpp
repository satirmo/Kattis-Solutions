#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;

	while( cin >> s ){
		int whitespace = 0;
		int lowercase = 0;
		int uppercase = 0;
		int symbol = 0;

		for( char c : s ){
			if( c == '_' ){
				whitespace++;
			}

			else if( islower( c ) ){
				lowercase++;
			}

			else if( isupper( c ) ){
				uppercase++;
			}

			else{
				symbol++;
			}
		}

		int total = s.size();

		printf( "%.10lf\n", (double) whitespace / total );
		printf( "%.10lf\n", (double) lowercase / total );
		printf( "%.10lf\n", (double) uppercase / total );
		printf( "%.10lf\n", (double) symbol / total );
	}

	return 0;
}