#include "pch.h"
#include "CppUnitTest.h"
#include "../BCSRec/main.h"

extern "C" {
    int getArea(int* length, int* width);
    int getPerimeter(int* length, int* width);
    void setLength(int input, int* length);
    void setWidth(int input, int* width);
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

        TEST_METHOD(TestSetLengthValid)
        {
            // Arrange
            int length = 0; // Initial length
            int newLength = 20;

            // Act
            setLength(newLength, &length);

            // Assert
            Assert::AreEqual(newLength, length); // Length should now be 20
        }

        TEST_METHOD(TestSetLengthInvalidNegative)
        {
            // Arrange
            int length = 10; // Initial length
            int newLength = -5; // Invalid length

            // Act
            setLength(newLength, &length);

            // Assert
            Assert::AreEqual(10, length); // Length should not change
        }

        TEST_METHOD(TestSetLengthInvalidTooLarge)
        {
            // Arrange
            int length = 10; // Initial length
            int newLength = 105; // Invalid length, out of range

            // Act
            setLength(newLength, &length);

            // Assert
            Assert::AreEqual(10, length); // Length should not change
        }

        TEST_METHOD(TestSetWidthValid)
        {
            // Arrange
            int width = 0; // Initial width
            int newWidth = 30;

            // Act
            setWidth(newWidth, &width);

            // Assert
            Assert::AreEqual(newWidth, width); // Width should now be 30
        }

        TEST_METHOD(TestSetWidthInvalidZero)
        {
            // Arrange
            int width = 10; // Initial width
            int newWidth = 0; // Invalid width

            // Act
            setWidth(newWidth, &width);

            // Assert
            Assert::AreEqual(10, width); // Width should not change
        }

        TEST_METHOD(TestSetWidthInvalidTooLarge)
        {
            // Arrange
            int width = 10; // Initial width
            int newWidth = 200; // Invalid width, out of range

            // Act
            setWidth(newWidth, &width);

            // Assert
            Assert::AreEqual(10, width); // Width should not change
        }
    };
}
