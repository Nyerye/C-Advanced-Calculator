#include <stdio.h>
#include <corecrt_math.h>
#include <string.h>
#include "calculatorFunctionFile.h"

//
// FUNCTION : modeSelect
// DESCRIPTION : This function takes the value of choice and confimed to the user the mode in which they have entered on the calculator.
// PARAMETERS :  int modeNumber
// RETURNS : nothing. Simnply only prints out a line of text for each corresponding mode. If its invalid or is e, it lets the while loop do the printing. 
//
void modeSelect(void) {
	//Declaring all local variables used in the process. Initializing choice to be zero to enter the while loop. 
	char choice[100] = {};
	int length = 0;
	int sentinelValue = 1;
	double firstNum, secondNum, baseNum, powerOf, rootNumber;
	double addSum, subSum, multiSum, divSum, modSum, expSum, squareSum = 0;
	while (sentinelValue == 1) {

		//Asking the user to enter in the string they want evaluated.
		printf("Select the operation you would like to perform by entering it's corresponding number:\n");
		printf("Addition (+)\nSubtraction (-)\nMultiplication (*)\nDivision (/)\nModulus (%%)\nExponentiation (^)\nSquare Root (r)\nExit (e)\nNewton Sqaure (n)\n");
		fgets(choice, sizeof(choice), stdin);

		//Remove newline character from fgets and adding null terminator.
		choice[strcspn(choice, "\n")] = '\0';

		// Validate that the first character is a valid operation
		char choiceKey = choice[0];

		// Check if the input is a single valid character. If its higher, ignore it. 
		if (strlen(choice) > 1) {
			printf("Invalid input. Please enter a single character corresponding to the operation.\n");
			continue;
		}

		//Choice 1: Addition
		if (choiceKey == '+') {
			firstNum = firstNumber();
			secondNum = secondNumber();
			addSum = addition(firstNum, secondNum);
			printf("The total of the %f and %f added is %.4f\n", firstNum, secondNum, addSum);
		}

		//Choice 2: Subtraction
		else if (choiceKey == '-') {
			firstNum = firstNumber();
			secondNum = secondNumber();
			subSum = subtraction(firstNum, secondNum);
			printf("The total of the %f and %f subtracted is %.4f\n", firstNum, secondNum, subSum);
		}

		//Choice 3: Multiplication.
		else if (choiceKey == '*') {
			firstNum = firstNumber();
			secondNum = secondNumber();
			multiSum = multiplication(firstNum, secondNum);
			printf("The total of the %f and %f multiplied is %.4f\n", firstNum, secondNum, multiSum);
		}

		//Choice 4: Division
		else if (choiceKey == '/') {
			firstNum = firstNumber();
			secondNum = secondNumber();
			divSum = division(firstNum, secondNum);
			if (divSum == 0) {
				printf("No zeros are allowed in division!\n");
			}
			else {
				printf("The total of the %f and %f subtracted is %.4f\n", firstNum, secondNum, divSum);
			}
		}

		//Choice 5: Modulus.
		else if (choiceKey == '%') {
			firstNum = firstNumber();
			secondNum = secondNumber();
			int modFirst = int(firstNum);
			int modSecond = int(secondNum);
			modSum = modulus(modFirst, secondNum);
			printf("The total of the %f and %f after modulus is %.4f\n", firstNum, secondNum, modSum);
		}

		//Choice 6: Exponents.
		else if (choiceKey == '^') {
			baseNum = baseNumber();
			powerOf = toPower();
			expSum = exponents(baseNum, powerOf);
			printf("The total of the %.4f and %.4f after exponents is %.4f\n", baseNum, powerOf, expSum);
		}

		//Choice 7: Square Roots.
		else if (choiceKey == 'r') {
			rootNumber = rootOf();
			squareSum = squareRoot(rootNumber);
			if (squareSum == -1) {

			}
			else {
				printf("The square root of %.4f is %.4f\n", rootNumber, squareSum);
			}
		}

		//Choice 8: Program Termination.
		else if (choiceKey == 'e') {
			printf("Program terminated.");
			break;
		}

		//Bonus: homemade square root calculation.
		else if (choiceKey == 'n') {
			rootNumber = rootOf();
			squareSum = newtonSquare(rootNumber);
			if (squareSum == -1) {

			}
			else {
				printf("The square root of %.4f is %.4f\n", rootNumber, squareSum);
			}
		}
	}
}
//
// FUNCTION : firstNumber
// DESCRIPTION : This function takes a user inputted double value and stores it in memory. Will check to confirm that the number entered is a valid data type choice. 
// PARAMETERS : none.
// RETURNS : num1 ( a double value). 
// 
double firstNumber(void) {
	double num1;
	int answer;
	int sentinelValue = 1;
	while (sentinelValue == 1) {
		printf("Enter the first number you want to use: \n");
		answer = scanf_s("%lf", &num1);
		if (answer == 1) {
			cleanBuffer();
			return num1;
		}
		else {
			printf("Invalid input. Please enter a valid integer.\n");
			cleanBuffer();
		}
	}
}
//
// FUNCTION : secondNumber
// DESCRIPTION : This function takes a user inputted integer and converts it into a double value.
// PARAMETERS : none.
// RETURNS : num2 ( a double value). 
// 
double secondNumber(void) {
	double num2;
	int answer;
	int sentinelValue = 1;
	while (sentinelValue == 1) {
		printf("Enter the second number you want to use: \n");
		answer = scanf_s("%lf", &num2);
		if (answer == 1) {
			cleanBuffer();
			return num2;
		}
		else {
			printf("Invalid input. Please enter a valid integer.\n");
			cleanBuffer();
		}
	}
}


