#include <stdio.h>
#include <stdbool.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "triangleSolver.h"

//This function provides us with the type of triangle based on its sides and also returns its angles 
char* analyzeTriangle(int side1, int side2, int side3) {
    char* result = "";
    if (side1 <= 0 || side2 <= 0 || side3 <= 0 || side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) { //Checks if the given input forms a triangle or not
        result = "Not a triangle";

    }
    else if (side1 == side2 && side1 == side3) { //Checks if the given input forms an equilateral triangle
        result = "Equilateral triangle";
        getInsideAngle(side1, side2, side3); //Passes sides into function and prints to console

    }
    else if ((side1 == side2 && side1 != side3) || (side2 == side3 && side2 != side1)) { //Checks if the given input forms an isoceles triangle
        result = "Isosceles triangle";
        getInsideAngle(side1, side2, side3); //Passes sides into function and prints to console

    }
    else {
        result = "Scalene triangle"; // If the input does not form either an equilateral or an isosceles triangle, it must be a scalene triangle
        getInsideAngle(side1, side2, side3); //Passes sides into function and prints to console

    }

    return result; //Return the string result
}

//Gives us the inside angle of the triangle 
void getInsideAngle(double side1, double side2, double side3) {
    double A, B, C, radian, s, area; //Variables
    s = (side1 + side2 + side3) / 2; // Calculates the semi-perimeter of the triangle

    //Using Formula 
    area = sqrt(s * (s - side1) * (s - side2) * (s - side3)); // Calculates the area of the triangle using Heron's formula
    radian = (side1 * side2 * side3) / (4 * area); // Calculates the radius of the circumcircle of the triangle using the formula R = abc/4A, where a,b, and c are the sides of the triangle and A is the area

    double radian2 = radian * 2.0; //Calculates the inside angles of the triangle using the radius and sine rule

    if (side1 > radian2) { //Check if the first side is longer than 2 times the radius
        A = 180 / M_PI;
    }
    else { //otherwise, use the sine rule to calculate angle A in radians and convert to degrees
        A = (180 / M_PI) * asin(side1 / radian2);
    }
    if (side2 > radian2) { //Check if the second side is longer than 2 times the radius
        B = 180 / M_PI; // if true, set angle B to 90 degrees
    }
    else { // otherwise, use the sine rule to calculate angle B in radians and convert to degrees
        B = (180 / M_PI) * asin(side2 / radian2);
    }
    if (side3 > radian2) { //Check if the third side is longer than 2 times the radius
        C = 180 / M_PI; //if true, set angle C to 90 degrees
    }
    else {
        C = (180 / M_PI) * asin(side3 / radian2); // otherwise, use the sine rule to calculate angle C in radians and convert to degrees
    }

    printf("Angles are : %.2f %.2f %3.2f \n", A, B, C); //Prints the calculated angles of the triangle to two decimal points.
}
