#include <iostream>
#include <string>
using namespace std;

string rotate(string g, int i) {
	if (i == 1) {
		return g.substr(7, 1) + g.substr(0, 7);
	}
	else if (i == -1) {
		return g.substr(1, 8) + g.substr(0, 1);
	}
	else {
		return g;
	}
}

bool is_rotate(string left, string right) {
	if (left[2] != right[6]) {
		return true;
	}
	else {
		return false;
	}
}

string g[5];
int rr[5];

int main() {
	int t;
	int ans_count = 1;
	cin >> t;
	while (t--) {
		int temp, k;
		cin >> k;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> temp;
				g[i] += to_string(temp);
			}
		}
		while (k--) {
			int s, r;
			cin >> s >> r;
			for (int i = 0; i < 4; i++) {
				rr[i] = 0;
			}
			s--;
			rr[s] = r;
			for (int i = s - 1; i >= 0; i--) {
				if (is_rotate(g[i], g[i + 1])) {
					rr[i] = ((s - i) % 2 == 1 ? -1 : 1) * r;
					rr[i + 1] = ((s - i + 1) % 2 == 1 ? -1 : 1) * r;
				}
				else {
					break;
				}
			}
			for (int j = s + 1; j < 4; j++) {
				if (is_rotate(g[j - 1], g[j])) {
					rr[j] = ((j - s) % 2 == 1 ? -1 : 1) * r;
					rr[j - 1] = ((j - 1 - s) % 2 == 1 ? -1 : 1) * r;
				}
				else {
					break;
				}
			}
			for (int i = 0; i < 4; i++) {
				g[i] = rotate(g[i], rr[i]);
			}
		}
		int ans = 0;
		for (int i = 0; i < 4; i++) {
			if (g[i][0] == '1') {
				ans += (1 << i);
			}
			g[i].clear();
		}
		cout << '#' << ans_count++ << ' ' << ans << '\n';;
	}
}