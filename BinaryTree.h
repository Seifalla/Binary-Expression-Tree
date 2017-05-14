#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "TreeNode.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class BinaryTree;

//friend functions

int findPlusMinus(vector<string> E, int left, int right);
int findMulDiv(vector<string> E, int left, int right);
string comp(string, string, string);

//class definition

class BinaryTree{

private:

	TreeNode *root;	

public:


vector<string> x;
BinaryTree();
~BinaryTree();
void buildTree(string E);
TreeNode* build(vector<string> E, int left, int right);
void infix();
void prefix();
void postfix();
void inOrder(TreeNode *nodePtr);
void preOrder(TreeNode *nodePtr);
void postOrder(TreeNode *nodePtr);
bool isOperand(string x);
void building();
void buildStack(TreeNode *nodePtr);
string evaluate();
friend int findPlusMinus(vector<string> E, int left, int right);
friend int findMulDiv(vector<string> E, int left, int right);
friend string comp(string, string, string);
};

#endif
