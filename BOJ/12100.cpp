#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int map[21][21];
int n;

int calc(int c) {
	if (c == 5) {
		int m = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (m < map[i][j]) {
					m = map[i][j];
				}
			}
		}
		return m;
	}
	int m = 0;
	int cpmap[21][21];
	memcpy(cpmap, map, sizeof(map));
	// up
	for (int j = 1; j <= n; j++) {
		int base = 1;
		for (int i = base + 1; i <= n; i++) {
			if (map[i][j] == 0) {
				continue;
			} else {
				if (map[base][j] == map[i][j]) {
					map[base][j] += map[i][j];
					map[i][j] = 0;
					base = i + 1;
					i++;
				} else {
					base = i;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			bool repeat = true;
			if (map[i][j] == 0) {
				int diff = 0;
				for (int k = i + 1; k <= n; k++) {
					if (map[k][j] != 0) {
						diff = k - i;
						break;
					}
				}
				if (diff == 0) {
					repeat = false;
				} else {
					for (int k = i; k <= n - diff; k++) {
						map[k][j] = map[k + diff][j];
						map[k + diff][j] = 0;
					}
				}
			}
			if (!repeat) {
				break;
			}
		}
	}

	//cout << "======================================\n";
	//cout << "count : " << c << ' ' << "up" << '\n';
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		cout << map[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	//cout << "======================================\n";
	m = max(m, calc(c + 1));
	memcpy(map, cpmap, sizeof(map));
	// down
	for (int j = 1; j <= n; j++) {
		int base = n;
		for (int i = base - 1; i >= 1; i--) {
			if (map[i][j] == 0) {
				continue;
			} else {
				if (map[base][j] == map[i][j]) {
					map[base][j] += map[i][j];
					map[i][j] = 0;
					base = i - 1;
					i--;
				} else {
					base = i;
				}
			}
		}
		for (int i = n; i >= 1; i--) {
			bool repeat = true;
			if (map[i][j] == 0) {
				int diff = 0;
				for (int k = i - 1; k >= 1; k--) {
					if (map[k][j] != 0) {
						diff = i - k;
						break;
					}
				}
				if (diff == 0) {
					repeat = false;
				} else {
					for (int k = i; k >= 1 + diff; k--) {
						map[k][j] = map[k - diff][j];
						map[k - diff][j] = 0;
					}
				}
			}
			if (!repeat) {
				break;
			}
		}
	}

	//cout << "======================================\n";
	//cout << "count : " << c << ' ' << "down" << '\n';
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		cout << map[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	//cout << "======================================\n";
	m = max(m, calc(c + 1));
	memcpy(map, cpmap, sizeof(map));
	// left
	for (int i = 1; i <= n; i++) {
		int base = 1;
		for (int j = base + 1; j <= n; j++) {
			if (map[i][j] == 0) {
				continue;
			} else {
				if (map[i][base] == map[i][j]) {
					map[i][base] += map[i][j];
					map[i][j] = 0;
					base = j + 1;
					j++;
				} else {
					base = j;
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			bool repeat = true;
			if (map[i][j] == 0) {
				int diff = 0;
				for (int k = j + 1; k <= n; k++) {
					if (map[i][k] != 0) {
						diff = k - j;
						break;
					}
				}
				if (diff == 0) {
					repeat = false;
				} else {
					for (int k = j; k <= n - diff; k++) {
						map[i][k] = map[i][k + diff];
						map[i][k + diff] = 0;
					}
				}
			}
			if (!repeat) {
				break;
			}
		}
	}

	//cout << "======================================\n";
	//cout << "count : " << c << ' ' << "left" << '\n';
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		cout << map[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	//cout << "======================================\n";
	m = max(m, calc(c + 1));
	memcpy(map, cpmap, sizeof(map));
	// right
	for (int i = 1; i <= n; i++) {
		int base = n;
		for (int j = base - 1; j >= 1; j--) {
			if (map[i][j] == 0) {
				continue;
			} else {
				if (map[i][base] == map[i][j]) {
					map[i][base] += map[i][j];
					map[i][j] = 0;
					base = j - 1;
					j--;
				} else {
					base = j;
				}
			}
		}
		for (int j = n; j >= 1; j--) {
			bool repeat = true;
			if (map[i][j] == 0) {
				int diff = 0;
				for (int k = j - 1; k >= 1; k--) {
					if (map[i][k] != 0) {
						diff = j - k;
						break;
					}
				}
				if (diff == 0) {
					repeat = false;
				} else {
					for (int k = j; k >= 1 + diff; k--) {
						map[i][k] = map[i][k - diff];
						map[i][k - diff] = 0;
					}
				}
			}
			if (!repeat) {
				break;
			}
		}
	}

	//cout << "======================================\n";
	//cout << "count : " << c << ' ' << "right" << '\n';
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		cout << map[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	//cout << "======================================\n";
	m = max(m, calc(c + 1));
	return m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	int ans = calc(0);

	cout << ans << '\n';
	return 0;
}