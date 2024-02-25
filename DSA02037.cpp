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

int n;
int arr[100];
vector<int> v;
vector<vector<int>> res;

bool isPrime(int sum) {
	if (sum < 2) return false;
	if (sum == 2) return true;
	for (int i = 2; i <= trunc(sqrt(sum)); i++) {
		if (sum % i == 0) return false;
	}
	return true;
}

void add() {
	res.push_back(v);
}

void Try(int i, int sum) {
	if (isPrime(sum)) add();
	if (i == n) return;

	for (int j = i + 1; j <= n; j++) {
		v.push_back(arr[j]);
		Try(j, sum + arr[j]);
		v.pop_back();
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		sort(arr + 1, arr + n + 1, greater<int>());

		Try(0, 0);

		sort(res.begin(), res.end());
		for (auto x : res) {
			for (auto it : x) {
				cout << it << " ";
			}
			cout << endl;
		}
		v.clear();
		res.clear();
	}

	return 0;
}