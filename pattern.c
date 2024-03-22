#include <stdio.h>

void findreplace(char *text,char *pat,char *rep) {
	char ans[100];
	int i,j,k=0,l,found=0;
	for(i=0;text[i]!='\0';i++) {
		for(j=0;pat[j]!='\0';j++) {
			if(text[i+j]!=pat[j])
			break;
		}
		if(pat[j]=='\0') {
			found=1;
			for (l=0;rep[l]!='\0';l++)
			ans[k++]=rep[l];
			i=i+j-1;
		}
		else
			ans[k++]=text[i];
	}
	ans[k]='\0';
	if(found==0) {
		printf("Patern Not Found!");
	} else {
		printf("The Result String: %s\n",ans);
	}
}

int main() {
	char text[100],pat[20],rep[20];
	printf("Enter The Text: ");
	fgets(text, sizeof(text), stdin);
	printf("Enter The Patern: ");
	fgets(pat, sizeof(pat), stdin);
	printf("Enter The Replace String: ");
	fgets(rep, sizeof(rep), stdin);
	findreplace(text,pat,rep);
	return 0;
}
