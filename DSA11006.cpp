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

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz size()
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

void inOrder(Node* r, int depth) {
	if (r != nullptr) {
		inOrder(r->left, depth + 1);
		//cout << r->x << " ";
		inOrder(r->right, depth + 1);
	}
	else {
		if (!d) d = depth;
		else if (depth != d) {
			check = false;
			return;
		}
	}
}

void spiralOrder(Node* r) {
	stack<Node*> st1, st2;

	st1.push(r);

	while (!st1.empty() || !st2.empty()) {
		while (st1.size()) {
			Node* cur = st1.top();
			st1.pop();

			cout << cur->x << " ";

			if (cur->right != nullptr) st2.push(cur->right);
			if (cur->left != nullptr) st2.push(cur->left);
		}

		while (st2.size()) {
			Node* cur = st2.top();
			st2.pop();

			cout << cur->x << " ";
			if (cur->left != nullptr) st1.push(cur->left);
			if (cur->right != nullptr) st1.push(cur->right);
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		Node* root = nullptr;

		while (n--) {
			int u, v;
			char c;

			cin >> u >> v >> c;

			if (root == nullptr) {
				root = new Node(u);
			}

			connect(root, u, v, c);
		}

		spiralOrder(root);
		cout << endl;
	}
	return 0;
}