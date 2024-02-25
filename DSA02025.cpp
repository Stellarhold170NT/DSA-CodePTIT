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

int n;
string s[100];
int dd[100] = { 0 };
int f[20][20];
int x[100];
int res = 100;

void check() {
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		cnt += f[x[i - 1]][x[i]];
	}

	res = min(res, cnt);
}

void Try(int i) {
	for (int j = 1; j <= n; j++) if (!dd[j]) {
		dd[j] = 1;
		x[i] = j;
		if (i == n) check();
		else Try(i + 1);
		dd[j] = 0;
	}
}

int count(string a, string b) {
	map<char, int> mp;
	for (auto x : a) mp[x]++;
	for (auto x : b) mp[x]++;
	int cnt = 0;
	for (auto x : mp) cnt += (x.second > 1);
	return cnt;
}

int main() {
	cin >> n;

	memset(f, 0, sizeof f);

	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			f[i][j] = count(s[i], s[j]);
			f[j][i] = f[i][j];
		}
	}

	Try(1);

	cout << res << endl;

	return 0;
}