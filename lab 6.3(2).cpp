#include <iostream>
#include <iomanip>

using namespace std;



void Create(int* list, const int size, const int Min, const int Max, int i) {
    if (i < size)
    {
        list[i] = rand() % (Max - Min + 1) + Min;
        return Create(list, size, Min, Max, ++i);
    }
}


void QuickSort(int* arr, int first, int last)
{
    int l = first,
        r = last,
        p = arr[(first + last) / 2];

    do {
        while (arr[l] < p) l++;
        while (arr[r] > p) r--;
        if (l <= r) {
            if (arr[l] > arr[r])
                swap(arr[l], arr[r]);
            l++;
            r--;
        }
    } while (l <= r);
    if (l < last)
        QuickSort(arr, l, last);
    if (first < r)
        QuickSort(arr, first, r);
}


void Print(int* list, const int size, int i)
{
    if (i < size) {
        cout << setw(3) << list[i];
        return Print(list, size, ++i);
    }
    cout << endl;
}


template <class T1, class T2, class T3>
void Create(T1* list, const int size, T2 Min, T3 Max, int i) {
    if (i < size)
    {
        list[i] = (Max - Min) * rand() / RAND_MAX + Min;
        return Create(list, size, Min, Max, ++i);
    }
}

template <class T>
void QuickSort(T* arr, int first, int last)
{
    int l = first,
        r = last;

    T p = arr[(first + last) / 2];

    do {
        while (arr[l] < p) l++;
        while (arr[r] > p) r--;
        if (l <= r) {
            if (arr[l] > arr[r])
                swap(arr[l], arr[r]);
            l++;
            r--;
        }
    } while (l <= r);
    if (l < last)
        QuickSort(arr, l, last);
    if (first < r)
        QuickSort(arr, first, r);
}

template <class T>
void Print(T* list, const int size, int i)
{
    if (i < size) {
        cout << fixed << setprecision(2) << setw(5) << list[i];
        return Print(list, size, ++i);
    }
    cout << endl;
}


int main()
{
    setlocale(LC_ALL, "Ukrainian");

    srand((unsigned)time(NULL));

    //srand(1); // для перевірки правильності способів

    const int n = 10;
    int a[n];

    int Min = 0;
    int Max = 90;

    cout << "Рекурсивний спосiб" << endl;
    cout << endl;

    Create(a, n, Min, Max, 0);
    cout << "Before: "; Print(a, n, 0);
    QuickSort(a, 0, n - 1);
    cout << "Sorted: "; Print(a, n, 0);


    cout << "\n\nРекурсивний спосiб (template)" << endl;
    double b[n];

    Create(b, n, 0.1, 1.9, 0);
    cout << "Before: "; Print(b, n, 0);
    QuickSort(b, 0, n - 1);
    cout << "Sorted: "; Print(b, n, 0);
}