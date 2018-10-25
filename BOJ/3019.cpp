// https://www.acmicpc.net/problem/3019
#include <iostream>
#include <string>
using namespace std;

int n, b;
int height[1011];

int isfixed(string s, int col) {
	if (col + s.size() - 1> n) {
		return 0;
	}
	int base = height[col] - (s[0] - '0');
	for (int i = 0; i < s.size(); i++) {
		if (base != height[col + i] - (s[i] - '0')) {
			return 0;
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> b;
	for (int j = 1; j <= n; j++) {
		int col;
		cin >> col;
		height[j] = col;
	}
	int ans = 0;
	// col
	for (int j = 1; j <= n; j++) {
		if (b == 1) {
			ans += isfixed("0", j) + isfixed("0000", j);
		} else if (b == 2) {
			ans += isfixed("00", j);
		} else if (b == 3){
			ans += isfixed("001", j) + isfixed("10", j);
		} else if (b == 4) {
			ans += isfixed("100", j) + isfixed("01", j);
		} else if (b == 5) {
			ans += isfixed("000", j) + isfixed("01", j) + isfixed("101", j) + isfixed("10", j);
		} else if (b == 6) {
			ans += isfixed("000", j) + isfixed("00", j) + isfixed("011", j) + isfixed("20", j);
		} else if (b == 7) {
			ans += isfixed("000", j) + isfixed("02", j) + isfixed("110", j) + isfixed("00", j);
		}
	}
	
	cout << ans << '\n';
	return 0;
}