#include <iostream>
#include <algorithm>
#include <deque> 
using namespace std;

using ull = unsigned long long;
void printKMax(int arr[], int n, int k){
    int m = arr[0];
    size_t m_at = k;

    int outgoing_elem = arr[0];

    for(size_t i = 0; i <= n-k; ++i)
    {
        if(i <= m_at && m_at <= i+k-1)
        {
            m = max({m, outgoing_elem, arr[i+k-1]});
        }else{
            auto mp = max_element(arr + i, arr + i + k);
            m = *mp;
            m_at = distance(arr, mp);
        }
        outgoing_elem = arr[i];
        
        cout << m << " ";
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

