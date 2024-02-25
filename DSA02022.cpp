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

//#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int x[10] = { 0 };
vector<string> res;

void check() {
	string s1 = "";
	for (int i = 1; i <= 8; i++) {
		if (x[i] == 0) {
			s1 = s1 + "0";
		}
		else {
			s1 = s1 + "2";
		}
	}

	string day = s1;
	day.insert(2, "/");
	day.insert(5, "/");

	if (day[6] == '2' && (day[0] != '0' || day[1] != '0') && (day[3] != '0' || day[4] != '0') && day[3] < '2') {
		res.push_back(day);
	}
}

void Try(int k) {
	for (int i = 0; i <= 1; i++) {
		x[k] = i;
		if (k == 8) check();
		else Try(k + 1);
	}
}

int main() {
	Try(1);

	sort(res.begin(), res.end());

	for (auto x : res) cout << x << endl;

	return 0;
}