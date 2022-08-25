#include<string>
#include<iostream>
using namespace std;
#include"Stackclass.h"
//setting the weightage/power of the operators
int Weightage_of_operators(char ch)
{
	int power = 0;
	if (ch == '*' || ch == '/') {
		power = 2;
	}
	else if (ch == '+' || ch == '-') {
		power = 1;
	}
	return power;
}
//utiltiy function to compare the precedence of peek and the current index of the infix expression
bool Precedence(char ch1, char ch2)
{
	int operator_1 = Weightage_of_operators(ch1);
	int operator_2 = Weightage_of_operators(ch2);
	if(operator_1>=operator_2)
		{
			return true;
		}
	return false;
	//return (operator_1 >= operator_2 ? true : false);
}
//checking if it is an operator
bool Operator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
		return true;
	}
	return false;
}
//checking if it is an operand
bool Operand(char ch)
{
	if (ch >= '0' && ch <= '9') {
		return true;
	}
		
	
	
	return false;
}
//converting  infix exp to postfix exp
string Infix_To_Postfix(string exp)
{
	Stackclass <char> S(20);
	string postfix = "";
	for (int i = 0; i < exp.length(); i++)
	{
		//if current index has an operator
		 if (Operator(exp[i]))
		{
			postfix += ' '; //adding space to postfix expression
			while (!S.isempty() && S.peek() != '(' && Precedence(S.peek(), exp[i]))
			{
				//if precedence at he peek is greator than adding the operator to the postfix exp
				postfix += S.peek();
				postfix += ' ';//adding space
				S.pop();
				
			}
			S.push(exp[i]);
		}
		 //if operand than adding it to the postfix expression as it is
		else if (Operand(exp[i]))
		{
			postfix += exp[i];
		}
		 //if opening bracket then pushing it to the stack
		else if (exp[i] == '(')
		{
			S.push(exp[i]);
		}
		 //if closing bracket than poping untill peek has the opening bracket and adding to the postfix exp
		else if (exp[i] == ')')
		{
			while (!S.isempty() && S.peek() != '(')
			{
				postfix += ' ';
				postfix += S.peek();
				S.pop();
			}
			S.pop();
		}
	}
	//at the end of the infix exp empty the stack..
	while (!S.isempty())
	{
		postfix += ' ';
		postfix += S.peek();
		S.pop();
	}
	return postfix;
}

int main()
{
	string exp;
	cout << "Enter Infix expression" << endl;
	getline(cin, exp);
	cout << endl;
	cout << "Your infix expression is ==>" << exp << endl;
	cout << "Processing <==> Converting into postfix expression" << endl;
	cout << endl;
	cout << endl;

	string postfix = Infix_To_Postfix(exp);
	cout << "Your postfix expression is ==> " << postfix << endl;
}
