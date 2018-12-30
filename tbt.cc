#include <iostream>
using namespace std;

class Tbt;

class Node {
	int data;
	Node *left, *right;
	bool isRightThreaded;
	friend class Tbt;
};

class Tbt {
	Node *root;
	
	private:
		Node *mknode(int d) {
			Node *temp = new Node;
			temp->data = d;
			temp->left = temp->right = nullptr;
			temp->isRightThreaded = false;
		}
		
		Node *getLeftMost(Node *r) {
			if(r == nullptr)
				return r;

			Node *temp = r, *left;
			while(temp != nullptr) {
				left = temp;
				temp = temp->left;
			}
			return left;
		}
			
	public:
		Tbt() {
			root = nullptr;
		}
		
		void insert(int d) {
			if(root == nullptr) {
				root = mknode(d);
				return;
			}
			
			Node *newnode = mknode(d);
			Node *temp = root, *current;
			while(temp != nullptr) {
				current = temp;
				if(d < temp->data) {
					temp = temp->left;
					if(temp == nullptr) {
						current->left = newnode;
						newnode->right = current;
						newnode->isRightThreaded = true;
						return;
					}
				} else if(d > temp->data) {
					if(temp->isRightThreaded == false) {
						temp = temp->right;
						if(temp == nullptr) {
							current->right = newnode;
							return;
						}				
					} else {
						Node *t = temp->right;
						temp->right = newnode;
						newnode->right = t;
						newnode->isRightThreaded = true;
						return;
					}
				} else {
					delete newnode;
					return;
				}
			}
		}
		
		void print() {
			Node *current = getLeftMost(root);
			while(current != nullptr) {
				cout << current->data << ' ' << flush;
				if(current->isRightThreaded == true) {
					current = current->right;
				} else {
					current = getLeftMost(current->right);
				}
			}
		}
};


int main() {
	Tbt obj;
	
	obj.insert(23);
	obj.insert(48);
	obj.insert(3);
	obj.insert(1);
	obj.insert(10);
	obj.insert(30);
	
	obj.print();
	cout << endl;
	return 0;
}
