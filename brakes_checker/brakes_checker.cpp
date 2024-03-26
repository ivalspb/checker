// brakes_checker.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stack>
#include <string>

bool check_brakes(std::string s)
{
    std::stack<char> st;
    for (const char simb : s)
    {
        if (simb == '(' || simb == '[' || simb == '{') st.push(simb);
        else
        {
            if (st.empty()) return false;
            switch (simb)
            {
            case ')':
                if (st.top() != '(') return false;
                break;
            case ']':
                if (st.top() != '[') return false;
                break;
            case '}':
                if (st.top() != '{') return false;
            }
            st.pop();
        }
    }
    return st.empty();

}

int main()
{
    std::cout << "Hello World!\n";
}
