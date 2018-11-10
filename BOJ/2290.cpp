#include<iostream>
#include<string>
using namespace std;

int view[11][5][3] = {
{ {0,1,0}, {1,0,1}, {0,0,0}, {1,0,1}, {0,1,0} },
{ {0,0,0}, {0,0,1}, {0,0,0}, {0,0,1}, {0,0,0} },
{ {0,1,0}, {0,0,1}, {0,1,0}, {1,0,0}, {0,1,0} },
{ {0,1,0}, {0,0,1}, {0,1,0}, {0,0,1}, {0,1,0} },
{ {0,0,0}, {1,0,1}, {0,1,0}, {0,0,1}, {0,0,0} },
{ {0,1,0}, {1,0,0}, {0,1,0}, {0,0,1}, {0,1,0} },
{ {0,1,0}, {1,0,0}, {0,1,0}, {1,0,1}, {0,1,0} },
{ {0,1,0}, {0,0,1}, {0,0,0}, {0,0,1}, {0,0,0} },
{ {0,1,0}, {1,0,1}, {0,1,0}, {1,0,1}, {0,1,0} },
{ {0,1,0}, {1,0,1}, {0,1,0}, {0,0,1}, {0,1,0} },
};

int main() {
	ios::sync_with_stdio(false);
	int s;
	string digit;
	cin >> s >> digit;

	for (int r = 0; r < 5; r++) {
		if (r % 2 == 0) {
			for (int i = 0; i < digit.size(); i++) {
				int d = digit[i] - '0';
				cout << ' ';
				for (int j = 0; j < s; j++) {
					cout << (view[d][r][1] == 1 ? '-' : ' ');
				}
				cout << ' ';
				cout << (i == digit.size() - 1 ? '\n' : ' ');
			}
		} else {
			for (int k = 0; k < s; k++) {
				for (int i = 0; i < digit.size(); i++) {
					int d = digit[i] - '0';
					cout << (view[d][r][0] == 1 ? '|' : ' ');
					for (int j = 0; j < s; j++) {
						cout << ' ';
					}
					cout << (view[d][r][2] == 1 ? '|' : ' ');
					cout << ' ';
				}
				cout << '\n';
			}
		}
	}

	return 0;
}