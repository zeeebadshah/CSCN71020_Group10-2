#include "pch.h"
#include "CppUnitTest.h"
#include "../polygonChecker/rectangleSolver.h"
#include "../polygonChecker/rectangleSolver.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleSolverTests
{
    TEST_CLASS(RectangleSolverTests)
    {
    public:

        TEST_METHOD(ValidRectangle)
        {
            // Arrange
            int x1 = 0, y1 = 0, x2 = 0, y2 = 5, x3 = 5, y3 = 5, x4 = 5, y4 = 0;
            char expected[] = "Rectangle";

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(InvalidRectangle)
        {
            // Arrange
            int x1 = 0, y1 = 0, x2 = 0, y2 = 5, x3 = 5, y3 = 5, x4 = 5, y4 = 5;
            char expected[] = "Not a Rectangle";

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual(expected, result);
        }
    };

}