// warm_days.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Дан массив чисел, состоящий из N элементов.
//Эти числа обозначают температуру в конкретный день. 
//Для каждого дня нужно найти количество суток до наступления более тёплого дня.

#include <iostream>

int main()
{
	const size_t N = 10;
	int day_temp[N];
	for (int& i : day_temp)
	{
		i = rand() % 100 - 40;
		std::cout << i << "\t";
	}
	std::cout << "\n";
	size_t days_to_warm[N]{ 0 };
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = i + 1; j < N; j++)
		{
			if (day_temp[j] > day_temp[i])
			{
				days_to_warm[i] = j - i;
				break;
			}
		}
		std::cout << days_to_warm[i] << "\t";
	}
}

