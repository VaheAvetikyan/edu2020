/*
    26: Merge sort
    Պահանջվում է գրել ծրագիր, որը մուտքում ստանալով N բնական թիվ, 
    ապա N ամբողջ տարրերից կազմված հաջորդականություն, 
    կսորտավորի հաջորդականության տարրերը նվազման կարգով և կարտածի այն։ 
    Արտածվող թվերը միմյանցից պետք է բաժանված լինեն բացատանիշով։ 
    Խնդիրը լուծելիս օգտագործել զանգված և merge sort ալգորիթմը։
*/

#include <iostream>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = new int[n1], *R = new int[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";
    std::cout << "\n";
}

int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
}