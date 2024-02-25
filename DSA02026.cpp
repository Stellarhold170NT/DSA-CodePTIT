#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 200

#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

string s;
char operation[2] = { '+' , '-' };
string ans = "";
bool flag = false;

void check(string s) {
	int a = stoi(s.substr(0, 2));
	int b = stoi(s.substr(5, 2));
	string c = s.substr(10, 2);

	if ((s[3] == '+' && to_string(a + b) == c) || (s[3] == '-' && to_string(a - b) == c)) {
		ans = s;
		flag = true;
	}
}

void Try(int i, string s) {
	if (flag) return;
	if (s[i] == '?') {
		if (i == 3) {
			for (int j = 0; j <= 1; j++) {
				s[i] = operation[j];
				if (i == s.length() - 1) check(s);
				else Try(i + 1, s);
			}
		}
		else if (i == 0 || i == 5 || i == 10) {
			for (char j = '1'; j <= '9'; j++) {
				s[i] = j;
				if (i == s.length() - 1) check(s);
				else Try(i + 1, s);
			}
		}
		else {
			for (char j = '0'; j <= '9'; j++) {
				s[i] = j;
				if (i == s.length() - 1) check(s);
				else Try(i + 1, s);
			}
		}
	}
	else {
		if (i == s.length() - 1) check(s);
		else Try(i + 1, s);
	}
}

int main() {
	int t;
	cin >> t;

	cin.ignore();

	while (t--) {
		getline(cin, s);
		flag = false;

		if (s[3] == '*' || s[3] == '/') {
			cout << "WRONG PROBLEM!" << endl;
		}
		else {
			Try(0, s);
			if (flag)
				cout << ans << endl;
			else cout << "WRONG PROBLEM!" << endl;
		}
	}

	return 0;
}