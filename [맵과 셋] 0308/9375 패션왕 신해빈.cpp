#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int num;
		string name, cloth;

		map<string, int> m;
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> name >> cloth;

			if (m.find(cloth) == m.end()) {
				m.insert({ cloth, 1 });
			}
			else
				m[cloth]++;  
		}

		int ans = 1;
		for (auto i : m) {
			ans *= (i.second + 1);  
		}
		ans -= 1;
		cout << ans << '\n';
	}
	return 0;
}