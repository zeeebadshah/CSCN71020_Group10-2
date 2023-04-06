#include "pch.h"
#include "CppUnitTest.h"
#include "../PolygonChecker/triangleSolver.h"
#include "../PolygonChecker/triangleSolver.c"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace TriangleSolverTests
{
	TEST_CLASS(AnalyzeTriangleTests)
	{
	public:
		TEST_METHOD(NotATriangleTest)
		{
			int side1 = 0, side2 = 0, side3 = 0;
			char* expectedResult = "Not a triangle";
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(EquilateralTriangleTest)
		{

			int side1 = 5, side2 = 5, side3 = 5;
			char* expectedResult = "Equilateral triangle";
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(IsoscelesTriangleTest)
		{
			int side1 = 5, side2 = 5, side3 = 8;
			char* expectedResult = "Isosceles triangle";
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(ScaleneTriangleTest)
		{
			int side1 = 3, side2 = 4, side3 = 5;
			char* expectedResult = "Scalene triangle";
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual(expectedResult, result);
		}
	};
}