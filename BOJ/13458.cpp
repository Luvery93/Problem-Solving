#include <iostream>
using namespace std;

int c[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	cin >> a >> b;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		c[i] -= a;
		ans++;
		if (c[i] > 0) {
			ans += c[i] / b;
			ans += c[i] % b != 0 ? 1 : 0;
		}
	}
	cout << ans << '\n';
	return 0;
}