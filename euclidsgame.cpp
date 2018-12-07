#include <bits/stdc++.h>

using namespace std;

bool Wins(long long a, long long b) {
	if (a < b) {
		return Wins(b, a);
	}

	if (b == 0) {
		return false;
	}

	if (a / b == 1LL) {
		return !Wins(a - b, b);
	}

	return true;
}

int main() {
	long long a, b;

	while (cin >> a >> b) {
		if (a == 0LL && b == 0LL) {
			break;
		}

		if (Wins(a, b)) {
			puts("Stan wins");
		}

		else {
			puts("Ollie wins");
		}
	}
}