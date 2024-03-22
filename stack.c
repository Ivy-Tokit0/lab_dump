#include<stdio.h>
#include<stdlib.h>
#define size 5

int stack[size],top=-1;

void push(int ele){
	if(top==size-1)
		printf("Stack Overflow");
	else
		stack[++top]=ele;
}

int pop() {
	if(top==-1) {
		printf("Stack Underflow");
		return -999;
	}
	else
		return(stack[top--]);
}

void display() {
	int i;
	if(top==-1)
		printf("Stack is Empty!");
	else {
		printf("Stack Elements: ");
		for(i=top;i>=0;i--)
			printf("%d\t",stack[i]);
	}
}

void palindrome() {
	top=-1;
	int num,ncopy;
	printf("Enter The Value: ");
	scanf("%d",&num);
	ncopy=num;
	while(num!=0) {
		push(num%10);
		num=num/10;
	}
	while(top!=-1) {
		if(ncopy%10!=pop()) {
			printf("Given Number is not a Palindrome");
			return;
		}
		ncopy=ncopy/10;
	}
	printf("It is a Palindrome");
}

int main() {
	int choice,ele;
	printf("1 for push\n2 for pop\n3 for display\n4 for Palindrome\n5 for Exit");
	while(1) {
		printf("\nEnter Your Choice: ");
		scanf("%d",&choice);
		switch(choice) {
			case 1: printf("Enter The Element: ");
				scanf("%d",&ele);
				push(ele);
				break;
			case 2: ele=pop();
				if(ele!=-999)
				printf("Poped Element: %d",ele);
				break;
			case 3: display();
				break;
			case 4: palindrome();
				break;
			case 5: exit(0);
			default: printf("Invalid Choice!");
		}
	}
}
