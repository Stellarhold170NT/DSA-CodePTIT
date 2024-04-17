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

int res = 0;
int f[1001] = { 0 };
vector<int> leafNode;

void bfs(vector<int> edge[], int u) {
	queue<int> q;
	q.push(u);
	f[u] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto x : edge[cur]) {
			f[x] = cur;
			if (edge[x].empty()) {
				leafNode.push_back(x);
			}
			q.push(x);
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		memset(f, 0, sizeof f);
		vector<int> edge[1001];

		for (int i = 1; i <= n - 1; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
		}

		res = 0;

		leafNode.clear();
		bfs(edge, 1);

		sort(leafNode.begin(), leafNode.end());
		for (auto x : leafNode) {
			stack<int> st;
			st.push(x);
			while (true) {
				x = f[x];
				st.push(x);
				if (x == 1) break;
			}

			while (st.size()) {
				cout << st.top() << " ";
				st.pop();
			}
			cout << endl;
		}
	}

	return 0;
}