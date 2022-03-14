#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, m;
	cin >> t;

	while (t--) {
		cin >> n;
		map<int, int> test;   // map<key, value>
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			test[num] = 1;  
		cin >> m;
		for (int i = 0; i < m; i++) {
			int num;
			cin >> num;
			if (test[num] == 1)
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
	return 0;
}