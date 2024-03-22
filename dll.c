#include <stdio.h>
#include <stdlib.h>

typedef struct dll {
	int ssn,sal;
	char name[20],dept[20],design[20],phone[11];
	struct dll *next,*prev;
} node;

node *start=NULL;

node *getnode() {
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("Enter Employee Details: SSN,Name,Department,Designation,Salary,Ph-No: ");
	scanf(" %d %s %s %s %d %s",&newnode->ssn,newnode->name,newnode->dept,newnode->design,&newnode->sal,newnode->phone);
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}

void insertbegin() {
	node *newnode;
	newnode=getnode();
	if(start==NULL) {
		start=newnode;
		return;
	} else {
		newnode->next=start;
		start->prev=newnode;
		start=newnode;
	}
}

void insertend() {
	node *newnode,*curr;
	newnode=getnode();
	if(start==NULL) {
		start=newnode;
		return;
	} else {
		curr=start;
		while(curr->next!=NULL)
			curr=curr->next;
		curr->next=newnode;
		newnode->prev=curr;
	}
}

void deletebegin() {
	node *tmp=start;
	if(start==NULL) {
		printf("List is Empty!");
		return;
	}
	printf("Deleted Node: %d\n",tmp->ssn);
	start=tmp->next;
	start->prev=NULL;
	free(tmp);
}

void deletend() {
	node *tmp=start,prev;
	if(start==NULL) {
		printf("List is Empty!");
		return;
	}
	if(start->next==NULL) {
		printf("Deleted Node: %d\n",tmp->ssn);
		start=NULL;
		free(tmp);
	} else {
		while(tmp->next!=NULL) {
			tmp=tmp->next;
		(tmp->prev)->next=NULL;
		printf("Deleted Node: %d\n",tmp->ssn);
		free(tmp);
		}
	}
}

void display(){
	int count=0;
	node *tmp=start;
	if(start==NULL) {
		printf("List is Empty!");
		return;
	}
	printf("The list Elements\n");
	while(tmp!=NULL) {
		printf("%d\n",tmp->ssn);
		tmp=tmp->next;
		count++;
	}
	printf("Count: %d\n",count);
}

int main() {
	int choice,n,i;
	while(1) {
		printf("1 for insertbegin\t2 for insertend\n3 for deletebegin\t4 for deletend\n5 for display\t\t6 for Exit");
		printf("\nEnter Your Choice: ");
		scanf(" %d",&choice);
		switch(choice) {
			case 1: printf("Enter the Number of Employee: ");
							scanf(" %d",&n);
							for(i=0;i<n;i++)
								insertbegin();
			break;
			case 2: insertend();
			break;
			case 3: deletebegin();
			break;
			case 4: deletend();
			break;
			case 5: display();
			break;
			case 6: exit(0);
			default: printf("Invalid Choice!");
		}
	}
}
