#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Software Implmentation CSCN71020
//GroupProject - Group 10
//Members - Zahan Badshah - Leader 
//Mayank Ameti 
//Monil Patel
//Aditya Parab 
//Yahya Ali

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int side = 0; //Sides are by defaut initailized to '0'

int main() {
	bool continueProgram = true;
	while (continueProgram) { // Loop that continues while continueProgram is true
		printWelcome(); //Function call to the function used to display the welcome message 


		int shapeChoice = printShapeMenu(); // Get user's choice of shape by calling printShapeMenu function

		switch (shapeChoice) // Use a switch statement to determine the action based on the user's shape choice
		{
		case 1: // If the user chooses triangle, get the triangle's sides, analyze it and print the result
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;

		case 2: // If the user chooses rectangle, get the rectangle's points, analyze it and print the result
			printf_s("Rectangle selected.\n");
			int rectanglePoints[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
			int* rectanglePointsPtr = getRectanglePoints(rectanglePoints);
			char* rectangleResult = analyzeRectangle(rectanglePointsPtr[0], rectanglePointsPtr[1], rectanglePointsPtr[2], rectanglePointsPtr[3], rectanglePointsPtr[4], rectanglePointsPtr[5], rectanglePointsPtr[6], rectanglePointsPtr[7]);
			printf_s("%s\n", rectangleResult);
			break;

		case 3: // If the user chooses to exit, set continueProgram to false so the loop will terminate
			continueProgram = false;
			break;

		default: // If the user chooses an invalid option, print an error message
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() { //Function displayed at the Start of the Program Launch
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() { //Function displayed after printWelcome 
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("3. Exit\n");


	//Validates Input for ShapeChoice
	int shapeChoice;
	printf_s("Enter number: ");
	if (scanf_s("%d", &shapeChoice) != 1) {
		printf("Your input is invalid !!");
		exit(0);
	}

	return shapeChoice;  //Return the user's shape choice
}

int* getTriangleSides(int* triangleSides) { //This function prompts input of three sides of a triangle, stores input in array and validates input; exits program if invalid
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		if (scanf_s("%d", &triangleSides[i]) != 1) {
			printf("Your input is invalid !!");
			exit(0);
		}
	}
	return triangleSides; // Return the pointer to the array of triangle point values
}

int* getRectanglePoints(int* rectanglePoints) { //This function prompts input of four pairs of points for the rectangle, stores input in array and validates input; exits program if invalid
	printf_s("Enter the four points of the rectangle as x,y pairs (e.g. 1,2 3,4 5,6 7,8): ");
	for (int i = 0; i < 8; i++)
	{
		if (scanf_s("%d,", &rectanglePoints[i]) != 1) {
			printf("Invalid Input Entered!!");
			exit(0);
		}
	}
	return rectanglePoints; // Return the pointer to the array of rectangle point values
}