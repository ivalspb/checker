#pragma once
#include <array>
#include <vector>

template <typename T, size_t SIZE>
std::vector<T> find_sum_term(const std::array<T, SIZE>& ar, const T& sum)
{
	std::vector<T> res;
	for (size_t i = 0, j = SIZE - 1; i < j;)
	{
		if (ar[i] + ar[j] == sum)
		{
			res.push_back(ar[i]);
			res.push_back(ar[j]);
			break;
		}
		else if (ar[i] + ar[j] > sum)
			j--;
		else
			i++;
	}
	return res;
}
