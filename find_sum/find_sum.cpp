﻿//Дан отсортированный массив чисел, включая отрицательные, и некое число K.
//Нужно найти два числа из массива, которые в сумме дадут число K.
//Если таких чисел нет, в результате возвращаем пустой массив.
//Если комбинаций чисел, дающих нужную сумму, несколько, возвращаем любую из них.
#include <iostream>
#include <array>

std::pair<int, int> find_sum_term(const std::set<int>& s, const int& sum)
{
    //найти ближайшее к сумме число и к нулю в массиве и пытаться складывать, двигаясь вокруг этих чисел
    
}

int main()
{
    std::array<int> s;
    for (size_t i = 0; i < 50; i++) s.insert(rand() % 200 - 100);
    for(int i:s) std::cout <<i<< " ";
    std::cout << std::endl << "size = " << s.size();
    
    int K = rand() % 200 - 100;
    std::cout << std::endl << "K = " << K;

}

