#include "pch.h"
#include "CppUnitTest.h"
#include "../BCSRec/main.h"
extern "C" {
    int getArea(int *length, int *width);
    int getPerimeter(int *length, int *width);
}


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleUnitTest
{
	TEST_CLASS(RectangleUnitTest)
	{
	public:

		TEST_METHOD(TestGetArea)
		{
			// Arrange
			int length = 5;
			int width = 10;

			// Act
			int area = getArea(&length, &width);

			// Assert
			Assert::AreEqual(50, area); // 5 * 10 = 50
		}

		TEST_METHOD(TestGetPerimeter)
		{
			// Arrange
			int length = 5;
			int width = 10;

			// Act
			int perimeter = getPerimeter(&length, &width);

			// Debugging output
			printf("Computed Perimeter: %d\n", perimeter);
			printf("Length: %d, Width: %d\n", length, width);

			// Assert
			Assert::AreEqual(30, perimeter); // 2 * (5 + 10) = 30
		}

	};
}