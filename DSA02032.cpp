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

int arr[100];
vector<int> v;
vector<string> res;
int n, x;

void add() {
	string ans = "";
	ans += "{";
	for (int i = 0; i < v.size() - 1; i++) ans += to_string(v[i]) + " ";
	ans += to_string(v[v.size() - 1]) + "}";
	res.push_back(ans);
}

void Try(int i, int sum) {
	if (sum > x) return;
	if (sum == x) {
		add();
		return;
	}

	for (int j = i; j <= n; j++) {
		v.push_back(arr[j]);
		Try(j, sum + arr[j]);
		v.pop_back();
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> x;


		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		Try(1, 0);
		if (res.size()) {
			cout << res.size() << " ";
			for (auto x : res) cout << x << " ";
			cout << endl;
		}
		else cout << -1 << endl;

		res.clear();
		v.clear();
	}

	return 0;
}