//
// FUNCTION : baseNumber
// DESCRIPTION : This function takes a user inputted integer and converts it into a double value. To be 
//				 used in the exponents function as the base number.
// PARAMETERS : none.
// RETURNS : baseNum ( a double value).
//
double baseNumber(void) {
	double baseNum;
	int answer;
	int sentinelValue = 1;
	while (sentinelValue == 1) {
		printf("Enter the base number you want to use: \n");
		answer = scanf_s("%lf", &baseNum);
		if (answer == 1) {
			cleanBuffer();
			return baseNum;
		}
		else {
			printf("Invalid input. Please enter a valid integer.\n");
			cleanBuffer();
		}
	}
}

//
// FUNCTION : toPower
// DESCRIPTION : This function takes a user inputted integer and converts it into a double value. To be 
//				 used in the exponents function as the number applied to the base.
// PARAMETERS : none.
// RETURNS : powerOf ( a double value).
//
double toPower(void) {
	double powerOf;
	int answer;
	int sentinelValue = 1;
	while (sentinelValue == 1) {
		printf("Enter the power you want to apply to the base number: \n");
		answer = scanf_s("%lf", &powerOf);
		if (answer == 1) {
			cleanBuffer();
			return powerOf;
		}
		else {
			printf("Invalid input. Please enter a valid integer.\n");
			cleanBuffer();
		}
	}
}

//
// FUNCTION : rootOf
// DESCRIPTION : This function takes a user inputted integer and converts it into a double value. To be 
//				 used in the square root function as the target number we want the square root of.
// PARAMETERS : none.
// RETURNS : rootNumber ( a double value). 
//
double rootOf(void) {
	double rootNumber;
	int answer;
	int sentinelValue = 1;
	while (sentinelValue == 1) {
		printf("Enter the number you want the root of: \n");
		answer = scanf_s("%lf", &rootNumber);
		if (answer == 1) {
			cleanBuffer();
			return rootNumber;
		}
		else {
			printf("Invalid input. Please enter a valid integer.\n");
			cleanBuffer();
		}
	}
}


//
// FUNCTION : addition
// DESCRIPTION : The function takes in two double values, firstNum and secondNum, and adds them.
// PARAMETERS : double firstNum and double secondNum.
// RETURNS : addSum, a double value which is the sum of firstNum and secondNum added. 
// 
double addition(double firstNum, double secondNum) {
	double addSum = firstNum + secondNum;
	return addSum;
}

//
// FUNCTION : subtraction
// DESCRIPTION : The function takes in two double values, firstNum and secondNum, and subtracts them.
// PARAMETERS : double firstNum and double secondNum.
// RETURNS : subSum, a double value which is the sum of firstNum and secondNum subtracted. 
// 
double subtraction(double firstNum, double secondNum) {
	double subSum = firstNum - secondNum;
	return subSum;
}

//
// FUNCTION : multiplication
// DESCRIPTION : The function takes in two double values, firstNum and secondNum, and multiplies them.
// PARAMETERS : double firstNum and double secondNum.
// RETURNS : multiSum, a double value which is the sum of firstNum and secondNum multiplied. 
// 
double multiplication(double firstNum, double secondNum) {
	double multiSum = firstNum * secondNum;
	return multiSum;
}

