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

int n, x;
int arr[100];
vector<int> v;
bool check;

void Try(int x, int lim) {
	if (x < 0) return;
	if (x == 0) {
		cout << '[';
		check = true;
		for (int i = 0; i < v.size() - 1; i++) cout << v[i] << " ";
		cout << v[v.size() - 1] << "]";
		return;
	}

	for (int i = lim; i < n; i++) {
		v.push_back(arr[i]);
		Try(x - arr[i], i);
		v.pop_back();
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> x;
		v.clear();
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + n);
		check = false;
		Try(x, 0);
		if (!check) cout << -1;
		cout << endl;
	}

	return 0;
}