// This Program uses the Luhn Algorithm to detect 
// invalid credit card numbers
// by Andrew Colbeck 2017

#include <stdlib.h>
#include <stdio.h>


//---------------------------------------------------
//					**** PROTOTYPES ****			
//---------------------------------------------------
int find_sum1(int a[], int length);
int find_sum2(int a[], int length);


//---------------------------------------------------
//					**** MAIN PROGRAM ****			
//---------------------------------------------------

int main()
{
	int a[20]={-1}, i=0, length=0, input=0, sum1, sum2, checksum=0;

	printf("\n\nThis Program will use the Luhn algorithm to detect\n");
	printf("fraudulent credit card numbers.\n\n");

	printf("Please enter credit card number in the following format:\n");
	printf("\t-All digits separated by a single space\n");
	printf("\t-Enter -1 when finished.\n\n");

		while (input != -1)
		{
			scanf(" %i", &input);

			if (input !=-1)
			{
				a[i] = input;
				i++;
				length++;
			}
		}
	
	if (length > 20)
	{
		printf("\nError, too many digits entered.\n");
		printf("Proceeding with first 20 digits only.\n");
		length=20;
	}
	
	printf("\nThe Credit Card Number is: ");
	for (i = 0; i < length; i++)
	{
		printf("%i", a[i]);
	}
	printf("\n");

	sum1 = find_sum1(a, length);
	printf("\nsum1 is: %i\n", sum1);

	sum2 = find_sum2(a, length);
	printf("\nsum2 is %i\n", sum2);

	checksum = (9*(sum1+sum2))%10;
		//Modulus 10 will give a remainder of the last digit only.
	printf("Checksum %i, and the last digit %i ", checksum, a[length-1]);

	if (checksum == a[length-1])
		printf("are the same: Valid Credit Card number.\n\n");
	else
		printf("do not match.  Credit Card number invalid.\n\n");
}


//---------------------------------------------------
//					**** FUNCTIONS ****			
//---------------------------------------------------

int find_sum1(int a[], int length)
{
	int sum1=0, calc=0, i;

	printf("The numbers for sum1 are ");
	for (i = ( length-2 ); i >= 0; i-=2 )
	{
		//For loop to calculate sum1 of the Luhn Algorithm.
		//sum1 will ignore the checkdigit (end digit),
		//and add the rightmost digit with itself.
		//
		//The result is added to a total sum.  If the result 
		//is over 10, only the second digit will be added.
		//The formula repeats every 2 digits to the left until 0.
		calc = (a[i]+a[i]);
	
		if (calc >= 10)
		{
			//If the sum of this digit > 10, 
			calc = (calc-10)+1;
			//subtract 10 and add 1
		}
		printf("%i ", calc);
		sum1 += calc;
	} 

	return sum1;
}

int find_sum2(int a[], int length)
{
	int sum2=0, i;

	printf("The numbers for sum2 are ");
	for (i = ( length-3 ); i >= 0; i-=2)
	{
		//For loop to ignore the check digit,
		//and find total of all OTHER digits.
		printf("%i ", a[i]);
		sum2 += a[i];
	}
	return sum2;
}