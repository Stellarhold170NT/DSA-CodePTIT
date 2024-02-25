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
#define N 200000

//#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int n, k;
vector<string> v;
int x[N] = { 0 };
map<string, int> mp;

void add() {
	for (int i = 1; i <= k; i++) {
		cout << v[x[i] - 1] << " ";
	}
	cout << endl;
}

void Try(int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k) add();
		else Try(i + 1);
	}
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		mp[s] = 1;
	}

	for (auto x : mp) {
		if (x.second) v.push_back(x.first);
	}

	n = v.size();

	x[0] = 0;
	Try(1);


	return 0;
}