#pragma once
#include <array>

template <typename T, size_t SIZE>
size_t find_index_nearest_up(const std::array<T, SIZE>& ar, const int& val)
{
    if (!SIZE) return 0;
    if (val < ar[0]||SIZE==1) return 0;
    if (val>ar[SIZE - 1]) return SIZE-1;
    size_t begin=0,end = SIZE-1;
    while (ar[end]!=val)
    {
        if (ar[end] > val && ar[end - 1] < val) break;
        if (ar[(end - begin) / 2] > val) end = (end - begin) / 2;
        else begin = (end-begin) / 2;
    }
    return end;
}

template <typename T, size_t SIZE>
std::pair<T, T> find_sum_term(const std::array<T, SIZE>& ar, const T& sum)
{
    //найти ближайшее к сумме число и к нулю в массиве и пытаться складывать, двигаясь вокруг этих чисел
    size_t term1_i = find_nearest_up(sum), term0_i = find_nearest_up(0);
    T delta = abs(ar[term1_i] + ar[term0_i] - sum);
    if (!delta) return { ar[term1_i],ar[term0_i] };

    size_t term0_up_lim, term0_bottom_limit, term1_up_lim, term1_bottom_limit;
    bool up_direction = true;
    if(term1_i>term0_i)
    {
        //choose direction
        term0_bottom_limit = 0;
        term0_up_lim = term1_i;
        term1_up_lim = SIZE - 1;
        term1_bottom_limit = term0_i;
    }
    //так как массив упорядочен, двигаемся либо наружу либо внутрь, пока дельта меньше
    //пробуем двигаться сначала одним, потом другим
    for(size_t i=term1_i; i<term1_up_lim;i++)
}
