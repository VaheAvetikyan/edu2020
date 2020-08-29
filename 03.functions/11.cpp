/*
    11: Մատրիցների տարբերություն
    Գրել ծրագիր, որը մուտքում կստանա երկու 6x6 մատրիցներ՝ տող առ տող և կարտածի այդ մատրիցների տարբերությունը։ 
    Անհրաժեշտ է արտածել մատրիցի տարրերը տող առ տող՝ նույն տողի տարրերը բաժանելով միմյանցից բացատանիշով։
*/

#include <iostream>

int main()
{
    int rows = 6;
    int cols = 6;
    int **matrixOne = new int *[rows];
    int **matrixTwo = new int *[rows];

    // Input first matrix
    for (int i = 0; i < rows; i++)
    {
        matrixOne[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrixOne[i][j];
        }
    }

    // Input second matrix
    for (int i = 0; i < rows; i++)
    {
        matrixTwo[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrixTwo[i][j];
        }
    }

    // Output the matrix difference
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrixOne[i][j] - matrixTwo[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Delete matrixes
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrixOne[i];
        delete[] matrixTwo[i];
    }
    delete[] matrixOne;
    delete[] matrixTwo;
}