#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, t, tip;
	long long max = 0;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}

	sort(v.rbegin(), v.rend());

	for (int i = 0; i < n; i++) {
		tip = v[i] - ((i + 1) - 1);
		if (tip < 0) {
			tip = 0;
		}
		max += tip;
	}

	cout << max;
}