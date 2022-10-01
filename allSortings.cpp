#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

void swap(int *arr, int i, int idx)
{
    int temp = arr[idx];
    arr[idx] = arr[i];
    arr[i] = temp;
}

//Bubble Sort

void bubbleSort(int *arr, int n)
{
    int swaps = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr, i, i + 1);
                swaps++;
            }
        }
        if (swaps == 0) //To reduce time complexity for lower bond
            break;
        swaps = 0;
    }
}

//Insertion Sort

void shiftRight(int *arr, int n)
{
    int current = arr[n];
    int i = n - 1;
    while (current < arr[i] && i >= 0)
    {
        arr[i + 1] = arr[i];
        --i;
    }
    arr[i + 1] = current;
}

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] < arr[i - 1])
        {
            shiftRight(arr, i);
        }
    }
}

//Merge Sort

void merge(int *arr, int l, int m, int r)
{
    int nl = m - l + 1;
    int nr = r - m;

    int larr[nl], rarr[nr];

    for (int i = 0; i < nl; i++)
        larr[i] = arr[l + i];

    for (int j = 0; j < nr; j++)
        rarr[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < nl && j < nr)
    {
        if (larr[i] <= rarr[j])
        {
            arr[k] = larr[i];
            i++;
        }
        else
        {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl)
    {
        arr[k] = larr[i];
        i++;
        k++;
    }
    while (j < nr)
    {
        arr[k] = rarr[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r)
{
    int m;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

//Quick Sort

void quickSort(int *arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int s = low;
    int e = high;
    int p = s + (e - s) / 2;

    while (s <= e)
    {
        while (arr[p] > arr[s])
        {
            s++;
        }
        while (arr[p] < arr[e])
        {
            e--;
        }

        if (s <= e)
        {
            swap(arr, s, e);
            s++;
            e--;
        }
    }

    quickSort(arr, low, e);
    quickSort(arr, s, high);
}

//Radix Sort

void radixSort(int *arr, int n, int d)
{
    int arrd[n];

    int power = 1;
    while (d--)
    {
        for (int i = 0, k = 0; i <= 9; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if ((arr[j] / power) % 10 == i)
                {
                    arrd[k] = arr[j];
                    ++k;
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            arr[i] = arrd[i];
        }
        power *= 10;
    }
}

//Selection Sort

void selectionSort(int *arr, int n)
{
    int idx = 0;

    for (int i = 0; i < n; ++i)
    {
        idx = i;
        for (int j = i; j < n; ++j)
        {
            if (arr[j] < arr[idx])
            {
                idx = j;
            }
        }
        swap(arr, i, idx);
    }
}

void resetArray(int *arr, int *arrX, int n)
{
    for (int i = 0; i < n; ++i)
    {
        arr[i] = arrX[i];
    }
}

int main()
{
    /*
    int n;
    cout << "Enter Array Size" << endl;
    cin >> n;
    int arrX[n];
    int arr[n];

    cout << "Enter elements seperated by space" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> arrX[i];
        arr[i] = arrX[i];
    }

    int d;
    cout << "Enter size for Radix Sort" << endl;
    cin >> d;
*/
    char x;
    int n = 52312, d = 4;
    int arr[52312];
    int arrX[52312];
    //52312
    string inFileName = "testcases.txt";
    ifstream inFile;
    inFile.open(inFileName.c_str());

    cout << "Do you want to see the unsorted array? (y/n)" << endl;
    cin >> x;

    if (inFile.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            inFile >> arrX[i];
            if (x == 'y' || x == 'Y')
            {
                cout << arrX[i] << " ";
            }
        }

        inFile.close(); // CLose input file
    }
    else
    { //Error message
        cerr << "Can't find input file " << inFileName << endl;
    }

    if (x == 'y' || x == 'Y')
    {
        cout << endl
             << endl;
    }

    cout << endl
         << "Bubble Sort : ";
    resetArray(arr, arrX, n);
    auto start = high_resolution_clock::now();
    bubbleSort(arr, n);
    auto stop = high_resolution_clock::now();
    std::chrono::duration<double> duration = stop - start;
    cout << duration.count() << " seconds" << endl;

    cout << "Insertion Sort : ";
    resetArray(arr, arrX, n);
    start = high_resolution_clock::now();
    insertionSort(arr, n);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << duration.count() << " seconds" << endl;

    cout << "Merge Sort : ";
    resetArray(arr, arrX, n);
    start = high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << duration.count() << " seconds" << endl;

    cout << "Quick Sort : ";
    resetArray(arr, arrX, n);
    start = high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << duration.count() << " seconds" << endl;

    cout << "Radix Sort : ";
    resetArray(arr, arrX, n);
    start = high_resolution_clock::now();
    radixSort(&arr[0], n, d);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << duration.count() << " seconds" << endl;

    cout << "Selection Sort : ";
    resetArray(arr, arrX, n);
    start = high_resolution_clock::now();
    selectionSort(&arr[0], n);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << duration.count() << " seconds" << endl;

    cout << "Do you want to see the sorted array? (y/n)" << endl;
    cin >> x;

    if (x == 'y' || x == 'Y')
    {
        for (int i = 0; i < n; ++i)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}