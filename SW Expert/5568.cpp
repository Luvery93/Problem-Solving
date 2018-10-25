#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int getDec(char c, int index, int max) {
	int t = 1;
	for (int i = index; i < max - 1; i++) {
		t *= 16;
	}
	if (c == 'F') {
		return 15 * t;
	} else if (c == 'E') {
		return 14 * t;
	} else if (c == 'D') {
		return 13 * t;
	} else if (c == 'C') {
		return 12 * t;
	} else if (c == 'B') {
		return 11 * t;
	} else if (c == 'A') {
		return 10 * t;
	} else {
		return (c - '0') * t;
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t, n, k;
	string s;
	cin >> t;
	int ans = 1;
	while (t--) {
		vector<int> v;
		cin >> n >> k;
		cin >> s;
		int cut = n / 4;
		int group = n / cut;
		for (int k = 0; k < cut; k++) {
			vector<int> cutted(group);
			for (int i = 0; i < group; i++) {
				for (int j = 0; j < cut; j++) {
					cutted[i] += getDec(s[j + cut * i], j, cut);
				}
			}
			for (int i = 0; i < group; i++) {
				v.push_back(cutted[i]);
			}
			s = s.substr(s.size() - 1, 1) + s.substr(0, s.size() - 1);
		}
		vector<int>::iterator new_end;
		sort(v.begin(), v.end(), greater<int>());
		new_end = unique(v.begin(), v.end());
		v.erase(new_end, v.end());
		cout << '#' << ans++ << ' ' << v[k - 1] << '\n';
	}

	return 0;
}