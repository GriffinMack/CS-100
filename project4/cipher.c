/* Griffin Mack
 * Program to read in a data file and apply a cipher to the contents
 * Function signatures-
 * 			FunctionI
 * 			FunctionD
 * 			FunctionR
 * 			FunctionL*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void FunctionI(char word[]) {
	int x=0;
	int count=0;
for(x=0;x<strlen(word);x++) {
	if(word[x]>='A' && word[x]<='Y') {
		word[x]+=1;
		count=x+1;
	}
	if(word[x]>='0' && word[x]<='8'){
	       	word[x]+=1;
		count=x+1;
	}
	if(word[x]>='a' && word[x]<='y') {
		word[x]+=1;
		count=x+1;
	}
	if(word[x]=='z' && count!=x+1) word[x]='a';
	if(word[x]=='Z' && count!=x+1) word[x]='A';
	if(word[x]=='9' && count!=x+1) word[x]='0';
}
	return;
}

void FunctionD(char word[]) {
	int x=0;
	int count=0;
for(x=0;x<strlen(word);x++) {
	if(word[x]>='B' && word[x]<='Z') {
		word[x]-=1;
		count=x+1;
	}
	if(word[x]>='1' && word[x]<='9'){
	       	word[x]-=1;
		count=x+1;
	}
	if(word[x]>='b' && word[x]<='z') {
		word[x]-=1;
		count=x+1;
	}
	if(word[x]=='a' && count!=x+1) word[x]='z';
	if(word[x]=='A' && count!=x+1) word[x]='Z';
	if(word[x]=='0' && count!=x+1) word[x]='9';
}
	return;
}
void FunctionR(char word[]) {
	char tempWord;
	int x=0;
tempWord=word[strlen(word)-1];
for(x=strlen(word)-1;x>=0;x--) {
	word[x]=word[x-1];
}
word[0]=tempWord;
return;
}
void FunctionL(char word[]) {
	char tempWord;
	int x=0;
tempWord=word[0];
for(x=0;x<strlen(word)-1;x++) {
	word[x]=word[x+1];
}
word[strlen(word)-1]=tempWord;
return;
}
int main(int argc, char* argv[]) {
	FILE* inFile;
inFile=fopen(argv[1],"r");
if(inFile==NULL) {
	printf("File doesn't exist\n");
	return -1;
}
	int countI=0;
	int countD=0;
	int countL=0;
	int countR=0;
	int j=0;
	int i=0;
	char Cipher[1000000];
	char fileWord[100];
strcpy(Cipher,argv[2]);
for(j=0;j<strlen(Cipher);j++) {
	if(Cipher[j]=='I') countI++;
	if(Cipher[j]=='D') countD++;
	if(Cipher[j]=='L') countL++;
	if(Cipher[j]=='R') countR++;
	if(Cipher[j]!='I' && Cipher[j]!='D' && Cipher[j]!='L'&& Cipher[j]!='R') {
		printf("ERROR\n");
		return -1;
}
}
fscanf(inFile,"%s",fileWord);
while(!feof(inFile)) {
		for(i=0;i<countI;i++) {
			FunctionI(fileWord);
		}

		for(i=0;i<countD;i++) {
			FunctionD(fileWord);
		}
		for(i=0;i<countL;i++) {
			FunctionL(fileWord);
		}
		for(i=0;i<countR;i++) {
			FunctionR(fileWord);
		}
printf("%s\n",fileWord);
fscanf(inFile,"%s",fileWord);
}


return 0;
}
