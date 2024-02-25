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

int inorder[1001], preorder[1001];
vector<int> postorder;
unordered_map<int, int> mp;

void get_post_order(int pre_left, int pre_right, int in_left, int in_right) {
	if (pre_left > pre_right) return;

	int root = preorder[pre_left];
	postorder.push_back(root);

	if (pre_left == pre_right) return;
	else {
		int cntLeft = mp[root] - in_left;
		int cntRight = in_right - mp[root];
		get_post_order(pre_left + cntLeft + 1, pre_right, mp[root] + 1, in_right);
		get_post_order(pre_left + 1, pre_right - cntRight, in_left, mp[root] - 1);
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		mp.clear();
		postorder.clear();

		for (int i = 1; i <= n; i++) cin >> inorder[i], mp[inorder[i]] = i;
		for (int i = 1; i <= n; i++) cin >> preorder[i];

		get_post_order(1, n, 1, n);

		for (int i = postorder.size() - 1; i >= 0; i--) {
			cout << postorder[i] << " ";
		}
		cout << endl;
	}

	return 0;
}