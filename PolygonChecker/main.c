#include <stdio.h>
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

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();


		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 2:
			//Added Recatangle Function that takes input as X,Y co-ordinates
			printf_s("Rectangle selected.\n");
			int rectanglePoints[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
			int* rectanglePointsPtr = getRectanglePoints(rectanglePoints);
			char* rectangleResult = analyzeRectangle(rectanglePointsPtr[0], rectanglePointsPtr[1], rectanglePointsPtr[2], rectanglePointsPtr[3], rectanglePointsPtr[4], rectanglePointsPtr[5], rectanglePointsPtr[6], rectanglePointsPtr[7]);
			printf_s("%s\n", rectangleResult);
			break;
		case 3:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n"); //New choice added in menu 
	printf_s("3. Exit\n");

	int shapeChoice;

	//Validates Input
	printf_s("Enter number: ");
	if (scanf_s("%d", &shapeChoice) != 1) {
		printf("Your input is invalid !!");
		exit(0);
	}

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		if (scanf_s("%d", &triangleSides[i]) != 1) {
			printf("Your input is invalid !!");
			exit(0);
		}
	}
	return triangleSides;
}

//Prompt the user to give inputs as X,Y co-ordinates in case of rectangle 
//Also validates input
int* getRectanglePoints(int* rectanglePoints) {
	printf_s("Enter the four points of the rectangle as x,y pairs (e.g. 1,2 3,4 5,6 7,8): ");
	for (int i = 0; i < 8; i++)
	{
		if (scanf_s("%d,", &rectanglePoints[i]) != 1) {
			printf("Invalid Input Entered!!");
			exit(0);
		}
	}
	return rectanglePoints;
}