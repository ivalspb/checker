// unix_path_canonical.cpp : This file contains the 'main' function. Program execution begins and ends there.
//begin from /
//separate single /
//can't end with / exept root dir
//can't contain . or ..

#include <iostream>
#include <string>
#include <stack>

bool my_make_canonical_path(std::string& path) 
{
	if (path.empty() || path[0] != '/') return false;
    std::string dir;
    std::stack<std::string> dirs;
    for (auto chars : path)
    {
		if (chars == '/') 
        {
            if(!dir.empty()) dirs.push(dir);
            dir.clear();
        }
        else if (chars == '.')
        {
            if (dir == ".")
            {
                dir.clear();
                if(!dirs.empty()) dirs.pop();
            }
        }
    }
	return true;
}

int main()
{
    std::cout << "Hello World!\n";
}

