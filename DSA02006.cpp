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
//#define N 50000

//#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int n, k;
int arr[10000];
int x[10000];
vector<string> res;

map<string, bool> mp;

void check() {
	int sum = 0;
	string s;
	for (int i = 0; i < n; i++) {
		if (x[i] == 1) {
			sum += arr[i];
			s = s + to_string(arr[i]) + " ";
		}
	}
	if (!s.empty()) {
		s.pop_back();
	}

	if (sum == k && !mp[s]) {
		mp[s] = true;
		res.push_back(s);
	}
}

void find(int i) {
	for (int j = 1; j >= 0; j--) {
		x[i] = j;

		if (i == n) check();
		else find(i + 1);
	}
}

int main() {

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> k;
		res.clear();
		mp.clear();

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(begin(arr), begin(arr) + n);

		find(0);
		//sort(res.begin(), res.end());
		if (res.empty()) {
			cout << -1 << endl;

		}
		else {
			for (auto x : res) cout << "[" << x << "]" << " ";
			cout << endl;
		}
	}
}