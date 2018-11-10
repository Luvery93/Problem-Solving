#include <iostream>
#include <algorithm>
using namespace std;

bool check[201][201];

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int first, second;
		cin >> first >> second;
		if (first > second) {
			swap(first, second);
		}
		check[first][second] = true;
	}

	long long ans = 0;
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (check[i][j] != true && check[j][k] != true && check[i][k] != true) {
					ans++;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}