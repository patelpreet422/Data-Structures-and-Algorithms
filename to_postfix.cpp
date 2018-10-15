#include <iostream>
#include <stack>
using namespace std;
bool is_operator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}
bool has_high_preced(char o1, char o2)
{
	if(o1 == '*' || o1 == '/')
	{
		return true;
	}
	if(o1 == '+' || o1 == '-')
	{
		return o2 == '+' || o2 == '-'? true:false;
	}
}
auto to_postfix(string infix)
{
	auto postfix = ""s;
	stack<char> operators;
	for(auto c: infix)
	{
		if(c == '(')
		{
			operators.push(c);
		}
		else if(c == ')')
		{
			while(operators.top() != '(')
			{
				postfix += operators.top();
				operators.pop();
			}
			operators.pop();
		}
		else if(is_operator(c))
		{
			while(!operators.empty() && operators.top() != '(' && has_high_preced(operators.top(), c))
			{
				postfix += operators.top();
				operators.pop();
			}
			operators.push(c);
		}
		else
		{
			postfix += c;
		}
	}
	
	while(!operators.empty())
	{
		postfix += operators.top();
		operators.pop();
	}
	
	return postfix;
}
int main()
{
	auto infix = "(a+(b-c))*((d-e)/(f+g-h))"s;
	cout << to_postfix(infix);
	return 0;
}
