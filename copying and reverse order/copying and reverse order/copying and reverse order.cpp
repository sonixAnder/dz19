#include <iostream>
using namespace std;

int main() 
{
    int arr1[] = { 1, 2, 3, 4, 5 };
    int arr2[5];

    int* p1 = arr1;
    int* p2 = arr2;

    for (int i = 0; i < 5; i++) 
    {
        *p2 = *(p1 + 4 - i);
        p2++;
    }

    for (int i = 0; i < 5; i++) 
    {
        cout << arr2[i] << " ";
    }

    return 0;
}

