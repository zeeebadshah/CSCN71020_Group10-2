#include "pch.h"
#include "CppUnitTest.h"
#include "../polygonChecker/rectangleSolver.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace rectangleSolverTests
{
    TEST_CLASS(DistanceTests) //Test Class to test the DistanceTests function
    {
    public:

        TEST_METHOD(TestDistanceWithPositiveValues) //Unit Test to check the distance calculation with positive values
        {
            // Arrange - Variable Initialization
            int x1 = 0;
            int y1 = 0;
            int x2 = 3;
            int y2 = 4;
            double expected = 5.0; //The expected result from the function

            // Act - Test Performed
            double result = distance(x1, y1, x2, y2); //The actual result from the function

            // Assert - Verification/Comparison
            Assert::AreEqual(expected, result); //Assert to Check if expected is equal to result 
        }

        TEST_METHOD(TestDistanceWithNegativeValues) //Unit Test to check the distance calculation with negative values
        {
            // Arrange - Variable Initialization
            int x1 = -2;
            int y1 = 3;
            int x2 = 1;
            int y2 = -2;
            double expected = 5.830951894845301; //The expected result from the function

            // Act
            double result = distance(x1, y1, x2, y2);  //The actual result from the function

            // Assert
            Assert::AreEqual(expected, result); //Assert to Check if expected is equal to result 
        }

        TEST_METHOD(TestDistanceWithZeroValues) //Unit Test to check the distance calculation with all values set to '0' 
        {
            // Arrange - Variable Initialization
            int x1 = 0;
            int y1 = 0;
            int x2 = 0;
            int y2 = 0;
            double expected = 0.0; //The expected result from the function

            // Act
            double result = distance(x1, y1, x2, y2);  //The actual result from the function

            // Assert
            Assert::AreEqual(expected, result); //Assert to Check if expected is equal to result 
        }
    };
}
