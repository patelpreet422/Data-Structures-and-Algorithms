#include <iostream>
using namespace std;

void print_subsets(int* arr, size_t size)
{
  for(int i = 0; i < (1 << size); ++i)
  {
    for(int j = 0; j < size; ++j)
    {
      if((i & 1 << j) > 0)
      {
        cout << arr[j] << ' ';
      }
    }
    cout << '\n';
  }
}

int main()
{
  int arr[] = {1, 2, 3};
  print_subsets(arr, sizeof(arr)/sizeof(arr[0]));
  return 0;
}
