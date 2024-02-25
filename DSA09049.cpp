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

#define int long long
#define MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 5000000 + 11
#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int n;
vector<int> edge[200005];
int dinh_duong[200005] = { 0 };
int cnt[200005] = { 0 };

void bfs(int s) {
	for (auto x : edge[s]) {
		bfs(x);
		dinh_duong[s] += dinh_duong[x];
		cnt[s] += cnt[x] + 1;
	}
	dinh_duong[s] += cnt[s];
}

main() {
	cin >> n;
	for (int i = 1; i <= n; i++) dinh_duong[i] = 1;
	for (int i = 2; i <= n; i++) {
		int par;
		cin >> par;
		edge[par].push_back(i);
	}

	bfs(1);

	for (int i = 1; i <= n; i++) {
		cout << dinh_duong[i] << " ";
	}

	return 0;
}