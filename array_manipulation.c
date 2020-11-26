#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array_manipulation.h"

int main(int argc, char *argv[]){

	//creates a double_array struct that holds a 6 row by 9 column array
	printf("This is the original 6 row by 9 column array:\n\n");
	struct Double_Array *myArray = doubleArray(6,9);
	randomizeArray(myArray, 23, 72);
	printArray(myArray);
	printf("\n");

	//randomly picks two row swaps and swaps the rows in the original array
	int a = rand() % 6;
	int b = rand() % 9;

	printf("Rows %d and %d of the original array have been swapped:\n\n", a, b);
	swapRows(myArray,a,b);
	printRowArray(myArray);
	printf("\n");

	//randomly picks two column swaps and swaps them
	int c = rand() % 6;
	int d = rand() % 9;

	printf("Columns %d and %d of the array have been swapped:\n\n",c,d);
	swapColumns(myArray,c,d);
	printArray(myArray);

	printf("\n\n\n\n");

	//frees all malloced memory before exiting the program
	freeArray(myArray);

	return 0;
}

//returns a pointer to a struct given the input for num rows and num columns
struct Double_Array *doubleArray(int row, int col){

	//allocates memory for the struct pointer
	struct Double_Array *myArray = malloc(sizeof(struct Double_Array));

	//sets row and col size of the struct
	myArray -> rowsize = row;
	myArray -> colsize = col;

	//allocates memory for the 2D array row elements
 	myArray -> array = malloc (row * sizeof(double*));

	//allocates memory for the 2D array column elements
	for (int i = 0; i < row; i++){
		myArray -> array[i] = malloc (col* sizeof(double));
	}
 
	return myArray;
}

//takes in Double_Array struct pointer and frees struct as well as the array in it
void freeArray(struct Double_Array *myArray){

	//frees each element in the struct array
	for (int i = 0; i < myArray -> rowsize; i++){
		free(myArray -> array[i]);
	}

	//frees the array then the struct pointer
	free(myArray -> array);
	free(myArray);
}

//takes Double_Array struct pointer and prints the array with each element to 1 decimal place
void printArray(struct Double_Array *myArray){

    for (int i = 0; i < myArray -> rowsize; i++){
        for (int j = 0; j < myArray -> colsize; j++){
            printf("%0.1f ", myArray -> array[i][j]);
        }
        printf("\n");
    }
	return;
}

struct Double_Array *printRowArray(struct Double_Array *swapRows){

    for (int i = 0; i < swapRows -> rowsize; i++){
        for (int j = 0; j < swapRows -> colsize; j++){
            printf("%0.1f ", swapRows -> array[i][j]);
        }
        printf("\n");
    }
	return 0;
}

//takes in the Double_Array struct and an upper and lower bound numbers to initialize the elements inside the struct array
struct Double_Array *randomizeArray(struct Double_Array *myArray, double a, double b){

	//initializes elements in the array to random values between the lower and upper bounds
	for (int i = 0; i < myArray -> rowsize; i++){
		for (int j = 0; j < myArray -> colsize; j++){
			myArray -> array[i][j] = ((double) rand() / (double) RAND_MAX) * (b - a) +a;
		}
	}
	return myArray;
}

//two columns in the struct array are swapped given that the function  integer inputs are valid
int  swapColumns(struct Double_Array *myArray, int x, int y){

	//if the integer inputs are valid based on the struct column and row size, rows are swapped
	if(x >= 0 && x <= myArray -> colsize && y >= 0 && y <= myArray -> colsize){

		double tempValue;

		//loops through each row and stores one of the chosen column elements in a temporary variable
		for(int i = 0; i < myArray -> rowsize; i++){

			tempValue = myArray -> array[i][x];
			myArray -> array[i][x] = myArray -> array[i][y];
			myArray -> array[i][y] = tempValue;
		}

		return 1;
	}
	else{
		return 0;
	}
}

//rows of the struct array are swapped given valid integer inputs
int  swapRows(struct Double_Array *myArray, int x, int y){

	//swaps rows of the array given valid input rows to swap
	if(x >= 0 && x <= myArray -> rowsize && y >= 0 && y <= myArray -> rowsize){

		double *tempValue = malloc(sizeof(double) * myArray -> colsize);

		tempValue = myArray -> array[x];
		myArray -> array[x] = myArray -> array[y];
		myArray -> array[y] = tempValue;

		//frees the temporary variable
		free(tempValue);

		return 1;
	}

	else{
		return 0;
	}
}

