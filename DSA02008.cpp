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
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int n, k;
int arr[101][101];
vector<int> v;
vector<vector<int>> res;

void Try(int i, int mask, int sum) {
	if (i == n) {
		if (sum == k) {
			res.push_back(v);
		}
		return;
	}
	for (int j = 0; j < n; j++) {
		if ((mask >> j) & 1) continue;
		v.push_back(j + 1);
		Try(i + 1, mask | (1 << j), sum + arr[i][j]);
		v.pop_back();
	}
}


int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	Try(0, 0, 0);

	cout << res.size() << endl;
	for (auto x : res) {
		for (auto i : x) cout << i << " ";
		cout << endl;
	}
	return 0;
}