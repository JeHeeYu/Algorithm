#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, n, m, sum = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> a;
			if (a >= sum) {
				sum = a;
				n = i;
				m = j;
			}
		}
	}
	cout << sum << endl << n << ' ' << m << endl;
}