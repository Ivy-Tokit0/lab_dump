#include<stdio.h>
#include<string.h>
char stack[20];
int top=-1;

void push(char s) {
	stack[top++]=s;
}

char pop()  {
	return stack[--top];
}

int precd(char s) {
	switch(s) {
		case '^': return 4;
		case '*':
		case '/': return 3;
		case '+':
		case '(': return 2;
		case ')': return 1;
		case '#': return 0;
	}
	return 0;
}

void convertip(char infix[20],char postfix[20]) {
	int i,j=0;
	char sym;
	push('#');
	int infixlen = strlen(infix);
	for(i=0;i<infixlen;i++) {
		sym=infix[i];
		switch(sym) {
			case '(': push(sym);
			break;
			case ')': while(stack[top]!='(') {
				postfix[j++]=pop();
				}
				pop();
			break;
			case '^':
			case '*':
			case '/':
			case '+':
			case '-': while(precd(sym)<=precd(stack[top])) {
				postfix[j++]=pop();
				}
				push(sym);
			break;
			default : postfix[j++]=sym;
		}
	}
	while (stack[top]!='#') {
		postfix[j++]=pop();
	}
	postfix[j]='\0';
}

int main() {
	char infix[20],postfix[20];
	printf("Enter The Infix Expression: ");
	scanf(" %s",infix);
	convertip(infix,postfix);
	printf("Postfix Expression: %s\n",postfix);
	return 0;
}
