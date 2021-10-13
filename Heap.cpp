#include <chrono>
#include <iostream>
#include <time.h>
using namespace std;
using namespace std::chrono;
class heap
{
public:
    void sort(int *, int);
    void heapify(int *, int);
    void adjust(int *, int, int);
};
void heap::sort(int a[], int n)
{
    int i, temp;
    heapify(a, n);
    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        adjust(a, i, 0);
    }
}
void heap::heapify(int a[], int n) //41  18467  6334  26500  19169  
{
    int i, j, k, p;
    for (i = 1; i < n; i++)
    {
        k = a[i];
        j = i;
        p = (j - 1) / 2;
        while (j > 0 && k > a[p])
        {
            a[j] = a[p];
            j = p;
            p = (j - 1) / 2;
        }
        a[j] = k;
    }
}
void heap::adjust(int a[], int n, int p)
{
    int i, item;
    item = a[p];
    i = 2 * p + 1;
    while (i < n)
    {
        if (i + 1 < n)
            if (a[i] < a[i + 1])
                i++;
        if (item < a[i])
        {
            a[p] = a[i];
            p = i;
            i = 2 * p + 1;
        }
        else
            break;
    }
    a[p] = item;
}
int main()
{
    int *a, n, i;
    heap h;
    clock_t start,stop;
    cout << "Enter the number of elements:";
    cin >> n;
    a = new int[n];
    cout << "Enter elements:" << endl;
    for (i = 0; i < n; i++)
    {
        a[i] = rand();
        cout << a[i] << "  ";
    }
    cout << endl;
    start =clock();
    h.sort(a, n);
    stop=clock();
    cout << "sorted elements:" << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << "  ";
    cout << endl;
    cout << "time taken=" <<((float)(stop-start)/(CLK_TCK))*10.0<<" Milliseconds"<< endl;
    cout << "space consumed=" << sizeof(n) + n * sizeof(a) + sizeof(i) + sizeof(h) << " bytes" << endl;
    return 0;
}