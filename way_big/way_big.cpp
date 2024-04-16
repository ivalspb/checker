#include <iostream>
#include <string>
#include <vector>
#include <stack>

int main()
{
    size_t N, M;
    std::cin >> N >> M;
    std::vector<std::vector<size_t>>t(N, std::vector<size_t>(M));
    for (auto& i : t)
        for (auto& j : i) std::cin >> j;
    for (size_t i = 1; i < N; i++) t[i][0] += t[i - 1][0];
    for (size_t j = 1; j < M; j++) t[0][j] += t[0][j - 1];
    for (size_t i = 1; i < N; i++)
        for (size_t j = 1; j < M; j++)
            t[i][j] += std::max(t[i - 1][j], t[i][j - 1]);
    std::cout << t[N - 1][M - 1] << std::endl;

    size_t i = N-1, j = M-1;
    std::stack<char> st;
    while (i  && j )
    {
            if (t[i -1][j] > t[i][j - 1])
            {
                st.push('D');
                i--;
            }
            else
            {
                st.push('R');
                j--;
            }
    }
    while (i)
    {
        st.push('D');
        i--;
    }
    while (j)
    {
        st.push('R');
        j--;
    }
    while (!st.empty())
    {
        std::cout << st.top() << " ";
        st.pop();
    }
    return 0;
}