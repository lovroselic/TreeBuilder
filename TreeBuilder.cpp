// https://www.codeabbey.com/index/task_view/tree-builder#prob-stat
// https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <chrono>
#include <cmath>
#include <cassert>
#include <limits>
#include <numeric>
#include <tuple>
#include <regex> 

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION "1.0"

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

class Node {
public:
	int value;
	Node* left;
	Node* right;

	Node(int value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
	void print() {
		cout << this->value;
	}
};

class BST {
public:
	Node* root = NULL;

	BST(vector<int> list) {
		for (auto key : list) {
			this->insert(key);
		}
	}

	void insert(int key) {
		Node* node = new Node(key);

		if (!root) {
			root = node;
			return;
		}

		Node* prev = NULL;
		Node* temp = root;

		while (temp) {
			if (temp->value > key) {
				prev = temp;
				temp = temp->left;
			}
			else if (temp->value < key) {
				prev = temp;
				temp = temp->right;
			}
		}

		if (prev->value > key) {
			prev->left = node;
		}
		else {
			prev->right = node;
		}
	}
	void inorder(Node* node) {
		if (!node) {
			cout << "-";
			return;
		}
		cout << "(";
		inorder(node->left);
		cout << ",";
		node->print();
		cout << ",";
		inorder(node->right);
		cout << ")";
	}
};

int main() {
	auto t1 = high_resolution_clock::now();
	cout << "TreeBuilder v" << VERSION << "!\n\n";
	//string path = "Test.txt";
	string path = "Try.txt";
	vector<string> raw_data = loadData(path);
	//printVector(raw_data);
	/***********************/

	vector<int> data = splitToInt(raw_data[1], " ");
	//printVector(data);

	BST bst(data);
	cout << "Solution: ";
	bst.inorder(bst.root);
	cout << endl;

	/***********************/
	auto t2 = high_resolution_clock::now();
	auto ms_int = duration_cast<milliseconds>(t2 - t1);
	cout << "Execution time: " << ms_int.count() << " ms" << endl;
}
