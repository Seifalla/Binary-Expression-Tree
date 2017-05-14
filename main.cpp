#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include "BinaryTree.h"

using namespace std;

//functions prototypes

string evaluateExp(string E);
string evaluate(vector<string> &x);
bool isOperand(string x);
bool valid(string);
string comp(string i, string n, string m);

int main(){

	BinaryTree tree; //define tree object
	
	string expression = ""; //string variable

	int SELECTION; //int variable to store user menu choice

//displaying menu choices

	cout<<"***********************************************************"<<endl;
	cout<<"SELECTIONS:"<<endl;
	cout<<"1. Read an expression"<<endl;
	cout<<"2. Display the prefix expression"<<endl;
	cout<<"3. Display the infix expression"<<endl;
	cout<<"4. Display the postfix expression"<<endl;
	cout<<"5. Evaluate the expression using postfix notation."<<endl;
	cout<<"6. Exit"<<endl;
	cout<<"***********************************************************"<<endl;

	cout<<"Select: ";

	cin>>SELECTION;

//keep looping until the user types in 6
	while(SELECTION != 6){

		if(SELECTION == 1){

			cin.ignore(80,'\n');

			cout<<"Enter an infix expression:"<<endl;

			getline(cin, expression);

			while(!valid(expression)){				

				cout<<"Include spaces!"<<endl;

				getline(cin, expression);
			}


			tree.buildTree(expression);
		}	

		if(SELECTION == 2){

			if(expression != ""){

			cout<<"Expression from user input: "<<expression<<endl;

			cout<<"prefix Expression : ";

			tree.prefix();

			cout<<endl;
			}

			else
				cout<<"Expression from user input is empty!"<<endl;
		}

		if(SELECTION == 3){

			if(expression != ""){

			cout<<"Expression from user input: "<<expression<<endl;

		        cout<<"infix Expression : ";
	
			tree.infix();

			cout<<endl;
			}

			else
		
				cout<<"Expression from user input is empty!"<<endl;
		}

		if(SELECTION == 4){

			if(expression != ""){

			cout<<"Expression from user input: "<<expression<<endl;

	                cout<<"postfix Expression : ";
	
			tree.postfix();

			cout<<endl;
			 }

                        else

                                cout<<"Expression from user input is empty!"<<endl;
		}

		if(SELECTION == 5){                       

			if(expression != ""){

			cout<<"Expression from user input: "<<expression<<endl;

                        cout<<"Evaluation of this Expression : ";

                        vector<string> x;

			string i;

			tree.building();
	
			i = tree.evaluate();

			cout<<i<<endl;
			}

                        else

                                cout<<"Expression from user input is empty!"<<endl;
                }
		
	        cout<<"***********************************************************"<<endl;
        	cout<<"SELECTIONS:"<<endl;
	        cout<<"1. Read an expression"<<endl;
        	cout<<"2. Display the prefix expression"<<endl;
	        cout<<"3. Display the infix expression"<<endl;
        	cout<<"4. Display the postfix expression"<<endl;
	        cout<<"5. Evaluate the expression using postfix notation."<<endl;
        	cout<<"6. Exit"<<endl;
	        cout<<"***********************************************************"<<endl;
        	cout<<"Select: ";

	        cin>>SELECTION;
		
	}

	cout<<"Thanks for using my program."<<endl;
		
	return 0;
}

bool isOperand(string x){

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

string comp(string i, string n, string m){

        int result;

	string r;
	
	int m1, m2;

	m1 = atoi( n.c_str() );	

	m2 = atoi( m.c_str() );	

        if(i == "+")

                result = m2 + m1;
        if(i == "-")

                result = m2 - m1;

        if(i == "*")

                result = m2 * m1;
        if(i == "/")

                result = m2 / m1;

	stringstream convert; // stringstream used for the conversion

	convert << result;//add the value of Number to the characters in the stream

	r = convert.str();
		
        return r;
}

bool valid(string E){

	int count = 0;

	int False = 0;

	bool m = true;

	string catchStr;
	
	while(count < E.length()){

		catchStr = E[count];		

		if(!isOperand(catchStr) || catchStr == "(" || catchStr == ")"){

			if(count == 0){

				if(E[count+1] != ' ')

					False ++;	

				else
					;	
			}
			else{

				if(count == E.length() - 1){

					if(E[count-1] != ' ')

						False ++;
				}
				 else{ 
					if(E[count+1] != ' ' || E[count-1] != ' ')

						False ++;			
				}
			}
		}
		else
			;

		count ++;
	}

	if(False > 0)

		m = false;

	return m;
}


