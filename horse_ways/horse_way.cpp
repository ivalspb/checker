#include <iostream>
#include <vector>
#include <stack>

bool move_vert(std::vector<std::vector<size_t>>& t, size_t i, size_t j)
{
	if (i + 1 < t.size() && j + 2 < t[0].size())
	{
		i++;
		j += 2;
		return true;
	}
	return false;
}

bool move_horiz(std::vector<std::vector<size_t>>& t, size_t i, size_t j)
{
	if (i + 2 < t.size() && j + 1 < t[0].size())
	{
		i+=2;
		j++;
		return true;
	}
	return false;
}


int main()
{
	size_t N,M;
	std::cin >> N >> M;
	std::vector<std::vector<size_t>>t(N, std::vector<size_t>(M));
	size_t ways_count = 0;
	std::stack<std::pair<size_t, size_t>>s;

	return 0;
}