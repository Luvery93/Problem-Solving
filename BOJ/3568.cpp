#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string base;
	cin >> base;
	while (true) {
		string next;
		cin >> next;
		string value = "";
		string type = "";
		bool isend = false;
		bool isvalue = true;
		for (int i = 0; i < next.size(); i++) {
			if (isvalue == true) {
				if ((next[i] - '0' >= 'a' - '0' && next[i] - '0' <= 'z' - '0')
					|| (next[i] - '0' >= 'A' - '0' && next[i] - '0' <= 'Z' - '0')) {
					value += next[i];
				}
				else {
					isvalue = false;
					i--;
				}
			}
			else {
				if (next[i] == '[') {
					type += ']';
				}
				else if (next[i] == ']') {
					type += '[';
				}
				else if (next[i] == ',') {
					break;
				}
				else if (next[i] == ';') {
					isend = true;
				}
				else {
					type += next[i];
				}
			}
		}
		reverse(type.begin(), type.end());
		cout << base << type << ' ' << value << ";\n";
		if (isend == true) {
			break;
		}
	}
	return 0;
}