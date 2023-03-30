#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "rectangleSolver.h"

double distance(int x1, int y1, int x2, int y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

char* analyzeRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    char* result = "";
    double side1 = distance(x1, y1, x2, y2);
    double side2 = distance(x2, y2, x3, y3);
    double side3 = distance(x3, y3, x4, y4);
    double side4 = distance(x4, y4, x1, y1);
    double diag1 = distance(x1, y1, x3, y3);
    double diag2 = distance(x2, y2, x4, y4);

    if (side1 <= 0 || side2 <= 0 || side3 <= 0 || side4 <= 0) {
        result = "Not a Rectangle";
    }
    else {
        result = "Rectangle";
        double perimeter = side1 + side2 + side3 + side4;
        double area = side1 * side2;
        printf("Yes the given points forms a rectangle\n");
        printf("Perimeter: %.2lf\n", perimeter);
        printf("Area: %.2lf\n", area);
    }
}