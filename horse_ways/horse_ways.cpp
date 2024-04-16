#include <iostream>
#include <string>
#include <vector>
#include <stack>

bool vert_step(std::vector<std::vector<int>>& t, size_t& i, size_t& j)
{
	if (t.size() > i + 2 && t[0].size() > j + 1)
	{
		i += 2;
		j++;
		return true;
	}
	return false;
}

bool horiz_step(std::vector<std::vector<int>>& t, size_t& i, size_t& j)
{
	if (t.size() > i + 1 && t[0].size() > j + 2)
	{
		i++;
		j+=2;
		return true;
	}
	return false;

}

bool another_way

int main()
{
	size_t stroki, stolbc;
	std::cin >> stroki >> stolbc;
	std::vector<std::vector<int>>t(stroki, std::vector<int>(stolbc));
	std::stack<std::pair<int, int>>s;

	return 0;
}