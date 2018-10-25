// https://www.acmicpc.net/problem/2210
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int map[6][6];
vector<string> ans;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void route(string s, int x, int y) {
	s += map[x][y] + '0';
	if (s.size() == 6) {
		ans.push_back(s);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= 5 && ny >= 1 && ny <= 5) {
			route(s, nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			route("", i, j);
		}
	}

	sort(ans.begin(), ans.end());
	vector<string>::iterator iter;
	iter = unique(ans.begin(), ans.end());
	ans.erase(iter, ans.end());

	cout << ans.size() << '\n';
	return 0;
}