//
// FUNCTION : division
// DESCRIPTION :The function takes in two double values, firstNum and secondNum, and divides them.
//				The function checks first using an if/else statement whether or not one of the 
//				the numbers is zero.If both numbers are not zero, then the program divides them and returns the sum.
// PARAMETERS : double firstNum and double secondNum.
// RETURNS : divSum, a double value which is the sum of firstNum and secondNum divided. 0 if one of the numbers is equal to zero.
// 
double division(double firstNum, double secondNum) {
	if (firstNum == 0 || secondNum == 0) {
		return 0;
	}
	else {
		double divSum = firstNum / secondNum;
		return divSum;
	}
}
//
// FUNCTION : modulus
// DESCRIPTION : The function takes in two double values, firstNum and secondNum, and applies the modulus operator to them.
// PARAMETERS : double firstNum and double secondNum.
// RETURNS : modSum, a double value which is the sum of firstNum and secondNum after modulus applied. 
// 
int modulus(int modFirst, int modSecond) {
	int modSum = modFirst % modSecond;
	return modSum;
}

//
// FUNCTION : exponents
// DESCRIPTION : The function takes in two double values, baseNum and powerOf, and uses the math.h function pow to calculate the sum..
// PARAMETERS : double firstNum and double secondNum.
// RETURNS : expSum, a double value which is the sum of firstNum and secondNum after modulus applied. 
// 
double exponents(double baseNum, double powerOf) {
	double expSum = 1;
	expSum = pow(baseNum, powerOf);
	return expSum;
}

//
// FUNCTION : squareRoot
// DESCRIPTION : The function takes in one double value, rootNumber, and uses the predefined sqrt function from math.h in order to calculate the square root. 
//				 The code will check to confirm that firstNum is greater than zero before any calculations are ran. 
// PARAMETERS : double rootNumber.
// RETURNS : squareSum, a double value, which is returned when firstNum is higher than zero. -1 if the number was detected to be equal to or less than zero. 
// 
double squareRoot(double rootNumber) {
	if (rootNumber > 0) {
		double squareSum = sqrt(rootNumber);
		return squareSum;
	}

	else {
		printf("You can not calculate the square root of zero or a negative number!\n");
		return -1;

	}
}

//For Darryl, before you told me I was allowed to use math.h
//
// FUNCTION : newtonSquare
// DESCRIPTION : The function takes a double value, num1, and then determines the "true" square root by first diving it in two as the Newton Raphson method does and then comparing
//				 it to a epsilon of 4 decimal place precision as instructed. As long as the guess (num1/2) times itself minus the user inputted number is greater than the epsilon of 0.0001 
//				 OR num1 minus guess times itself is greater than the epsilon, it will keep reducing itself until it eventually is no longer true and output what the closest value to 
//				 the square root is (it is not always perfect each time I imagine). This mathematical method is used in modern day calculators, my epsilon is just smaller than what calculators use. 
//				 The program checks before the while logic that the number is greater than zero as square root of negative numbers or zero is not possible.
// PARAMETERS : double firstNum and double secondNum.
// RETURNS : guess if the conditions were met before running calculations. -1 if the conditions were not met.  
// 
double newtonSquare(double firstNum) {
	double guess = firstNum / 2.0;
	double epsilon = 0.0001;
	if (guess > 0) {
		while ((guess * guess - firstNum) > epsilon || (firstNum - guess * guess) > epsilon) {
			guess = (guess + firstNum / guess) / 2.0;
		}
		return guess;
	}
	else {
		printf("You can not calculate the square root of zero or a negative number!\n");
		return -1;
	}
}

//So, how did Nick figure this out? Alot of different sites for reference but this specific reddit article to understand more and make my code: https://www.reddit.com/r/askscience/comments/ehgviv/how_do_computerscalculators_find_the_square_roots/

//
// FUNCTION : cleanBuffer
// DESCRIPTION : https://stackoverflow.com/questions/7898215/how-can-i-clear-an-input-buffer-in-c
// This function clears any remaining characters in the input buffer,
// including newline characters, to prevent unintended inputs in future reads.
// PARAMETERS :
// None
// RETURNS :
// void : This function does not return a value.
//
void cleanBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}