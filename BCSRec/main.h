#pragma once

#ifdef __cplusplus
extern "C" {
#endif

	void setLength(int input, int* length);
	void setWidth(int input, int* width);
	int getPerimeter(int* length, int* width);
	int getArea(int* length, int* width);
	void printWelcomeMenu();
	void printOptions();
	int getIntInput(char message[]);

#ifdef __cplusplus
}
#endif
