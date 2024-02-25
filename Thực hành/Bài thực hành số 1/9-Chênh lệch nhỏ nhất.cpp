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

int n, k;
vector<string> s;
int dd[100] = { 0 };
int x[100] = { 0 };
ll res = 1000000000;

void check() {

	vector<int> v;
	for (int i = 0; i < n; i++) {
		string tmp = "";
		for (int j = 1; j <= k; j++) {
			tmp += s[i][x[j] - 1];
		}
		v.push_back(stoi(tmp));
	}
	sort(v.begin(), v.end());
	res = min(res, (ll)(v[n - 1] - v[0]));
}

void Try(int i) {
	for (int j = 1; j <= k; j++) if (!dd[j]) {
		x[i] = j;
		dd[j] = 1;
		if (i == k) {
			check();
		}
		else Try(i + 1);
		dd[j] = 0;
	}
}

int main() {
	cin >> n >> k;

	s.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	Try(1);

	cout << res << endl;

	return 0;
}