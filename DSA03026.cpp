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
#define N 600000

#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)
#define endl "\n"

bool inRange(int x, int n) {
	if (x >= 0 && x <= 9 * n) return true;
	return false;
}

string find_max(int n, int s) {
	string res = "";

	for (int i = 1; i <= n; i++) {
		if (s == 0) {
			res = res + "0";
			continue;
		}
		for (int digit = 9; digit >= 0; digit--) {
			if (inRange(s - digit, n - i)) {
				s -= digit;
				res = res + to_string(digit);
				break;
			}
		}
	}

	return res;
}

string find_min(int n, int s) {
	string res = "";

	for (int digit = 1; digit <= 9; digit++) {
		if (inRange(s - digit, n - 1)) {
			res = res + to_string(digit);
			string tmp = find_max(n - 1, s - digit);
			reverse(tmp.begin(), tmp.end());
			res = res + tmp;
			break;
		}
	}
	return res;
}

int main() {
	int n, s;
	cin >> n >> s;

	if (s != 0 && inRange(s, n)) {
		cout << find_min(n, s) << " " << find_max(n, s) << endl;
	}
	else {
		cout << -1 << " " << -1 << endl;
	}

	return 0;
}