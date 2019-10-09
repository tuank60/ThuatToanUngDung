#include<iostream>
int top = 0;
int match(char a, char b)
{
	if (a == '['&&b == ']') return 1;
	if (a == '('&&b == ')')return 1;
	if (a == '{'&&b == '}')return 1;
	else return 0;
}
void push(char a[],int x)
{
	a[top] = x;
	top++;
}
char pop(char a[])
{
	top--;
	return a[top];
}
int main()
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		top = 0;
		int kq = 1;
		char *arr = new char[1000000];
		char *stack = new char[1000000];
		std::cin >> arr;
		int length = 0;
		do
		{
			length++;
		} while (arr[length] != '\0');
		//std::cout << length;
		for (int i = 0; i < length; i++)
		{
			if (arr[i] == '[' || arr[i] == '{' || arr[i] == '(')
			{
				push(stack, arr[i]);
			}
			else
			{
				if (top == 0)
				{
					kq = 0;
					break;
				}
 
				else
				{
					
					if (match(pop(stack), arr[i]) == 0)
					{
						kq = 0;
						break;
					}
 
				}
 
			}
		}
		if (top > 0) kq = 0;
		//std::cout << kq << std::endl;
		//std::cout << top << std::endl;
		
		std::cout << kq << std::endl;
	}
	
	//system("pause");
	return 0; 
 
}
