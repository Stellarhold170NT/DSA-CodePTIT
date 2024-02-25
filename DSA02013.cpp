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

vector<int> nt;
int n, p, s;
int cnt = 0;
int x[200] = { 0 };
vector<string> res;

bool isPrime(int x) {
	if (x < 2) return false;
	if (x == 2) return true;

	for (int i = 2; i <= trunc(sqrt(x)); i++) {
		if (x % i == 0) return false;
	}
	return true;
}

void add() {
	cnt++;
	string ans = "";
	for (int i = 1; i <= n; i++) {
		ans = ans + to_string(nt[x[i]]) + " ";
	}
	ans.pop_back();
	res.push_back(ans);
}

void Try(int i, int sum) {
	if (sum > s) return;
	for (int j = x[i - 1] + 1; j < nt.size(); j++)
		if (nt[j] > p) {
			x[i] = j;
			if (i == n && sum + nt[j] == s) add();
			else Try(i + 1, sum + nt[j]);
		}
}

int main() {
	for (int i = 2; i <= 200; i++) {
		if (isPrime(i)) {
			nt.push_back(i);
		}
	}

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> p >> s;

		cnt = 0;
		x[0] = -1;
		Try(1, 0);

		sort(res.begin(), res.end());
		cout << cnt << endl;
		for (auto x : res) cout << x << endl;

		res.clear();
	}

	return 0;
}