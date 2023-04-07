#include "pch.h"
#include "CppUnitTest.h"
#include "../polygonChecker/rectangleSolver.h"
#include "../polygonChecker/rectangleSolver.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleSolverTests
{
    TEST_CLASS(RectangleSolverTests) //Test Class to test the Rectangle Solver function 'analyzeRectangle'
    {
    public:

        TEST_METHOD(ValidRectangle) //Unit Test to check if non-problematic input will lead to the correct string result 
        {
            // Arrange - Initalization
            int x1 = 0, y1 = 0, x2 = 0, y2 = 5, x3 = 5, y3 = 5, x4 = 5, y4 = 0;
            char expected[] = "Rectangle"; //Expected Result

            // Act - Test Performed
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4); //Actual Result

            // Assert - Verification/Comparison
            Assert::AreEqual(expected, result); //Assert to Check if expected is equal to result 
        }

        TEST_METHOD(InvalidRectangle) //Unit Test to check if problematic input will lead to the correct string result
        {
            // Arrange - Initalization
            int x1 = 0, y1 = 0, x2 = 0, y2 = 5, x3 = 5, y3 = 5, x4 = 5, y4 = 5;
            char expected[] = "Not a Rectangle"; //Expected Result

            // Act - Test Performed
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4); //Actual Result

            // Assert - Verification/Comparison
            Assert::AreEqual(expected, result); //Assert to Check if expected is equal to result 
        }
    };

}