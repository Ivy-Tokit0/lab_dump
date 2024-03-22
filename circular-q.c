#include <stdio.h>
#include <stdlib.h>
#define MAX 5

char q[MAX];
int rear=-1,front=0,count=0;

void enqueue() {
	char ele;
	if(count==MAX)
		printf("Queue Overflow");
	else {
		printf("Enter the Element: ");
		scanf(" %c",&ele);
		rear=(rear+1)%MAX;
		q[rear]=ele;
		count++;
	}
}

void dequeue() {
	if(count==0)
		printf("Queue Underflow");
	else {
		printf("Deleted Element: %c\n",q[front]);
		front=(front+1)%MAX;
		count--;
	}
}

void display() {
	int i,j;
	if(count==0)
		printf("Queue is Empty!");
	else {
		i=front;
		for(j=0;j<count;j++) {
			printf("%c\t",q[i]);
			i=(i+1)%MAX;
		}
	}
}

int main() {
	int choice,ele;
	while(1) {
		printf("\n1 for enqueue\t2 for dequeue\t3 for display\t4 for Exit");
		printf("\nEnter your Choice: ");
		scanf("%d",&choice);
		switch(choice) {
			case 1: enqueue();
			break;
			case 2:	dequeue();
			break;
			case 3: display();
			break;
			case 4: exit(0);
			default: printf("Invalid Choice!");
		}
	}
}
