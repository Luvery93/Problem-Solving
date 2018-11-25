#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

char map[11][11];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	int rx, ry, bx, by, gx, gy;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				rx = i;
				ry = j;
			} else if ( map[i][j] == 'B' ){
				bx = i;
				by = j;
			} else if (map[i][j] == 'O') {
				gx = i;
				gy = j;
			}
		}
	}

	int ans = -1;
	queue<tuple<int, int, int, int, int>> q;
	q.push(make_tuple( rx, ry, bx, by, 1 ));
	while (!q.empty()) {
		int crx = get<0>(q.front());
		int cry = get<1>(q.front());
		int cbx = get<2>(q.front());
		int cby = get<3>(q.front());
		int count = get<4>(q.front());
		q.pop();
		if (count > 10) {
			ans = -1;
			break;
		}
		bool isAnswer = false;
		for (int k = 0; k < 4; k++) {
			int ncrx = crx + dx[k];
			int ncry = cry + dy[k];
			int ncbx = cbx + dx[k];
			int ncby = cby + dy[k];

			bool isRholl = false;
			bool isBholl = false;
			bool redfirst = false;

			if (k == 0 && crx < cbx) {
				redfirst = true;
			} else if (k == 1 && crx > cbx) {
				redfirst = true;
			} else if ( k == 2 && cry < cby ){
				redfirst = true;
			} else if (k == 3 && cry > cby) {
				redfirst = true;
			}

			map[crx][cry] = 'R';
			map[cbx][cby] = 'B';
			if (redfirst) {
				if (map[ncrx][ncry] == '.') {
					while (map[ncrx][ncry] == '.') {
						ncrx += dx[k];
						ncry += dy[k];
						if (map[ncrx][ncry] == 'O') {
							isRholl = true;
							break;
						}
					}
					if (isRholl) {
						map[crx][cry] = '.';
					} else {
						ncrx -= dx[k];
						ncry -= dy[k];
						map[crx][cry] = '.';
						map[ncrx][ncry] = 'R';
					}
				} else if (map[ncrx][ncry] == 'O') {
					isRholl = true;
					map[crx][cry] = '.';
				} else {
					ncrx = crx;
					ncry = cry;
				}

				if (map[ncbx][ncby] == '.') {
					while (map[ncbx][ncby] == '.') {
						ncbx += dx[k];
						ncby += dy[k];
						if (map[ncbx][ncby] == 'O') {
							isBholl = true;
							break;
						}
					}
					if (isBholl) {
						map[cbx][cby] = '.';
					} else {
						ncbx -= dx[k];
						ncby -= dy[k];
						map[cbx][cby] = '.';
						map[ncbx][ncby] = 'B';
					}
				} else if (map[ncbx][ncby] == 'O') {
					isBholl = true;
					map[cbx][cby] = '.';
				} else {
					ncbx = cbx;
					ncby = cby;
				}
			} else {
				if (map[ncbx][ncby] == '.') {
					while (map[ncbx][ncby] == '.') {
						ncbx += dx[k];
						ncby += dy[k];
						if (map[ncbx][ncby] == 'O') {
							isBholl = true;
							break;
						}
					}
					if (isBholl) {
						map[cbx][cby] = '.';
					} else {
						ncbx -= dx[k];
						ncby -= dy[k];
						map[cbx][cby] = '.';
						map[ncbx][ncby] = 'B';
					}
				} else if (map[ncbx][ncby] == 'O') {
					isBholl = true;
					map[cbx][cby] = '.';
				} else {
					ncbx = cbx;
					ncby = cby;
				}

				if (map[ncrx][ncry] == '.') {
					while (map[ncrx][ncry] == '.') {
						ncrx += dx[k];
						ncry += dy[k];
						if (map[ncrx][ncry] == 'O') {
							isRholl = true;
							break;
						}
					}
					if (isRholl) {
						map[crx][cry] = '.';
					} else {
						ncrx -= dx[k];
						ncry -= dy[k];
						map[crx][cry] = '.';
						map[ncrx][ncry] = 'R';
					}
				} else if (map[ncrx][ncry] == 'O') {
					isRholl = true;
					map[crx][cry] = '.';
				} else {
					ncrx = crx;
					ncry = cry;
				}
			}

			/*if (!isRholl && !isBholl) {
				if (ncrx != crx || ncry != cry || ncbx != cbx || ncby != cby) {
					cout << "=====================================\n";
					cout << count << '\n';
					cout << "red : " << crx << ',' << cry << " to " << ncrx << ',' << ncry << '\n';
					cout << "blue : " << cbx << ',' << cby << " to " << ncbx << ',' << ncby << '\n';
					for (int i = 1; i <= n; i++) {
						for (int j = 1; j <= m; j++) {
							cout << map[i][j];
						}
						cout << '\n';
					}
					cout << "=====================================\n";
				}
			}*/

			if (isRholl && !isBholl) {
				ans = count;
				isAnswer = true;
				break;
			} else if (!isRholl && !isBholl) {
				if (ncrx != crx || ncry != cry || ncbx != cbx || ncby != cby) {
					q.push(make_tuple(ncrx, ncry, ncbx, ncby, count + 1));
				}
			}

			map[ncrx][ncry] = '.';
			map[ncbx][ncby] = '.';
			map[crx][cry] = '.';
			map[cbx][cby] = '.';
			map[gx][gy] = 'O';
		}
		if (isAnswer) {
			break;
		}
	}

	cout << ans << '\n';
	return 0;
}