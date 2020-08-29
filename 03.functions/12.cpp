/*
    12: Տրանսպոնացված մատրից
    Գրել ծրագիր, որը մուտքում կստանա 5x10 մատրից՝ տող առ տող և կարտածի այդ մատրիցի տրանսպոնացված մատրիցան։ 
    Անհրաժեշտ է արտածել մատրիցի տարրերը տող առ տող՝ նույն տողի տարրերը բաժանելով միմյանցից բացատանիշով։
*/

#include <iostream>

int main()
{
    int rows = 5;
    int cols = 10;
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

    // Transpose of a matrix
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            std::cout << matrix[j][i] << " ";
        }
        std::cout << "\n";
    }

    // Delete matrix
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}