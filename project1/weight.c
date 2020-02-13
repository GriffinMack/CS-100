/**
Griffin Mack

Program calculates the total number of bills and coins a user has, and outputs the weight of bills, coins, and combined to the console window
*/

#include <stdio.h>

int main(void)
{
	int numTwenty = 0;
	int numTen = 0;
	int numFive = 0;
	int numOne = 0;
	int numQuarter = 0;
	int numDime = 0;
	int numNickel = 0;
	int numPenny = 0;

printf("Enter the number of $20s you have:");
scanf("%d", &numTwenty);

printf("Enter the number of $10s you have:");
scanf("%d", &numTen);

printf("Enter the number of $5s you have:");
scanf("%d", &numFive);

printf("Enter the number of $1s you have:");
scanf("%d", &numOne);

printf("Enter the number of quarters you have:");
scanf("%d", &numQuarter);

printf("Enter the number of dimes you have:");
scanf("%d", &numDime);

printf("Enter the number of nickels you have:");
scanf("%d", &numNickel);

printf("Enter the number of pennies you have:");
scanf("%d", &numPenny);

numTwenty *= 20;
numTen *= 10;
numFive *= 5;
numOne *= 1;
numQuarter *= 25;
numDime *= 10;
numNickel *= 5;
numPenny *= 1;

	int numDollar = 0;
	int numCent = 0;

numDollar = numTwenty + numTen + numFive + numOne;
numCent = numQuarter + numDime + numNickel + numPenny;

printf("\nYou have %d dollars in bills and %d cents in change.\n", numDollar, numCent);

	double billWeight = 0;
	
	const double WEIGHT_OF_BILL=1;
	const double GRAM_TO_POUND=.00220462;//set constant conv factor 1 g=.00220462 lb

numTwenty /= 20;
numTen /= 10;
numFive /= 5;
numOne /= 1;

billWeight = ((numTwenty + numTen + numFive + numOne) * WEIGHT_OF_BILL) * GRAM_TO_POUND;

printf("The weight of your bills is %lf pounds.\n", billWeight);

	double changeWeight = 0;
	
	const double WEIGHT_OF_QUARTER=5.670;
	const double WEIGHT_OF_DIME=2.268;
	const double WEIGHT_OF_NICKEL=5.000;
	const double WEIGHT_OF_PENNY=2.500;

numQuarter /= 25;
numDime /= 10;
numNickel /= 5;
numPenny /= 1;

changeWeight = ((numQuarter * WEIGHT_OF_QUARTER) + (numDime * WEIGHT_OF_DIME) + (numNickel * WEIGHT_OF_NICKEL) + (numPenny * WEIGHT_OF_PENNY)) * GRAM_TO_POUND;

printf("The weight of your change is %lf pounds.\n", changeWeight);

	double totalWeight = 0;

totalWeight = billWeight + changeWeight;

printf("Your money can go a total of %lf pounds.\n", totalWeight);

return 0;

} 
