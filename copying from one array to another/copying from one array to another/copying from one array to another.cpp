#include <iostream>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "ru");
    const int SIZE = 5;
    int arr1[SIZE] = { 1, 2, 3, 4, 5 };
    int arr2[SIZE];

    int* ptr1 = arr1;
    int* ptr2 = arr2;

    for (int i = 0; i < SIZE; i++) 
    {
        *ptr2 = *ptr1;
        ptr1++;
        ptr2++;
    }

    cout << "Скопированный массив: ";
    for (int i = 0; i < SIZE; i++) 
    {
        cout << arr2[i] << " ";
    }

    return 0;
}