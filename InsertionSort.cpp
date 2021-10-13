
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class InsertionSort
{
public:
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    void sort(int A[], int n)
    {
        int i, j, x;

        for (i = 1; i < n; i++)
        {
            j = i - 1;
            x = A[i];
            while (j > -1 && A[j] > x)
            {
                A[j + 1] = A[j];
                j--;
            }
            A[j + 1] = x;
        }
    }
};

int main()
{
    int n, i;
    clock_t start, stop;
    cout << "\nEnter the number of elements : ";
    cin >> n;
    int a[n];
    InsertionSort insertionSort;
    cout << "\nThe unsorted list is:\n\n";
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 10000;
        cout << a[i] << "\t";
    }
    start = clock();
    insertionSort.sort(a, n);
    stop = clock();
    cout << "\n\nSorted elements are \n"
         << endl;
    for (i = 1; i < n; i++)
        cout << a[i] << "\t";
    cout << "\n\nANALYSIS:";
    cout << "\nTime taken: " << ((float)(stop - start) / CLK_TCK) * 10.0 << " milliseconds";
    cout << "\nSpace consumed: " << sizeof(n) + n * sizeof(a) + sizeof(i) + sizeof(insertionSort) << " bytes";
    cout << "\n";
    return 0;
}
