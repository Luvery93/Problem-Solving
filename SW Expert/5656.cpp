#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int t, n, w, h;
int map[21][21];
int test_map[21][21];

void del_two(int x, int y) {
	int del = 0;
	if (test_map[x][y] != 0) {
		del = test_map[x][y] - 1;
		test_map[x][y] = 0;
	}
	// horizontal
	int temp = del;
	for (int c = y - 1; c >= 1 && temp > 0; c--) {
		del_two(x, c);
		temp--;
	}
	temp = del;
	for (int c = y + 1; c <= w && temp > 0; c++) {
		del_two(x, c);
		temp--;
	}
	// vertical
	temp = del;
	for (int r = x - 1; r >= 1 && temp > 0; r--) {
		del_two(r, y);
		temp--;
	}
	temp = del;
	for (int r = x + 1; r <= h && temp > 0; r++) {
		del_two(r, y);
		temp--;
	}
}

void del_col(int j) {
	int x = -1;
	int del = 0;
	for (int r = 1; r <= h; r++) {
		if (test_map[r][j] != 0) {
			del = test_map[r][j] - 1;
			x = r;
			test_map[r][j] = 0;
			break;
		}
	}
	if (x != -1 && del != 0) {
		// horizontal
		int temp = del;
		for (int c = j - 1; c >= 1 && temp > 0; c--) {
			del_two(x, c);
			temp--;
		}
		temp = del;
		for (int c = j + 1; c <= w && temp > 0; c++) {
			del_two(x, c);
			temp--;
		}
		// vertical
		temp = del;
		for (int r = x - 1; r >= 1 && temp > 0; r--) {
			del_two(r, j);
			temp--;
		}
		temp = del;
		for (int r = x + 1; r <= h && temp > 0; r++) {
			del_two(r, j);
			temp--;
		}
	}
}


void down() {
	for (int c = 1; c <= w; c++) {
		int last_zero = -1;
		for (int r = h; r >= 1; r--) {
			if (test_map[r][c] == 0) {
				last_zero = r;
				break;
			}
		}
		bool pull = false;
		for (int r = last_zero - 1; r >= 1; r--) {
			if (test_map[r][c] != 0) {
				pull = true;
			}
		}
		if (pull) {
			for (int r = h; r >= 1; r--) {
				if (test_map[r][c] != 0 && r < last_zero) {
					test_map[last_zero][c] = test_map[r][c];
					test_map[r][c] = 0;
					break;
				}
			}
			c--;
		}
	}
}

int simulate(int i, int j, int k, int l) {
	memcpy(test_map, map, sizeof(map));
	if (i != 0) {
		del_col(i);
		down();
	}
	if (j != 0) {
		del_col(j);
		down();
	}
	if (k != 0) {
		del_col(k);
		down();
	}
	if (l != 0) {
		del_col(l);
		down();
	}
	int ans = 0;
	for (int r = 1; r <= h; r++) {
		for (int c = 1; c <= w; c++) {
			if (test_map[r][c] != 0) {
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	int count = 1;
	while (t--) {
		cin >> n >> w >> h;
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> map[i][j];
			}
		}
		int ans = 987654321;
		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= w; j++) {
				for (int k = 1; k <= w; k++) {
					for (int l = 1; l <= w; l++) {
						if (ans == 0) {
							break;
						}
						if (n == 1) {
							j = w + 1;
							k = w + 1;
							l = w + 1;
							ans = min(ans, simulate(i, 0, 0, 0));
						} else if (n == 2) {
							k = w + 1;
							l = w + 1;
							ans = min(ans, simulate(i, j, 0, 0));
						} else if (n == 3) {
							l = w + 1;
							ans = min(ans, simulate(i, j, k, 0));
						} else if (n == 4) {
							ans = min(ans, simulate(i, j, k, l));
						}
					}
				}
			}
		}
		cout << '#' << count++ << ' ' << ans << '\n';
	}
	return 0;
}