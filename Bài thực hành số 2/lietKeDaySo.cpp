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
#include <bitset>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int N;
vector<ll> res;

void Try(int i, ll n, bool check2, bool check3, bool check5, bool check7) {
	if (i >= 5 && i <= N + 1 && n % 2 != 0) {
		if (check2 && check3 && check5 && check7) res.push_back(n);
	}

	if (i <= N) {
		Try(i + 1, n * 10 + 2, true, check3, check5, check7);
		Try(i + 1, n * 10 + 3, check2, true, check5, check7);
		Try(i + 1, n * 10 + 5, check2, check3, true, check7);
		Try(i + 1, n * 10 + 7, check2, check3, check5, true);
	}
}

int main() {
	faster();
	cin >> N;

	Try(1, 0, false, false, false, false);

	sort(res.begin(), res.end());

	for (auto x : res) {
		cout << x << endl;
	}

	return 0;
}