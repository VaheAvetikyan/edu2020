#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (n % 2 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    std::cout << 0;
                }
                else
                {
                    std::cout << 1;
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}