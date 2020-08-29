/*
    13: Հեռացնել տողը
    Գրել ծրագիր, որը մուտքում կստանա K (1 ≤ K ≤ 6) թիվը, ապա 6x5 մատրիցի տարրերը՝ տող առ տող։ 
    Անհրաժեշտ է հեռացնել մատրիցից K֊րդ տողը և արտածել ստացված նոր մատրիցը։ 
    Անհրաժեշտ է արտածել մատրիցի տարրերը տող առ տող՝ նույն տողի տարրերը բաժանելով միմյանցից բացատանիշով։
*/

#include <iostream>

int main()
{
    int K;
    std::cin >> K;
    K--;

    int rows = 6;
    int cols = 5;
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

    // Delete K row
    delete[] matrix[K];

    // Print the matrix
    for (int i = 0; i < rows; ++i)
    {
        // Skip over deleted row
        if (i == K)
            continue;

        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Delete matrix
    for (int i = 0; i < rows; ++i)
    {
        // Skip over deleted row
        if (i == K)
            continue;
        delete[] matrix[i];
    }
    delete[] matrix;
}