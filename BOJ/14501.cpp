#include <iostream>
#include <algorithm>
using namespace std;

int t[16];
int p[16];
int d[16 + 5];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
		d[i + 1] = max(d[i + 1], d[i]);
	}
	cout << d[n + 1] << '\n';
	return 0;
}