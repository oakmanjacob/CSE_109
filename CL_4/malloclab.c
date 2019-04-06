/**
 * CSE 109
 * Class lab 4
 * Jacob Oakman
 */

#include <stdio.h>
#include <stdlib.h>

double *multiplyByTwo(double *input)
{
	double *twice = malloc(sizeof(double));
	*twice = *input * 2.0;
	return twice;
}

int main(int argc, char *argv[])
{
	int *age = malloc(sizeof(int));
	*age = 30;
	// age is never used after this point so it is immediately deallocated
	free(age);

	double *salary = malloc(sizeof(double));
	*salary = 12345.67;

	double *myList = malloc(3 * sizeof(double));
	myList[0] = 1.2;
	myList[1] = 2.3;
	myList[2] = 3.4;
	// myList is never used after this point so it is immediately deallocated
	free(myList);

	double *result = multiplyByTwo(salary);
	printf("double your salary is %.3f\n", *result);

	free(salary);
	free(result);

	return 0;
}