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
#include <climits>
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

const int INF = 10000000;
int n, k;
int res = INT_MAX;
vector<string> v;
int x[100] = { 0 };
int dd[100] = { 0 };

void check() {
	int n_max = INT_MIN;
	int n_min = INT_MAX;
	for (auto s : v) {
		string tmp = "";
		for (int i = 0; i < k; i++) tmp += s[x[i]];
		n_max = max(n_max, stoi(tmp));
		n_min = min(n_min, stoi(tmp));
	}

	res = min(res, n_max - n_min);
}

void Try(int i) {
	for (int j = 0; j < k; j++) if (!dd[j]) {
		dd[j] = 1;
		x[i] = j;
		if (i == k - 1) check();
		else Try(i + 1);
		dd[j] = 0;
	}
}

int main() {
	cin >> n >> k;


	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	Try(0);
	cout << res << endl;
	return 0;
}