#include<iostream>
using namespace std;
#include<stack>
////比较符号的优先
//bool Priority(char ch, char topch)
//{
//	if ((ch == '*' || ch == '/') && (topch == '+' || topch == '-'))
//	{
//		return true;
//	}
//	if (topch == '(' && ch != ')')
//	{
//		return true;
//	}
//	return false;
//}
//
//
//string MiddleToEndExpr(string expr)
//{
//	string result;
//	stack<char>s;
//	for (char ch : expr)
//	{
//		if (ch >= '0' && ch <= '9')
//		{
//			result.push_back(ch);
//		}
//		else
//		{
//			for (;;)
//			{
//				if (s.empty() || ch == '(')
//				{
//					s.push(ch);
//					break;
//				}
//				char topch = s.top();
//				if (Priority(ch, topch))
//				{
//					s.push(ch);
//					break;
//				}
//				else
//				{
//					s.pop();
//					if (topch == '(')
//						break;
//					result.push_back(topch);
//				}
//			}
//		}
//	}
//	while (!s.empty())
//	{
//		result.push_back(s.top());
//		s.pop();
//	}
//	return result;
//}

bool priority(char ch, char topch)
{
	if ((ch == '*' || ch == '/') && (topch == '+' || topch == '-'))
	{
		return true;
	}
	if (topch == '(' && ch != ')')return true;
	return false;
}

string MiddleToEndExpr(string s)
{
	stack<char> s1;
	string result;
	for (auto ch : s)
	{
		if (ch >= '0' && ch <= '9')
		{
			result += ch;
		}
		else
		{
			for (;;)
			{
				if (ch == '(' || s1.empty())
				{
					s1.push(ch);
					break;

				}
				char topch = s1.top();
				if (priority(ch, topch))
				{
					s1.push(ch);
					break;
				}
				else
				{
					s1.pop();
					if (topch == '(')break;
					result += topch;
				}

			}
		}
	}
	while (!s1.empty())
	{
		result.push_back(s1.top());
		s1.pop();
	}
	return result;
}
int main()
{
	cout << MiddleToEndExpr("(1+2)*3+(2+1)*1") << endl;
	return 0;
}