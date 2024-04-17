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
#include <climits>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 600000

#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)
#define endl "\n"
string s;
vector<string> v;
unordered_map<string, int> m;


int merge(int a[], int l, int r, int mid) {
	vector<int> c;
	int res = 0;
	int i = l;
	int j = mid + 1;

	while (i <= mid && j <= r) {
		if (a[i] <= a[j]) c.push_back(a[i++]);
		else {
			c.push_back(a[j++]);
			res += (mid - i + 1);
		}
	}

	while (i <= mid) c.push_back(a[i++]);
	while (j <= r) c.push_back(a[j++]);

	for (int i = l; i <= r; i++) a[i] = c[i - l];

	return res;
}

int merge_sort(int a[], int l, int r) {
	int res = 0;
	if (l < r) {
		int mid = (l + r) / 2;
		res += merge_sort(a, l, mid);
		res += merge_sort(a, mid + 1, r);
		res += merge(a, l, r, mid);
	}
	return res;
}

int main() {
	int n;
	cin >> n;

	/*int* a = new int(n + 5);
	int* c = new int(n + 5);*/
	int a[100001];
	int c[100001];
	int idx = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			c[idx++] = a[i];
		}
	}
	int total = merge_sort(c, 0, idx - 1);
	int cnt = 0;

	a[n] = 1;

	for (int i = 1; i <= n; i++) {
		if (a[i] % 2 == 0 && a[i - 1] % 2 == 0) cnt++;
		else if (a[i] % 2 == 1 && a[i - 1] % 2 == 0) {
			total -= merge_sort(a, i - (cnt + 1), i - 1);
			cnt = 0;
		}
	}

	cout << total << endl;


	return 0;
}