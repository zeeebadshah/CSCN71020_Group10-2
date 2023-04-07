#include "pch.h"
#include "CppUnitTest.h"
#include "../PolygonChecker/triangleSolver.h"
#include "../PolygonChecker/triangleSolver.c"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace TriangleSolverTests
{
	TEST_CLASS(AnalyzeTriangleTests) //Test Class to test the AnalyzeTriangleTests function

	{
	public:
		TEST_METHOD(NotATriangleTest) //Unit Test to check if result will be the string "Not a triangle" while sides are all '0'
		{
			int side1 = 0, side2 = 0, side3 = 0; //Initalized sides to '0'
			char* expectedResult = "Not a triangle"; //Expected Result
			char* result = analyzeTriangle(side1, side2, side3); //Actual Result 
			Assert::AreEqual(expectedResult, result); //Assert to Check if Actual is equal to Result
		}

		TEST_METHOD(EquilateralTriangleTest) //Unit Test to check if result will be the string "Equilateral triangle" while sides are all equal to each other
		{

			int side1 = 5, side2 = 5, side3 = 5; //Initalized sides to '5'
			char* expectedResult = "Equilateral triangle"; //Expected Result
			char* result = analyzeTriangle(side1, side2, side3); //Actual Result 
			Assert::AreEqual(expectedResult, result); //Assert to Check if Actual is equal to Result
		}

		TEST_METHOD(IsoscelesTriangleTest) //Unit Test to check if result will be the string "Isoceles triangle" while two sides are equal and one side is greater in dimension
		{
			int side1 = 5, side2 = 5, side3 = 8; //Two sides initalized to '5' and one initalized '8'
			char* expectedResult = "Isosceles triangle"; //Expected Result
			char* result = analyzeTriangle(side1, side2, side3); //Actual Result 
			Assert::AreEqual(expectedResult, result); //Assert to Check if Actual is equal to Result
		}

		TEST_METHOD(ScaleneTriangleTest) //Unit Test to check if result will be the string "Scalene triangle" while all sides are unequal to each other but greater than '0'
		{
			int side1 = 3, side2 = 4, side3 = 5; //Sides are initialized uniquely to '3, 4, 5'
			char* expectedResult = "Scalene triangle"; //Expected Result
			char* result = analyzeTriangle(side1, side2, side3); //Actual Result 
			Assert::AreEqual(expectedResult, result); //Assert to Check if Actual is equal to Result
		}
	};
}