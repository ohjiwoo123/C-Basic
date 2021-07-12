#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <math.h>

#include <string.h>

#define MAX_STACK_SIZE 100 /* maximum stack size */

#define MAX_EXPR_SIZE 100 /* max size of expression */

#define MAX 100

typedef enum {
	lparen, rparen, plus, minus, times, divide,

	mod, eos, operand

} precedence;

char expr[MAX_EXPR_SIZE]; /* input string */

int top = 0;

precedence stack[MAX_STACK_SIZE];

/* isp and icp arrays ? index is value of precedence lparen, rparen,

plus, minus, times, divide, mode, eos */

void print_stack()
{
	int i;

	printf("[STACK : ");

	for (i = 0; i <= top; i++)
	{
		print_token(stack[i]);
	}

	printf("]");
	printf("\n");
}

void push(precedence item)

{
	if (top >= MAX_STACK_SIZE - 1) {
		printf("stack_full()\n");

		return;

	}

	stack[++top] = item;

	print_stack();

}

precedence pop() {
	if (top == -1)

	{
		printf("stack_empty()\n");

	}

	int x = stack[top];

	top--;

	print_stack();

	return x;

}

int isempty()

{
	if (top == -1) return(1); else return(0);

}

int isfull()

{
	if (top >= MAX_STACK_SIZE - 1) return(1); else return(0);

}

static int isp[] = { 0,19,12,12,13,13,13,0 };

static int icp[] = { 20,19,12,12,13,13,13,0 }; // lparen 연산자 우선순위 조정

precedence get_token(char* symbol, int* n) {
	*symbol = expr[(*n)++];

	switch (*symbol) {
	case '(': return lparen;

	case ')': return rparen;

	case '+': return plus;

	case '-': return minus;

	case '/': return divide;

	case '*': return times;

	case '%': return mod;

	case ' ': return eos;

	default: return operand;

	}

}

precedence print_token(precedence t) {
	switch (t) {
	case lparen: printf("( "); break;

	case rparen: printf(") "); break;

	case plus: printf("+ "); break;

	case minus: printf("- "); break;

	case divide: printf("/ "); break;

	case times: printf("* "); break;

	case mod: printf("%% "); break;

	case eos: printf("eos "); break;

	default: printf("\n "); return(0);

	}

}

void postfix(void) {
	char symbol;

	precedence token;

	int n = 0;

	top = 0;

	stack[0] = eos; // 스택의 바닥에 공백(eos)를 넣는다.

	for (token = get_token(&symbol, &n); token != eos; token = get_token(&symbol, &n))

	{
		if (token == operand) printf("%c ", symbol);

		else if (token == rparen) { // 오른쪽 괄호 만나면 스택에서 모두 pop..

			while (stack[top] != lparen)

				print_token(pop());

			pop();

		}

		else { // 연산자들의 우선 순위 비교..

			while (isp[stack[top]] >= icp[token])

				print_token(pop());

			push(token);

		}

	}

	while ((token = pop()) != eos)

		print_token(token);

	printf(" \n");

}



int main()

{
	/*precedence p = divide;

	if (p == divide)

	printf("division\n");

	else printf("no division\n");*/

	strcpy(expr, "5*(3+2)/7 "); // 입력의 마지막에 공백(eos)을 둔다.

	postfix();

}

