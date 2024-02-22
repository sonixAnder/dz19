#include <iostream>
using namespace std;
void reverseArray(int* arr, int size) 
{
    int* start = arr; 
    int* end = arr + size - 1; 

    while (start < end) 
    {
        
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() 
{
    setlocale(LC_ALL, "ru");
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Оригинальный массив: ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }

    reverseArray(arr, size);

    cout << "\nПротивоположный: ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }

    return 0;
}
