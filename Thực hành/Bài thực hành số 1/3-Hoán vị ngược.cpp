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

int n;
string x = "";
vector<string> res;
int dd[100] = { 0 };

void Try(int i) {
	for (int j = n; j >= 1; j--) if (!dd[j]) {
		dd[j] = 1;
		x += to_string(j);
		if (i == n) {
			res.push_back(x);
		}
		else Try(i + 1);
		x.pop_back();
		dd[j] = 0;
	}
}
int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		res.clear();
		memset(dd, 0, sizeof dd);
		Try(1);
		for (int i = 0; i < res.size() - 1; i++) cout << res[i] << ",";
		cout << res[res.size() - 1] << endl;
	}

	return 0;
}