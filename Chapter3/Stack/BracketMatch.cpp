#include "Stack.h"
//¿®∫≈∆•≈‰ºÏ≤È

int main_BracketMatch() 
{
	Stack<char> s1;
	s1.initStack();
	string input;
	while (true)
	{
		s1.clear();
		input = "";
		cout << "«Î ‰»Îƒ„–Ë“™ºÏ≤Èµƒ±Ì¥Ô Ω:";
		cin >> input;
		for (int i = 0; i < input.length(); i++)
		{
			//∂¡µΩ◊Û¿®∫≈ ±£¨◊Û¿®∫≈Ω¯’ª
			if (input[i]=='('|| input[i] == '{' || input[i]=='[')
			{
				s1.push(input[i]);
			}
			else if (input[i] == ')' || input[i] == '}' || input[i]==']')
			{
				char elem;
				//»Áπ˚µ±«∞Œ™ø’’ª£¨Àµ√˜”“¿®∫≈±»◊Û¿®∫≈∂‡£¨∆•≈‰ ß∞‹
				if (s1.isEmpty())
				{
					cout << "∆•≈‰ ß∞‹£°" << endl;
					return 0;
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
						cout << "∆•≈‰ ß∞‹£°" << endl;
						return ERROR;
					}
				}
			}
		}
		if (s1.isEmpty())
		{
			cout << "∆•≈‰≥…π¶£°" << endl;
			return 0;
		}
		else
		{
			cout << "∆•≈‰ ß∞‹£°" << endl;
		}
	}
	system("pause");
	return 0;
}