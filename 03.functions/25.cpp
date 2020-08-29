/*
    25: Հաջորդականությունների միավորում
    Պահանջվում է գրել ծրագիր, որը մուտքում կստանա երկու 10 երկարության սորտավորված զանգված 
    և կարտածի այդ զանգվածների միավորման արդյունքում ստացված սորտավորված զանգվածը։ 
*/

#include <iostream>

int *merge(int a[], int len_a, int b[], int len_b);

int main()
{
    int len = 10;
    int array1[len];
    int array2[len];

    // Input first array
    for (int i = 0; i < len; i++)
    {
        std::cin >> array1[i];
    }
    // Input second array
    for (int i = 0; i < len; i++)
    {
        std::cin >> array2[i];
    }

    int *array3 = merge(array1, len, array2, len);
    // Print new array
    for (int i = 0; i < 2 * len; i++)
    {
        std::cout << array3[i] << " ";
    }
    std::cout << "\n";
}

// Merge 2 arrays
int *merge(int a[], int len_a, int b[], int len_b)
{
    int i = 0, j = 0, k = 0;
    int newArrayLength = len_a + len_b;
    int *target = new int[newArrayLength];

    while (k < newArrayLength)
    {
        if (a[i] <= b[j] && i < len_a || j >= len_b)
        {
            target[k] = a[i];
            i++;
        }
        else
        {
            target[k] = b[j];
            j++;
        }
        k++;
    }
    return target;
}