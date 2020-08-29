/*
    15: Սպիրալաձև
    Գրել ծրագիր, որը մուտքում կստանա 6x6 մատրիցի տարրերը՝ տող առ տող։ 
    Արտածել մարտիցի տարրերը մեկ տողում՝ սկսելով նրա առաջին (վերևի ամենաձախ) տարրից և անցնելով մատրիցի տարրերի վրայով սպիտալաձև: 
*/

#include <iostream>

int main()
{
    int rows = 6;
    int cols = 6;
    int **matrix = new int *[rows];

    // Input  matrix
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    // Print the matrix in one row
    int rowBase = 0, colBase = 0;
    int i = 0, j = 0;
    while (rows >= rowBase && cols >= colBase)
    {
        while (j < cols)
        {
            std::cout << matrix[i][j] << " ";
            j++;
        }
        rowBase++;
        i++;
        j--;

        while (i < rows)
        {
            std::cout << matrix[i][j] << " ";
            i++;
        }
        cols--;
        j--;
        i--;

        while (j > colBase)
        {
            std::cout << matrix[i][j] << " ";
            j--;
        }
        rows--;

        while (i > rowBase)
        {
            std::cout << matrix[i][j] << " ";
            i--;
        }
        colBase++;
    }

    std::cout << "\n";

    // Delete matrix
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}