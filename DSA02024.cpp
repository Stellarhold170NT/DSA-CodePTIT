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

int n;
int arr[N];
vector<int> v;
vector<string> res;

void add() {
	string ans = "";
	for (int i = 0; i < v.size(); i++) ans = ans + to_string(v[i]) + ' ';
	ans.pop_back();
	//cout << ans << endl;
	res.push_back(ans);
}

void Try(int i) {
	for (int j = i + 1; j <= n; j++) {
		if (arr[j] > arr[i]) {
			v.push_back(arr[j]);

			if (i > 0) {
				add();
			}
			Try(j);

			v.pop_back();
		}
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	arr[0] = -1000;

	Try(0);

	sort(res.begin(), res.end());

	for (auto x : res) cout << x << endl;

	return 0;
}