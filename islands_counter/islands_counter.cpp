#include <iostream>
#include <vector>
#include <stack>

struct point
{
    size_t x, y;
};

size_t islands_counter(std::vector<std::vector<int>> lake)
{
    std::stack<point> islands_points;
    size_t islands_counct = 0;
    for(size_t i=0;i<lake.size();i++)
        for (size_t j = 0; j < lake[i].size(); j++)
        {
            if (lake[i][j]) islands_points.push({ i,j });
        }
    while (!islands_points.empty())
    {
        point cur_point = islands_points.top();
        if ((cur_point.x && lake[cur_point.x - 1][cur_point.y]) ||
            (cur_point.y && lake[cur_point.x][cur_point.y - 1]) ||
            (cur_point.x < (lake.size() - 1) && lake[cur_point.x + 1][cur_point.y]) ||
            (cur_point.y < (lake[cur_point.x].size() - 1) && lake[cur_point.x][cur_point.y + 1]))
        {
            islands_points.pop();
            lake[cur_point.x][cur_point.y] = 0;
        }
        else 
        {
            islands_counct++;
            islands_points.pop();
        }

    }
    return islands_counct;
}

int main()
{
    std::vector < std::vector<int >> lake = {
       {0,0,0,0},
       {0,0,0,0},
       {0,0,0,1},
       {0,0,1,1},
    };
    std::cout << islands_counter(lake);
    return 0;

}
