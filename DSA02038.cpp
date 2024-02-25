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

int n, k;
vector<int> v;
int arr[100];

void Try(int i) {
	if (i > n) return;
	for (int j = i; j < n; j++) {
		v.push_back(arr[j]);
		if (v.size() == k) {
			for (auto x : v) cout << x << " ";
			cout << endl;
		}
		else Try(j + 1);
		v.pop_back();
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> k;

		for (int i = 0; i < n; i++) cin >> arr[i];

		sort(arr, arr + n);

		Try(0);
	}

	return 0;
}