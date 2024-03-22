#include <stdio.h>

int count=0;

void tower(int n,char s,char t,char d) {
	if(n<=1) {
		printf("Move From %c to %c\n",s,d);
		count++;
	}
	else {
		tower(n-1,s,d,t);
		printf("Move From %c to %c\n",s,d);
		count++;
		tower(n-1,t,s,d);
	}
}

int main() {
	int n;
	printf("Enter The Number of Disks: ");
	scanf("%d",&n);
	tower(n,'A','B','C');
	printf("Number of Moves: %d\n",count);
	return 0;
}
