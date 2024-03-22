#include <stdio.h>
#include <stdlib.h>

typedef struct sll {
	int sem;
	char usn[11],name[20],branch[20],phone[11];
	struct sll *next;
} node;

node *start=NULL;

node *getnode() {
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("Enter Student Details: USN,Name,Branch,Sem,Ph-No: ");
	scanf(" %s %s %s %d %s",newnode->usn,newnode->name,newnode->branch,&newnode->sem,newnode->phone);
	newnode->next=NULL;
	return newnode;
}

void insertbegin() {
	node *newnode;
	newnode=getnode();
	if(start==NULL) {
		start=newnode;
		return;
	}
	newnode->next=start;
	start=newnode;
}

void insertend() {
	node *newnode,*tmp;
	newnode=getnode();
	if(start==NULL) {
		start=newnode;
		return;
	}
	tmp=start;
	while(tmp->next!=NULL)
		tmp=tmp->next;
	tmp->next=newnode;
}

void deletebegin() {
	node *tmp=start;
	if(start==NULL) {
		printf("List is Empty!");
		return;
	}
	printf("Deleted Node: %s\n",tmp->usn);
	start=tmp->next;
	free(tmp);
}

void deletend() {
	node *tmp=start,*prev;
	if(start==NULL) {
		printf("List is Empty!");
		return;
	}
	if(start->next==NULL) {
		printf("Deleted Node: %s\n",tmp->usn);
		start==NULL;
		free(tmp);
	} else {
		while(tmp->next!=NULL) {
			prev=tmp;
			tmp=tmp->next;
		}
		prev->next=NULL;
		printf("Deleted Node: %s\n",tmp->usn);
		free(tmp);
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
		printf("%s\n",tmp->usn);
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
			case 1: printf("Enter the Number of Students: ");
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
