#include "pch.h"
#include "CppUnitTest.h"
#include "../PolygonChecker/triangleSolver.h"
#include "../PolygonChecker/triangleSolver.c"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace InsideAngleUnitTest
{
	TEST_CLASS(InsideAngleUnitTest)
	{
	public:
		
		
		
            TEST_METHOD(TestGetInsideAngle_Scaline)
            {
                // Test data
                double side1 = 3.0;
                double side2 = 4.0;
                double side3 = 5.0;
                double expectedA = 36.87;
                double expectedB = 53.13;
                double expectedC = 90.00;

                // Call the function to get actual results
                getInsideAngle(side1, side2, side3);

                // Assert the results are as expected, with a tolerance of 0.01
                Assert::AreEqual(expectedA, A, 0.01);
                Assert::AreEqual(expectedB, B, 0.01);
                Assert::AreEqual(expectedC, C, 0.01);
            }

            TEST_METHOD(TestGetInsideAngle_Equilateral)
            {
                // Test data
                double side1 = 3.0;
                double side2 = 3.0;
                double side3 = 3.0;
                double expectedA = 60.00;
                double expectedB = 60.00;
                double expectedC = 60.00;

                // Call the function to get actual results
                getInsideAngle(side1, side2, side3);

                // Assert the results are as expected, with a tolerance of 0.01
                Assert::AreEqual(expectedA, A, 0.01);
                Assert::AreEqual(expectedB, B, 0.01);
                Assert::AreEqual(expectedC, C, 0.01);
            }

            TEST_METHOD(TestGetInsideAngle_Isoceles)
            {
                // Test data
                double side1 = 6.0;
                double side2 = 6.0;
                double side3 = 8.0;
                double expectedA = 48.19;
                double expectedB = 48.19;
                double expectedC = 83.62;

                // Call the function to get actual results
                getInsideAngle(side1, side2, side3);

                // Assert the results are as expected, with a tolerance of 0.01
                Assert::AreEqual(expectedA, A, 0.01);
                Assert::AreEqual(expectedB, B, 0.01);
                Assert::AreEqual(expectedC, C, 0.01);
            }
		
	};
}
