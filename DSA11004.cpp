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

class Node {
public:
	Node* left;
	Node* right;
	int c;

	Node(int c) {
		this->c = c;
		this->left = nullptr;
		this->right = nullptr;
	}
};

Node* createNode(int c) {
	Node* node = new Node(c);
	return node;
}

void buildTree(Node* r, int u, int v, char d) {
	if (r != nullptr) {
		if (r->c == u) {
			if (d == 'L') r->left = createNode(v);
			else r->right = createNode(v);
		}
		buildTree(r->left, u, v, d);
		buildTree(r->right, u, v, d);
	}
}

void levelOrder(Node* root) {
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* cur = q.front();
		q.pop();

		cout << cur->c << " ";

		if (cur->left != nullptr) q.push(cur->left);
		if (cur->right != nullptr) q.push(cur->right);
	}
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int u, v;
		char d;

		cin >> u >> v >> d;
		Node* root = createNode(u);
		buildTree(root, u, v, d);

		for (int i = 1; i < n; i++) {
			cin >> u >> v >> d;
			buildTree(root, u, v, d);
		}

		levelOrder(root);
		cout << endl;
	}
	return 0;
}