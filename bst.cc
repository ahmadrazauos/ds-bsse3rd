#include <iostream>
#include <stack>
using namespace std;

class Bst;

class Node {
	int data;
	Node *left, *right;
	friend class Bst;
};

class Bst {
	Node *root;
	
	private:
		Node *mknode(int d) {
			Node *temp = new Node;
			temp->data = d;
			temp->left = temp->right = NULL;
			return temp;
		}
		
		void inRecPrint(Node *r) {
			if(r == NULL)
				return;
			inRecPrint(r->left);
			cout << r->data << ' ';
			inRecPrint(r->right);
		}
		
		void preRecPrint(Node *r) {
			if(r == NULL)
				return;
			
			cout << r->data << ' ';
			preRecPrint(r->left);
			preRecPrint(r->right);
		}
		
		void postRecPrint(Node *r) {
			if(r == NULL)
				return;
				
			postRecPrint(r->left);
			postRecPrint(r->right);
			cout << r->data << ' ';
		}
		
		
	public:
		Bst() {
			root = NULL;
		}
		
		void insert(int d) {
			if(root == NULL) {
				root = mknode(d);
				cout << "Inserted node " << d << endl;
				return;
			}
			
			Node *temp = root, *current;
			while(temp != NULL) {
				current = temp;
				if(d < temp->data) {
					temp = temp->left;
					if(temp == NULL) {
						current->left = mknode(d);
						cout << "Inserted node " << d << endl;
						return;
					}
				} else if(d > temp->data) {
					temp = temp->right;
					if(temp == NULL) {
						current->right = mknode(d);
						cout << "Inserted node " << d << endl;
						return;
					}
				} else {
					return;
				}
			}
		}
		
		void inRecPrint() {
			Node *temp = root;
			inRecPrint(temp);
		}
		
		void preRecPrint() {
			Node *temp = root;
			preRecPrint(temp);
		}
		
		void postRecPrint() {
			Node *temp = root;
			postRecPrint(temp);
		}
		
		void inStkPrint() {
			Node *temp = root;
			stack<Node *> stk;
			
			while(!stk.empty() || temp != NULL) {
				if(temp != NULL) {
					stk.push(temp);
					temp = temp->left;
				} else {
					temp = stk.top();
					stk.pop();
					cout << temp->data << ' ';
					temp = temp->right;
				}
			}
		}
		
		void preStkPrint() {
			Node *temp = root;
			stack<Node *> stk;
			stk.push(temp);
			
			while(!stk.empty()) {
				Node *curr = stk.top();
				stk.pop();
				cout << curr->data << ' ';
				
				if(curr->right != NULL) {
					stk.push(curr->right);
				}
				
				if(curr->left != NULL) {
					stk.push(curr->left);
				}
			}
		}
		
		void postStkPrint() {
			Node *temp = root;
			stack<Node *> stk;
			stack<int> ordered;
			
			stk.push(temp);
			
			while(!stk.empty()) {
				Node *curr = stk.top();
				stk.pop();
				
				ordered.push(curr->data);
				
				if(curr->left != NULL) {
					stk.push(curr->left);
				}
				
				if(curr->right != NULL) {
					stk.push(curr->right);
				}
			}
			
			while(!ordered.empty()) {
				int curr = ordered.top();
				ordered.pop();
				cout << curr << ' ';
			}
		}
};

int main() {
	Bst obj;
	
	obj.insert(23);
	obj.insert(48);
	obj.insert(3);
	obj.insert(1);
	obj.insert(10);
	obj.insert(30);
	
	obj.inRecPrint();
	cout << endl;
	obj.preRecPrint();
	cout << endl;
	obj.postRecPrint();
	cout << endl;
	
	obj.inStkPrint();
	cout << endl;
	obj.preStkPrint();
	cout << endl;
	obj.postStkPrint();
	cout << endl;
}
