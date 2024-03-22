#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct calendar {
  char *name, *description;
  int date;
} cal;
int i;

cal* create() {
	return (cal*)malloc(7*sizeof(cal));
}

void read(cal *d) {
	int flag;
	char tmp[20];
	for(i = 0; i < 7; i++) {
		d[i].name = NULL;
		d[i].date = -1;
		d[i].description=NULL;
	}
	do {
		printf("Enter The Date: ");
		scanf("%d", &i);
		if (i<0 || i>6)
			printf("Invalid Date!");
		else {
			d[i].date = i;
			printf("Enter The Name: ");
			scanf("%s",tmp);
			d[i].name=strdup(tmp);
			printf("Enter Description: ");
			scanf("%s", tmp);
			d[i].description=strdup(tmp);
		}
		printf("Enter 1 To Continue 0 To Exit: ");
		scanf( "%d",&flag);
	}
	while (flag==1);
}

void display(cal* d) {
  for (i=0;i<7;i++) {
    if (d[i].date!=-1)
      printf("%d\t%s\t%s\n",d[i].date,d[i].name,d[i].description);
  }
}

void deallocate(cal* d) {
  for (i=0;i<7;i++) {
    free(d[i].name);
    free(d[i].description);
  }
  free(d);
}

int main() {
	cal* d = create();
	read(d);
	display(d);
	deallocate(d);
	return 0;
}
