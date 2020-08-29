/*
    14: Հեռացնել սյունը
    Գրել ծրագիր, որը մուտքում կստանա K (1 ≤ K ≤ 5) թիվը, ապա 6x5 մատրիցի տարրերը՝ տող առ տող։ 
    Անհրաժեշտ է հեռացնել մատրիցից K֊րդ սյունը և արտածել ստացված նոր մատրիցը։ 
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
    int **matrix = new int *[cols];

    // Create matrix
    for (int i = 0; i < cols; i++)
    {
        matrix[i] = new int[rows];
    }

    // Input  matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[j][i];
        }
    }

    // Delete K column
    delete[] matrix[K];

    // Print the matrix
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; j++)
        {
            // Skip over deleted row
            if (j == K)
                continue;
            std::cout << matrix[j][i] << " ";
        }
        std::cout << "\n";
    }

    // Delete matrix
    for (int i = 0; i < cols; ++i)
    {
        // Skip over deleted row
        if (i == K)
            continue;
        delete[] matrix[i];
    }
    delete[] matrix;
}