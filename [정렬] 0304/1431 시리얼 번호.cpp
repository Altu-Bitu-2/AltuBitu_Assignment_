#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool cmp(string a, string b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}
	else {
		int sum_a = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] - '0' <= 9 && a[i] - '0' >= 0) {
				sum_a += a[i] - '0';
			}
		}
		int sum_b = 0;
		for (int i = 0; i < a.size(); i++) {
			if (b[i] - '0' <= 9 && b[i] - '0' >= 0) {
				sum_b += b[i] - '0';
			}
		}
		if (sum_a != sum_b) {
			return sum_a < sum_b;
		}
		else {
			return a < b;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<string> v;
	int n;
	string s;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}