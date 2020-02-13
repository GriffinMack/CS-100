#include <stdio.h>
#include <string.h>
int main(void) {

	char a[50];

printf("Who were you thinking about? (parents,sibling,other) ");
scanf("%s", a);
if(strcmp(a, "parents")==0) {
	printf("\nMom?(yes or no) ");
	char b[50];
	scanf("%s", b);
	if(strcmp(b, "yes")==0) {
		printf("\nAre things bothering you?(yes or no) ");
		char c[50];
		scanf("%s", c);
		if(strcmp(c, "no")==0) {
			printf("\nSend a quick text about your day\n");
		}
		else {
			printf("\nCall them(and be prepared to spend at least 10 minutes on the phone)\n");
		}
	}
	if (strcmp(b, "no")==0) {
		printf("\nTalked recently?(yes or no) ");	
		char d[50];
		scanf("%s", d);       //have used a-d characters.
		if(strcmp(d, "yes")==0) {
			printf("\nDo nothing(let them call you)\n");
		}
		else {
			printf("\nSend a quick text about your day\n");
		}
	}
}


if(strcmp(a, "sibling")==0) {
	printf("\nYounger or older?  ");
	char b[50];
	scanf("%s", b);
	if(strcmp(b, "younger")==0) {
		printf("\nHow do they view you?(hero,useless) ");
		char c[50];
		scanf("%s", c);
		if(strcmp(c, "hero")==0) {
			printf("\nDo you have a test tomorrow?(yes or no) ");	
			char d[50];
			scanf("%s", d);       
			if(strcmp(d, "yes")==0) {
				printf("\nSend a quick text about your day\n");
				}
			if(strcmp(d, "no")==0) {
				printf("\nCall them(and be prepared to spend at least 10 minutes on the phone)\n");
		}
		}
		if(strcmp(c, "useless")==0) {
				printf("\nDo nothing(let them call you)\n");
		}
				
		}
	
	if(strcmp(b, "older")==0) {
		printf("\nWere they always there for you?(yes or no) ");	
			char d[50];
			scanf("%s", d);       
			if(strcmp(d, "yes")==0) {
				printf("\nCall them(and be prepared to spend at least 10 minutes on the phone)\n");
				}
	
			else {
				printf("\nWas it due to the way you acted?(yes or no) ");
				char d[50];
				scanf("%s", d);
				if (strcmp(d, "yes")==0) {
					printf("\nSend a quick text about your day\n");
				}
				else {
					printf("\nDo nothing(let them call you)\n");
				}
			}
	}
}
if(strcmp(a, "other")==0) {
        printf("\nIs it one of your grandparents?(yes or no) ");
 	char b[50];
	scanf("%s", b);	
	if(strcmp(b, "yes")==0) {
		printf("\nDo they like you?(yes or no) ");	
			char d[50];
			scanf("%s", d);       
			if(strcmp(d, "no")==0) {
				printf("\nDo nothing(let them call you)\n");
				}
	
			else {
				printf("\nBut do they like everyone?(yes or no) ");
				char d[50];
				scanf("%s", d);
				if (strcmp(d, "yes")==0) {
					printf("\nSend a quick text about your day");
				}
				else {
					printf("\nCall them(and be prepared to spend at least 10 minutes on the phone)\n");
				}
			}
	}
	if(strcmp(b, "no")==0) {
		printf("\nYou in their will?(yes or no) ");
		char c[50];
		scanf("%s", c);
		if(strcmp(c, "no")==0) {
			printf("\nDo nothing(let them call you)\n");
		}
		else {
			printf("Call them(and be prepared to spend at least 10 minutes on the phone)\n");
		}
	}
}

printf("\n");
return 0;
}

