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

string res1 = "";
string res2 = "";

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

void inOrder(Node* r) {
	if (r != nullptr) {
		inOrder(r->left);
		res2 += to_string(r->x);
		inOrder(r->right);
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		res1 = "";
		res2 = "";
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

		int m;
		cin >> m;

		Node* root2 = nullptr;

		while (m--) {
			int u, v;
			char c;

			cin >> u >> v >> c;

			if (root2 == nullptr) {
				root2 = new Node(u);
			}

			connect(root2, u, v, c);
		}

		inOrder(root);
		res1 = res2;
		res2 = "";
		inOrder(root2);

		if (res1 == res2) cout << 1;
		else cout << 0;

		cout << endl;

	}
	return 0;
}