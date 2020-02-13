/*Griffin Mack
 * 
 * word.c-Creates a word search puzzle given a data file and square size. 
 * Then asks for a word to search for in said puzzle.
 *
 * Function Calls->LeftToRight,RightToLeft,BottomToTop,TopToBottom*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int LeftToRight(int squareSize,char wordSearch[],char** wordMat,char** dotMat){ 
	int length=0;
	int i=0;
	int j=0;
	int k=0;
	int flag=0;
	int matches=0;
length=strlen(wordSearch);
for(i=0;i<squareSize;i++) {
	for(j=0;j<squareSize;j++) {
		if(j+length<=squareSize){
			if(wordMat[i][j]==wordSearch[0]) {
			for(k=1;k<length;k++) {
				if(wordMat[i][j+k]==wordSearch[k]);
				else flag=1;	
			}
		}
		else flag=1;
			if(flag==0) {
				matches++;
				for(k=0;k<length;k++) {
					dotMat[i][j+k]=wordSearch[k];
					}
	}}
	flag=0;
}}

return matches;
}
int RightToLeft(int squareSize,char wordSearch[],char** wordMat,char** dotMat){ 
	int length=0;
	int i=0;
	int j=0;
	int k=0;
	int flag=0;
	int matches=0;
length=strlen(wordSearch);
for(i=0;i<squareSize;i++) {
	for(j=0;j<squareSize;j++) {
		if(j+length<=squareSize){
			if(wordMat[i][j]==wordSearch[length-1]) {
			for(k=1;k<length;k++) {
				if(wordMat[i][j+k]==wordSearch[length-1-k]);
				else flag=1;	
			}
		}
		else flag=1;
			if(flag==0) {
				matches++;
				for(k=0;k<length;k++) {
					dotMat[i][j+k]=wordSearch[length-1-k];
					}
	}}
	flag=0;
}}

return matches;
}


int BottomToTop(int squareSize,char wordSearch[],char** wordMat,char** dotMat){ 
	int length=0;
	int i=0;
	int j=0;
	int k=0;
	int flag=0;
	int matches=0;
length=strlen(wordSearch);
for(j=0;j<squareSize;j++) {
	for(i=0;i<squareSize;i++) {
		if(i+length<=squareSize){
			if(wordMat[i][j]==wordSearch[0]) {
			for(k=0;k<length;k++) {
				if(wordMat[i+k][j]==wordSearch[k]);
				else flag=1;
			}
		}
		else flag=1;
			if(flag==0) {
				matches++;
				for(k=0;k<length;k++) {
				dotMat[i+k][j]=wordSearch[k];
				}
	}}
	flag=0;
}}
return matches;
}
int TopToBottom(int squareSize,char wordSearch[],char** wordMat,char** dotMat){ 
	int length=0;
	int i=0;
	int j=0;
	int k=0;
	int flag=0;
	int matches=0;
length=strlen(wordSearch);
for(j=0;j<squareSize;j++) {
	for(i=0;i<squareSize;i++) {
		if(i+length<=squareSize){
			if(wordMat[i][j]==wordSearch[length-1]) {
			for(k=0;k<length;k++) {
				if(wordMat[i+k][j]==wordSearch[length-1-k]);
				else flag=1;
			}
		}
		else flag=1;
			if(flag==0) {
				matches++;
				for(k=0;k<length;k++) {
				dotMat[i+k][j]=wordSearch[length-1-k];
				}
	}}
	flag=0;
}}
return matches;
}
int main(int argc, char* argv[]) {
	FILE* inFile;
inFile=fopen(argv[2],"r");

//check if file name is invalid
if(inFile==NULL) {
	printf("File doesn't exist\n");
	return -1;
}
	
	int squareSize=0;
	int i=0;
	int j=0;
	char fileChar='?';
//creating word matrix
squareSize=atoi(argv[1]);
	char **wordMat=malloc(sizeof(char *)*squareSize);
	for(i=0;i<squareSize;i++) {
	wordMat[i]=malloc(sizeof(char *) *squareSize);
}
for(i=0;i<squareSize;i++) {
	for(j=0;j<squareSize;j++) {
		fscanf(inFile,"%c ",&fileChar);
		wordMat[i][j]=fileChar;
	}
}
for(i=0;i<squareSize;i++) {
	for(j=0;j<squareSize;j++) {
		printf("%c",wordMat[i][j]);
	}
	printf("\n");
}
fclose(inFile);

	char wordSearch[100];
	int matchesL2R=0;
	int matchesR2L=0;
	int matchesB2T=0;
	int matchesT2B=0;
	int matchesTotal=0;
	char **dotMat=malloc(sizeof(char *) *squareSize);
//creating dot matrix
	for(i=0;i<squareSize;i++) {
	dotMat[i]=malloc(sizeof(char *) * squareSize);
	}
for(i=0;i<squareSize;i++) {
	for(j=0;j<squareSize;j++) {
		dotMat[i][j]='.';
	}
}
//start of word search
printf("Enter a word to find in the puzzle:");
scanf("%s",wordSearch);
while(strcmp(wordSearch,"zzz")!=0){
matchesL2R=LeftToRight(squareSize,wordSearch,wordMat,dotMat);
matchesR2L=RightToLeft(squareSize,wordSearch,wordMat,dotMat);
matchesB2T=BottomToTop(squareSize,wordSearch,wordMat,dotMat);
matchesT2B=TopToBottom(squareSize,wordSearch,wordMat,dotMat);
matchesTotal=matchesR2L+matchesL2R+matchesB2T+matchesT2B;
printf("The word %s was found %d times, as shown below\n",wordSearch,matchesTotal);
if(matchesL2R>=1) printf("%d times written left-to-right\n",matchesL2R);
if(matchesR2L>=1) printf("%d times written right-to-left\n",matchesR2L);
if(matchesB2T>=1) printf("%d times written bottom-to-top\n",matchesB2T);
if(matchesT2B>=1) printf("%d times written top-to-bottom\n",matchesT2B);
printf("\n");
for(i=0;i<squareSize;i++) {
	for(j=0;j<squareSize;j++) {
		printf("%c",dotMat[i][j]);
	}
printf("\n");
}
printf("\nEnter another word to find (or 'zzz' to exit) :");
scanf("%s",wordSearch);
for(i=0;i<squareSize;i++) {
	for(j=0;j<squareSize;j++) {
		dotMat[i][j]='.';
	}
}}
return 0;
}

