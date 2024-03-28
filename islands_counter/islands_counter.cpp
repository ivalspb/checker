#include <iostream>
#include <vector>
#include <stack>

struct point
{
    size_t x, y;
};

void print_lake(const std::vector<std::vector<int>>& lake)
{
    std::cout << std::endl;
	for (size_t i = 0; i < lake.size();i++)
    {
        for (size_t j = 0; j < lake[i].size(); j++)
            std::cout << lake[i][j] << " ";
		std::cout << std::endl;
    }
}

void mark_island(std::vector <std::vector<int>>& lake, const point& p, std::stack<point>& islands_points)
{
    if (lake[p.x][p.y]) 
    {
        islands_points.push(p);
        lake[p.x][p.y] = 0;
		if (p.x) 
            mark_island(lake, { p.x - 1, p.y }, islands_points);    
        if (p.y) 
            mark_island(lake, { p.x, p.y - 1 }, islands_points);
		if (p.x < lake.size() - 1) 
            mark_island(lake, { p.x + 1, p.y }, islands_points);
		if (p.y < lake.size() - 1) 
            mark_island(lake, { p.x, p.y + 1 }, islands_points);
    }

}

size_t islands_counter(std::vector<std::vector<int>> lake)
{
    std::stack<point> islands_points;
    size_t islands_counct = 0;
	print_lake(lake);
    for(size_t i=0;i<lake.size();i++)
        for (size_t j = 0; j < lake[i].size(); j++)
        {
            if (lake[i][j]) 
            {
                mark_island(lake, { i,j }, islands_points);
                islands_counct++;
                print_lake(lake);
                while (!islands_points.empty())
                {
                    point p = islands_points.top();
					lake[p.x][p.y] = 0;
                    islands_points.pop();
                }
            }
        }
    return islands_counct;
}

int main()
{
    std::vector < std::vector<int >> lake = {
       {0,1,0,1},
       {1,1,0,1},
       {0,0,0,0},
       {1,0,1,1},
    };
    std::cout << islands_counter(lake)<<std::endl;
    
    std::vector < std::vector<int >> lake2;
    std::cout << islands_counter(lake2);
    return 0;
}
