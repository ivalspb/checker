// build_stairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//i-step consist from i blocks
//from N blocks find step number

#include <iostream>

size_t steps_number(size_t blocks)
{
    size_t cur_blocks = 0, steps = 0;
    for (; cur_blocks < blocks; )
    {
        cur_blocks += ++steps;
    }
    if (cur_blocks != blocks) steps--;
    return steps;
}

int main()
{
    size_t blocks;
    std::cout << "blocks number = ";
    std::cin >> blocks;
    std::cout << "\nsteps = "<<steps_number(blocks);
}


