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

int cnt = 0;

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

void preOrder(Node* root) {
	if (root != nullptr) {
		if (root->left == nullptr && root->right == nullptr) {
			cnt--;
		}
		preOrder(root->left);
		preOrder(root->right);
	}
}

unordered_map<int, int> mp;

Node* buildTree(Node* root, int val) {
	if (root == nullptr) {
		root = new Node(val);
		return root;
	}

	if (root->x > val) {
		root->left = buildTree(root->left, val);
	}
	else root->right = buildTree(root->right, val);

	return root;
}


int main() {
	faster();
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int arr[1001];

		Node* root = nullptr;


		for (int i = 1; i <= n; i++) {
			cin >> arr[i];

			root = buildTree(root, arr[i]);
		}

		cnt = n;

		preOrder(root);
		cout << cnt << endl;
	}
	return 0;
}