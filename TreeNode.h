#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
#include <string>
using namespace std;

class TreeNode{

public:

	string value;

	TreeNode *left;

	TreeNode *right;

	TreeNode(string k) {value = k; left = right = NULL;}
};
#endif
