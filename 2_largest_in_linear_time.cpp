#include <iostream>
using namespace std;
void two_largest(int* arr, int s, int& first, int& second)
{
    first = second = *arr;
    for(int i = 1; i < s; ++i)
    {
        if(first < arr[i])
        {
            second = first;
            first = arr[i];
        }
        else if(second < arr[i])
        {
            second = arr[i];
        }
    }
}
int main()
{
    int arr[5] = {3, 1, 5, 2, 7};
    int f = 0, s = 0;
    two_largest(arr, sizeof(arr)/sizeof(int), f, s);
    cout << f << ", " << s << '\n';
    return 0;
}
