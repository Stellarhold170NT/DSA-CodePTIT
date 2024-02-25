#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
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

int n;
string tmp = "";
vector<string> label;
vector<string> id;
int dd[1000] = { 0 };

void Try2(int i) {
	for (int j = 1; j <= n; j++) {
		tmp += to_string(j);
		if (i == n) {
			id.push_back(tmp);
		}
		else Try2(i + 1);
		tmp.pop_back();
	}
}

void Try1(int i) {
	for (int c = 'A'; c <= 'A' + n - 1; c++)
		if (!dd[c]) {
			dd[c] = 1;
			tmp += c;
			if (i == n) {
				label.push_back(tmp);
			}
			else Try1(i + 1);
			tmp.pop_back();
			dd[c] = 0;
		}
}
int main() {
	cin >> n;

	Try1(1);
	Try2(1);

	for (auto x : label) {
		for (auto y : id) {
			cout << x << y << endl;
		}
	}

	return 0;
}