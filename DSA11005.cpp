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

int inorder[1001];
vector<int> postorder;
vector<int> levelorder;
unordered_map<int, int> mp;

vector<int> filter(vector<int> levelorder, int l, int r) {
	vector<int> level;
	level.push_back(0);
	for (int i = 1; i < levelorder.size(); i++) {
		for (int j = l; j <= r; j++) {
			if (levelorder[i] == inorder[j]) {
				level.push_back(levelorder[i]);
				break;
			}
		}
	}
	return level;
}

void get_post_order(vector<int> levelorder, int in_left, int in_right) {
	int root = levelorder[1];
	postorder.push_back(root);

	int cntLeft = mp[root] - in_left;
	int cntRight = in_right - mp[root];

	if (cntRight > 0)
		get_post_order(filter(levelorder, mp[root] + 1, in_right), mp[root] + 1, in_right);
	if (cntLeft > 0)
		get_post_order(filter(levelorder, in_left, mp[root] - 1), in_left, mp[root] - 1);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		mp.clear();
		postorder.clear();
		levelorder.resize(n + 1);
		levelorder[0] = 0;
		for (int i = 1; i <= n; i++) cin >> inorder[i], mp[inorder[i]] = i;
		for (int i = 1; i <= n; i++) cin >> levelorder[i];

		get_post_order(levelorder, 1, n);

		for (int i = postorder.size() - 1; i >= 0; i--) {
			cout << postorder[i] << " ";
		}
		cout << endl;
	}

	return 0;
}