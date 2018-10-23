// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int> > h;
vector<pair<int, int> > c;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int temp = 0;
			cin >> temp;
			if (temp == 2) {
				c.push_back(make_pair(i, j));
			}
			else if (temp == 1) {
				h.push_back(make_pair(i, j));
			}
		}
	}

	int ans = 987654321;
	for (int k = 1; k <= m; k++) {
		vector<int> v;
		for (int l = 0; l < k; l++) {
			v.push_back(1);
		}
		for (int l = k; l < c.size(); l++) {
			v.push_back(0);
		}
		do {
			int min_sum = 0;
			for (int i = 0; i < h.size(); i++) {
				int min_distance = 987654321;
				for (int j = 0; j < c.size(); j++) {
					if (v[j] == 1) {
						int x = h[i].first - c[j].first;
						int y = h[i].second - c[j].second;
						int temp_distance = (x > 0 ? x : -x) + (y > 0 ? y : -y);
						min_distance = min(min_distance, temp_distance);
					}
				}
				min_sum += min_distance;
			}
			ans = min(ans, min_sum);
		} while (prev_permutation(v.begin(), v.end()));
		v.clear();
	}

	cout << ans << '\n';
	return 0;
}