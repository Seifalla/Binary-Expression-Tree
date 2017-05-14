#include "BinaryTree.h"
#include <iostream>

using namespace std;

//constructor & distructor

BinaryTree::BinaryTree(){
	
	root = NULL;
}

BinaryTree::~BinaryTree(){}

//this function accepts a string 
//as a parameter and store it in
// a vector of string then it
// sends it to the function that
//builts the tree
	
void BinaryTree::buildTree(string E)
{
        vector<string> exp;

        int count = 0;

        int pos = 0;

        while(count <= E.length() - 1){

                int countSpaces = 0;

                string catchStr;

                if(E[count] != ' '){
                        while(E[count] != ' '){

                                countSpaces++;

                                count ++;

                                if(count >= E.length())

                                        break;
                        }
                        for(int x = 0; x < countSpaces; x ++){

                                catchStr += E[pos];

                                pos++;
                        }

                        exp.push_back(catchStr);
                }
                else{
                        count ++;
                        pos++;
                }
        }

        root = build(exp, 0, exp.size() - 1);

}

//this function builts the tree structure
//by finding operators and making them 
// parents while operands become child nodes

TreeNode* BinaryTree::build(vector<string> E, int l,int r){

        if (l == r){
//a single operand
                TreeNode* G;
                G = new TreeNode(E[l]);

                return G;
        }
        TreeNode *T;

        int loc = findPlusMinus(E, l, r) ;

        if(loc != -1){

                if(E[loc] == "+"){

                        T = new TreeNode("+");
                }

                else{

                        T = new TreeNode("-");

                }

        T->left = build(E, l, loc-1);//build left subtree

        T->right = build(E, loc+1, r);

        return T;
        }

        loc = findMulDiv(E, l, r);

        if(loc != -1){

                if(E[loc] == "*"){

                        T = new TreeNode("*");
                }
                else{
                        T = new TreeNode("/");
                }

        T->left = build(E, l, loc-1);

        T->right = build(E, loc+1, r);

        return T;
}
        return build(E, l+1, r-1); //parentheses eliminated
}

//this fnction searches the vector of strings for a plus 
//or minus signs
int findPlusMinus(vector<string> E, int left, int right){

        int parenCnt = 0, loc = right;
        while(loc >= left){
                if(E[loc] == ")")
                        parenCnt++ ;
                else if(E[loc] == "(")
                        parenCnt-- ;
                     else if(E[loc] == "+" || E[loc] == "-")
                                if (parenCnt == 0)
                                        return loc;
                loc--;
        }
        return -1 ;
}
//this fnction searches the vector of strings for a times
//or divide signs
int findMulDiv(vector<string> E, int left, int right){

        int parenCnt = 0, loc = right;

        while(loc >= left){
                if(E[loc] == ")")
                        parenCnt++ ;
                else if(E[loc] == "(")
                        parenCnt-- ;
                    else if(E[loc] == "*" || E[loc] == "/")
                                if (parenCnt == 0)
                                        return loc;
                loc--;
        }
        return -1 ;
}

//assistant functions to help transverse the tree

void BinaryTree::infix(){inOrder(root);}
void BinaryTree::prefix(){preOrder(root);}
void BinaryTree::postfix(){postOrder(root);}

//this function generates infix notation

void BinaryTree::inOrder(TreeNode *nodePtr){

	if(nodePtr){

		if(isOperand(nodePtr -> value))
	
			cout<<nodePtr -> value<<' ';
		else{

			cout<<'('<<' ';

			inOrder(nodePtr -> left);
		
			cout<<nodePtr -> value<<' ';

			inOrder(nodePtr -> right);

			cout<<')'<<' ';
		
		}
	}
}

//this function generates prefix notation

void BinaryTree::preOrder(TreeNode *nodePtr){

        if(nodePtr){

		cout<<nodePtr -> value;

                preOrder(nodePtr -> left);           

                preOrder(nodePtr -> right);
        }
}

//this function generates postfix notation

void BinaryTree::postOrder(TreeNode *nodePtr){

        if(nodePtr){             

                postOrder(nodePtr -> left);

                postOrder(nodePtr -> right);

		cout<<nodePtr -> value;
        }
}

//assistant function to help evaluate 
// postfix expressions

void BinaryTree::building(){

	buildStack(root);	
}

void BinaryTree::buildStack(TreeNode *nodePtr){

        if(nodePtr){

                buildStack(nodePtr -> left);

                buildStack(nodePtr -> right);

                x.push_back(nodePtr -> value);
        }	
}
		
bool BinaryTree::isOperand(string x){

	bool var = true;

	if(x == "+")

		var = false;

	if(x == "-")

		var = false;

	if(x == "*")

                var = false;

	if(x == "/")

                var = false;
	
	return var;
}

//this function evaluates the postfix expression

string BinaryTree::evaluate(){

        stack<string> S;

        string op2,op1;

        string result = " ";
        
        for(int i = 0; i < x.size(); i++)
        {
                if (isOperand(x[i]))

                        S.push(x[i]);
                else //E[i] is an operator.
                {
                        op1 = S.top();
                        S.pop();
                        op2 = S.top();
                        S.pop();
                        S.push(comp(x[i], op1, op2));
                }
        }

        result = S.top();

        S.pop();

        return result;
}

