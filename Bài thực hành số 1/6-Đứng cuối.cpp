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

int dd[100] = { 0 };
int n;
vector<string> v;
vector<string> tmp;
vector<vector<string>> res;

void Try(int i) {
	for (int j = 0; j < n; j++) if (!dd[j]) {
		tmp.push_back(v[j]);
		dd[j] = 1;
		if (i == n - 1) {
			res.push_back(tmp);
		}
		else Try(i + 1);
		dd[j] = 0;
		tmp.pop_back();
	}
}

int main() {
	cin >> n;

	v.resize(n);

	for (auto& i : v) cin >> i;

	sort(v.begin(), v.end());

	string last;
	cin >> last;

	for (int i = 0; i < n; i++) {
		if (last == v[i]) {
			dd[i] = 1;
			break;
		}
	}

	Try(1);

	for (auto x : res) {
		for (auto i : x) cout << i << " ";
		cout << last << endl;
	}

	return 0;
}