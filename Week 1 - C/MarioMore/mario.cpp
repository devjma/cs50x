//harvard cs50x2024
#include <iostream>

void DrawLeftPyramid(int height)
{
	//skip the line
	for (int i = 1; i <= height; i++)
	{
		//draw blank spaces
		for (int j = 0; j < (height - i); j++)
		{
			printf(" ");
		}
		//draw blocks
		for (int j = 0; j < i; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}

void DrawFullPyramid(int height)
{
	//skip the line
	for (int i = 0; i < height; i++)
	{
		//left pyramid
		{
			//draw blank spaces
			for (int j = 0; j < height-(i+1); j++)
			{
				printf(" ");
			}
			//draw blocks
			for (int j = 0; j < (i + 1); j++)
			{
				printf("#");
			}
		}
		//space between them
		printf(" ");

		//right pyramid
		{
			for (int j = 0; j < (i+1); j++)
			{
				printf("#");
			}
		}

		printf("\n");
	}
}

int main()
{
	int height;
	do {
		printf("Height: ");
		std::cin >> height;
	} while (height < 1 || height > 8);

	DrawFullPyramid(height);

	return 0;
}