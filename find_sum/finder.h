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
    T delta_cur{}, delta = abs(ar[term1_i] + ar[term0_i] - sum);
    if (!delta) return { ar[term1_i],ar[term0_i] };

    int term0_up_lim, term0_bottom_lim, term1_up_lim, term1_bottom_lim,term0_delta,term1_delta;
    for(bool out_direction = true;out_direction;out_direction--)
    {
        if (sum > 0 && out_direction)//0....term0_i...term1_i....SIZE - 1
        {                            //  <<<                 >>>>
            term0_bottom_lim = term0_i;
            term0_up_lim = -1;
            term1_up_lim = SIZE;
            term1_bottom_lim = term1_i;
            term0_delta = 1;
            term1_delta = -1;
        }
        else if(sum<=0 && out_direction)//0....term1_i...term0_i....SIZE - 1
        {                               //  <<<                 >>>>
            term0_bottom_lim = term0_i;
            term0_up_lim = SIZE - 1;
            term1_bottom_lim = 0;
            term1_up_lim = term1_i;
        }
        else if (sum > 0 && !out_direction)//0....term0_i..........term1_i....SIZE - 1
        {                                  //            >>>     <<<
            term0_bottom_lim = term0_i;
            term0_up_lim = (term1_i - term0_i)/2+term0_i;
            term1_bottom_lim = (term1_i - term0_i) / 2 + term0_i;
            term1_up_lim = term1_i;
        }
        else
        {                                   //0....term1_i..........term0_i....SIZE - 1        
            term0_up_lim = term0_i;         //            >>>     <<<
            term0_bottom_lim = (term1_i - term0_i) / 2 + term0_i;
            term1_up_lim = (term1_i - term0_i) / 2 + term0_i;
            term1_bottom_lim = term1_i;
        }
        //так как массив упорядочен, двигаемся либо наружу либо внутрь, пока дельта меньше
        //пробуем двигаться сначала одним, потом другим
        for (int i = term1_bottom_lim, j = term0_bottom_lim; i != term1_up_lim && j != term0_up_lim;i+term1_delta,j+term0_delta)
        {

        }
    }
}
