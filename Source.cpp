#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

char stack[MAX];
int top = -1;
void push(char);
char pop();
bool isForward(char);
bool isBackward(char);
bool closing_brackets(char, char);

void main()
{
	int n;
	char *ch;
	bool b = true;
	printf("enter no of brackets : \n");
	scanf("%d", &n);
	if (n % 2 == 0)
	{
		ch = (char *)malloc(n * sizeof(char));
		printf("enter brackets : \n");
		scanf("%s", ch);

		for (int i = 0, j = 0; i < n; i++, j++)
		{
			if (isForward(*(ch + i)))
				push(*(ch + i));

			if (isBackward(*(ch + i)))
			{
				char ch2 = pop();

				if (closing_brackets( ch2, *(ch + i)) )
					j -= 2;

				else
					b = false;
			}
		}

		if (top == -1 && b)
			printf("\nBalanced");
		else
			printf("\nNot balanced");
	}
	else
		printf("\nNot balanced");
	_getch();
}

void push(char element)
{
	if (top == MAX - 1)
	{
		printf("Stack Overflow \n");
		return;
	}
	top = top + 1;
	stack[top] = element;
}

char pop()
{
	char element;
	if (top == -1)
	{
		printf("Stack is empty \n");
		return -1;
	}
	element = stack[top];
	top = top - 1;
	return element;
}

bool isForward(char ch)
{
	if (ch == '[' || ch == '{' || ch == '(')
		return true;
	else
		return false;
}

bool isBackward(char ch)
{
	if (ch == ']' || ch == '}' || ch == ')')
		return true;
	else
		return false;
}

bool closing_brackets(char ch1, char ch2)
{
	if (ch1 == '[' && ch2 == ']')
		return true;
	else if (ch1 == '{' && ch2 == '}')
		return true;
	else if (ch1 == '(' && ch2 == ')')
		return true;
	else
		return false;
}