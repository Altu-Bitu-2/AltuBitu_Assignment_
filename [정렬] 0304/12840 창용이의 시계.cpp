#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int h, m, s, q;
	int t, T, c;

	cin >> h >> m >> s;
	cin >> q;

	t = 3600 * h + 60 * m + s;

	for (int i = 0; i < q; i++) {
		cin >> T;
		if (T == 1) {
			cin >> c;
			t = (t + c) % 86400;
		}
		else if (T == 2) {
			cin >> c;
			t = (t - c) % 86400;
			if (t < 0) {
				t += 86400;
			}
		}
		else {
			cout << t / 3600 << ' ' << (t / 60) % 60 << ' ' << t % 60 << '\n';
		}
	}
}