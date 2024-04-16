//Дан отсортированный массив чисел, включая отрицательные, и некое число K.
//Нужно найти два числа из массива, которые в сумме дадут число K.
//Если таких чисел нет, в результате возвращаем пустой массив.
//Если комбинаций чисел, дающих нужную сумму, несколько, возвращаем любую из них.
#include <iostream>
#include <algorithm>
#include "finder.h"

int main()
{
    const size_t arr_size = 20;
    std::array<int, arr_size> ar;
    srand(time(NULL));
    for (size_t i = 0; i < arr_size; i++) ar[i] =rand() % 200 - 100;
    std::sort(ar.begin(),ar.end());
    for(int i:ar) std::cout <<i<< " ";
    
    int K = rand() % 200 - 100;
    std::cout << std::endl << "K = " << K<<std::endl;

    std::vector<int> res = find_sum_term(ar, K);
    if (res.empty()) std::cout << "\nThere are not members at array as terms of " << K << std::endl;
    else std::cout << res[0] << "+" << res[1] << "=" << K;

}

