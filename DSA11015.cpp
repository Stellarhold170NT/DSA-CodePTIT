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
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int d = 0;
bool check = true;

string res1 = "";
string res2 = "";

long long sum = 0;
int ans = -1e9;

class Node {
public:
	int x;
	Node* left;
	Node* right;

	Node(int x) {
		this->x = x;
		left = nullptr;
		right = nullptr;
	}
};

unordered_map<int, Node*> mp;

void connect(Node* r, int u, int v, char c) {
	if (r == nullptr) return;
	if (r->x == u) {
		Node* n = new Node(v);
		if (c == 'L') r->left = n;
		else r->right = n;
	}
	else {
		connect(r->left, u, v, c);
		connect(r->right, u, v, c);
	}
}

bool isLeaf(Node* r) {
	if (r->left == nullptr && r->right == nullptr) return true;
	return false;
}

void inOrder(Node* r) {
	if (r != nullptr) {
		if (r->right && isLeaf(r->right)) sum += r->right->x;
		if (r->left && !isLeaf(r->left))
			inOrder(r->left);
		if (r->right && !isLeaf(r->right))
			inOrder(r->right);
	}
}

int calc(Node* root) {
	if (root == nullptr) return 0;

	int L = calc(root->left), R = calc(root->right);

	if (root->left == nullptr && root->right == nullptr) return root->x;

	if (root->left == nullptr) return R + root->x;
	if (root->right == nullptr) return L + root->x;

	ans = max(ans, L + R + root->x);

	return max(L, R) + root->x;
}

int main() {
	faster();
	int t;
	cin >> t;

	while (t--) {
		ans = -1e9;
		mp.clear();
		int n;
		cin >> n;

		Node* root = nullptr;

		while (n--) {
			int u, v;
			char c;

			cin >> u >> v >> c;

			if (root == nullptr) {
				root = new Node(u);
				mp[u] = root;
				connect(root, u, v, c);

			}
			else
				connect(root, u, v, c);
		}

		calc(root);
		cout << ans << endl;

	}
	return 0;
}