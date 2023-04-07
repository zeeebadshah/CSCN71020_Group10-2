#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "rectangleSolver.h"


double distance(int x1, int y1, int x2, int y2) { //Calculates the distance between two points.
    double dx = x2 - x1; // Calculates difference in x-coordinates of the two points.
    double dy = y2 - y1; // Calculates difference in y-coordinates of the two points.
    return sqrt(dx * dx + dy * dy); //Return the value of the inputs after operations are applied with the distance formula  
}

char* analyzeRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) { //Indicates whether the inputs form a rectangle.
    char* result = "";
    double side1 = distance(x1, y1, x2, y2);  // Calculates the length of the first side of the rectangle using distance function.
    double side2 = distance(x2, y2, x3, y3);  // Calculates the length of the second side of the rectangle using distance function.
    double side3 = distance(x3, y3, x4, y4);  // Calculates the length of the third side of the rectangle using distance function.
    double side4 = distance(x4, y4, x1, y1);  // Calculates the length of the fourth side of the rectangle using distance function.
    double diag1 = distance(x1, y1, x3, y3);  // Calculates the length of the first diagonal using distance function.
    double diag2 = distance(x2, y2, x4, y4);  // Calculates the length of the second diagonal using distance function.

    if (side1 <= 0 || side2 <= 0 || side3 <= 0 || side4 <= 0) { //Checks if the lengths of all sides of the rectangle are positive, if not, input points do not form a rectangle.
        result = "Not a Rectangle";
    }

    else { //Calculates and prints the area and perimeter of the rectangle, and if the input points form a rectangle.
        result = "Rectangle"; //Shows that the input points form a rectangle
        double perimeter = side1 + side2 + side3 + side4; //Calculates perimeter of the rectangle
        double area = side1 * side2; //Calculates area of the rectangle
        printf("Yes the given points forms a rectangle\n");
        printf("Perimeter: %.2lf\n", perimeter); //Prints the perimeter of the rectangle.
        printf("Area: %.2lf\n", area); // Prints the area of the rectangle.
    }
    return result; //Returns the result indicating whether the input points form a rectangle or not.
}