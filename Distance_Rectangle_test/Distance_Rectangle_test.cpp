#include "pch.h"
#include "CppUnitTest.h"
#include "../polygonChecker/rectangleSolver.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace rectangleSolverTests
{
    TEST_CLASS(DistanceTests)
    {
    public:

        TEST_METHOD(TestDistanceWithPositiveValues)
        {
            // Arrange
            int x1 = 0;
            int y1 = 0;
            int x2 = 3;
            int y2 = 4;
            double expected = 5.0;

            // Act
            double result = distance(x1, y1, x2, y2);

            // Assert
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestDistanceWithNegativeValues)
        {
            // Arrange
            int x1 = -2;
            int y1 = 3;
            int x2 = 1;
            int y2 = -2;
            double expected = 5.830951894845301;

            // Act
            double result = distance(x1, y1, x2, y2);

            // Assert
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestDistanceWithZeroValues)
        {
            // Arrange
            int x1 = 0;
            int y1 = 0;
            int x2 = 0;
            int y2 = 0;
            double expected = 0.0;

            // Act
            double result = distance(x1, y1, x2, y2);

            // Assert
            Assert::AreEqual(expected, result);
        }
    };
}
