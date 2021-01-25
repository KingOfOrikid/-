#include "Stack.h"
#include <math.h>
using namespace std;

/*
(1)定义两个工作栈，一个运算符栈OPTR、一个操作数栈OPND寄存操作数和运算结果
  (2)首先置操作数栈OPND为空栈，表达式起始符“#”为运算符栈的栈底元素
  (3)依次读入每个字符:
		若是操作数则进入OPND
		若是运算符则和OPTR栈的栈顶元素比较优先级后进行运算，直到求值完毕（即：OPTR栈顶元素和当前字符为“#”）
*/

char getNum(char op);//得到运算符对应的索引
char getPriority(char in, char out);//两个运算符比较优先级
char operation(char op, double num2, double num1);//运算
double getAnswer(string input);//遍历表达式得到答案
bool OpCheck(string input);//检查表达式是否合法
Stack<char> OPTR;//运算符栈
Stack<double> OPND;//操作数栈

int main()
{
	string input;
	cout << "请输入你需要进行运算的表达式(以'#'结束):";
	cin >> input;
	if (OpCheck(input))
	{
		double answer;
		answer = getAnswer(input);
		cout << "答案为：" << answer << endl;
	}
	system("pause");
	return 0;
}


char getNum(char op)//获取此op所对应的索引
{
	int index = 0;
	switch (op)
	{
	case '+':
		index = 0;
		break;
	case '-':
		index = 1;
		break;
	case '*':
		index = 2;
		break;
	case '^':
		index = 3;
		break;
	case '/':
		index = 4;
		break;
	case '(':
		index = 5;
		break;
	case ')':
		index = 6;
		break;
	case '#':
		index = 7;
		break;
	default:
		break;
	}
	return index;
}

char getPriority(char in, char out)//获取op1和op2的优先级
{
	const char priority[8][8] =
	{
		//+   -   *   ^   /   (    )  #
		{'>','>','<','<','<','<','>','>'},//+
		{'>','>','<','<','<','<','>','>'},//-
		{'>','>','>','<','>','<','>','>'},//*
		{'>','>','>','>','>','<','>','>'},//^
		{'>','>','>','<','>','<','>','>'},///
		{'<','<','<','<','<','<','=','0'},//(
		{'>','>','>','>','>','0','>','>'},//)
		{'<','<','<','<','<','<','0','='},//#
	};//制作优先级关系的表，表内为栈顶：进栈元素的符号，顶部符号表示进栈符号
	//0表示情况不可能发生，发生时表达式错误
	//（=）表示括号内运算已完成，#=#表示表达式运算已完成
	int inside = getNum(in);
	int outside = getNum(out);
	return priority[inside][outside];
}

char operation(char op, double num2, double num1)//计算num2 op num1，num2是表达式中考前的操作数
{
	switch (op)
	{
	case '+':
		return num2 + num1;
	case '-':
		return num2 - num1;
	case '*':
		return num2 * num1;
	case '/':
		return num2 / num1;
	case '^':
		return pow(num2, num1);
	default:
		break;
	}
}

double getAnswer(string input)//表达式求值
{
	OPTR.initStack();
	OPND.initStack();
	//表达式起始符“#”为运算符栈的栈底元素
	OPTR.push('#');//将‘#’入栈optr
	int count = 0;//判断输入的连续数字是否属于同一个操作数
	char top;
	for (int i = 0; i < input.length();i++)
	{
		OPTR.getTop(top);
		if (input[i] != '#' || top != '#')
		{
			//首先判断录入的是符号还是数字
			if (isdigit(input[i]))//录入的是数字
			{
				if (count == 1)//这个操作数大于一位数
				{
					double tmp = 0.0;
					OPND.pop(tmp);
					OPND.push(tmp * 10 + (input[i] - '0'));//将新输入的数字加上原有数字的十倍后入栈
					count = 1;
				}
				else//此数为操作数输入的第一个数字
				{
					//double tmp = (double)(input[i] - '0');
					OPND.push(input[i] - '0');//数字入栈
					count++;//表示已录入了第一个数字
				}
			}
			else//录入的是符号
			{
				count = 0;//计数器归零，便于下一次操作数进栈
				//首先与栈顶符号相比确定优先级
				char opTmp;
				OPTR.getTop(opTmp);
				switch (getPriority(opTmp, input[i]))
				{
				case '>'://栈顶元素优先级大于入栈元素，计算目前栈内元素
				{	
					char op;
					OPTR.pop(op);//栈顶的符号
					double num1 = 0;
					double num2 = 0;
					OPND.pop(num1);
					OPND.pop(num2);
					OPND.push(operation(op, num2, num1));//计算结果入栈
					if (input[i] == ')')
					{
						i--;
					}//计算完括号内的弹出左右括号
					else if (input[i] == '#')
					{
						i--;
					}//如果计算到末尾，返回计算运算符栈内未计算完的运算符
					else
					{
						OPTR.push(input[i]);//新符号入栈
					}
					break;
				}
				case '<'://栈顶元素小于入栈元素，元素入栈
				{
					OPTR.push(input[i]);
					break;
				}
				case '='://将栈顶元素弹出，用于括号的处理
				{
					OPTR.pop(opTmp);
					break;
				}
				default:
					break;
				}
			}
		}
		else
		{
			double numTop;
			OPND.getTop(numTop);
			return numTop;//返回操作数栈顶元素的值
		}
	}
	double numTop;
	OPND.getTop(numTop);
	return numTop;//返回操作数栈顶元素的值
}


bool OpCheck(string input)//检验表达式是否合法(是否含除括号运算符以外的符号/括号匹配是否正确

{
	for (int i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]))
		{
			continue;
		}
		else if (input[i] == '#' || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^' || input[i] == '(' || input[i] == ')')
		{
			continue;
		}
		else
		{
			cout << "表达式输入不合法！" << endl;
			exit(ERROR);
		}
	}
	Stack<char> s1;
	s1.initStack();
	for (int i = 0; i < input.length(); i++)
	{
		//读到左括号时，左括号进栈
		if (input[i] == '(' || input[i] == '{' || input[i] == '[')
		{
			s1.push(input[i]);
		}
		else if (input[i] == ')' || input[i] == '}' || input[i] == ']')
		{
			char elem;
			//如果当前为空栈，说明右括号比左括号多，匹配失败
			if (s1.isEmpty())
			{
				cout << "括号输入不正确！" << endl;
				exit(ERROR);
			}
			else
			{
				s1.pop(elem);
				if (input[i] == ')'&&elem == '(')
				{
					continue;
				}
				else if (input[i] == '}'&&elem == '{')
				{
					continue;
				}
				else if (input[i] == ']'&&elem == '[')
				{
					continue;
				}
				else
				{
					cout << "括号输入不正确！" << endl;
					exit(ERROR);
				}
			}
		}
	}
	if (s1.isEmpty())
	{
		if (input[input.length() - 1] != '#')
		{
			cout << "没有以'#'作为表达式的末尾！" << endl;
			exit(ERROR);
		}
		return true;
	}
	else
	{
		cout << "括号输入不正确！" << endl;
		exit(ERROR);
	}
}