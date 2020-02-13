#include<stdio.h>
#include<string.h>

int main(void) {
	int lineLength=0;
	int i=0;
	int k=0;
	int lineLeft=0;
	int count=0;
printf("Enter the output line length: ");
scanf("%d", &lineLength);
while (lineLength <=0) {
	printf("Invalid line length,try again: ");
	scanf("%d",&lineLength);
}
	char string[3000000];
	char word[1000];
	int lengthString=0;
	int lengthWord=0;
printf("\nEnter your text(ctrl-D to quit): ");
scanf("%s", word);
printf("\n");
lengthWord=strlen(word);
lengthString=0;
string[0]='\0';
while(!feof(stdin)) {	
		
		if ((lengthWord+lengthString)>=lineLength || lengthWord==lineLength) {
			
			for(k=0;k<(lineLength-lengthString);k++) printf(" ");
			for(i=(lengthString-1);i>=0;i--) {
			printf("%c",string[i]);
			}
			printf("\n");
			string[0]='\0';
			strcat(string, word);
			strcat(string, " ");
			lengthString=strlen(string);
			lineLeft=0;
			count=0;
			scanf("%s", word);
			lengthWord=strlen(word);	
		}
		if (count==0) {
			strcat(string, word);
			count++;
			lengthString=strlen(string);
		lineLeft=lineLength-lengthString;	
		}
		else {
			if((lengthWord)+lengthString<lineLength) {
			strcat(string," ");
			strcat(string, word);
		lineLeft=lineLength-lengthString;
		}
		}
	scanf("%s", word);
	lengthWord=strlen(word);
	lengthString=strlen(string);
		}
lengthString=strlen(string);
lineLeft=lineLength-lengthString;

	for(k=0;k<lineLeft;k++) printf(" ");
	for(i=lengthString-1;i>=0;i--) {
		printf("%c",string[i]);
	}
		printf("\n");	
return 0;
}
