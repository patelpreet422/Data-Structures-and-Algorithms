#include <iostream>
#include <algorithm>
#include <deque> 
using namespace std;

using ull = unsigned long long;
void printKMax(int arr[], int n, int k){
    int m = arr[0];
    size_t m_at = 0;
    
    // int mi = arr[0];
    // size_t mi_at = 0;

    for (size_t i = 1; i < k; ++i) {
      if (m <= arr[i]) {
        m = arr[i];
        m_at = i;
      }

    //   if (mi >= arr[i]) {
    //     mi = arr[i];
    //     mi_at = i;
    //   }
    }

    cout << "Max: " << m << ", ";
    // cout << "Min: " << mi << '\n';

    for(size_t i = 1; i <= n-k; ++i)
    {
        if(i <= m_at && m_at <= i+k-1)
        {
            m = max({m, arr[i-1], arr[i+k-1]});
        }else{
            auto mp = max_element(arr + i, arr + i + k);
            m = *mp;
            m_at = distance(arr, mp);
        }

        // if (i <= mi_at && mi_at <= i + k - 1) {
        //   mi = min({mi, arr[i - 1], arr[i + k - 1]});
        // } else {
        //   auto mp = min_element(arr + i, arr + i + k);
        //   mi = *mp;
        //   mi_at = distance(arr, mp);
        // }

        cout << "Max: " << m << ", ";
        // cout << "Min: " << mi << '\n';
    }

    cout << '\n';
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

