#include <iostream>

int GetCoinsNumber(int change);

int main()
{
	int change;
	do
	{
		printf("Change owed: ");
		std::cin >> change;
	} while (change < 1);

	printf("%i",GetCoinsNumber(change));

	return 0;
}

int GetCoinsNumber(int change)
{
	int coins[] = { 25,10,5,1};
	int global_count = 0;

	// get the minimum required coins for the change using simple algorithm
	for (int i = 0; i < 4; i++)
	{
		int count = change/coins[i];
		change -= count * coins[i];
		global_count += count;
	}

	return global_count;
}