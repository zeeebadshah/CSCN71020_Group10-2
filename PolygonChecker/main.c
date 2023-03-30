#include <stdio.h>
#include <stdbool.h>

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
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 2:
			printf_s("Rectangle selected.\n");
			int rectanglePoints[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
			int* rectanglePointsPtr = getRectanglePoints(rectanglePoints);
			char* rectangleResult = analyzeRectangle(rectanglePointsPtr[0], rectanglePointsPtr[1], rectanglePointsPtr[2], rectanglePointsPtr[3], rectanglePointsPtr[4], rectanglePointsPtr[5], rectanglePointsPtr[6], rectanglePointsPtr[7]);
			printf_s("%s\n", rectangleResult);
			break;
		case 0:
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
	printf_s("2. Rectangle\n");
	printf_s("3. Exit\n");

	int shapeChoice;

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