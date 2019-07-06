#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void k_sorted(vector<int>& vec, int k)
{
	priority_queue<int, vector<int>, greater<>> pq(vec.begin(), vec.begin()+k+1);

	int n = vec.size();
	int p = 0;
	for (int i = k+1; i < n; ++i)
	{
		vec[p++] = pq.top();
		pq.pop();
		pq.push(vec[i]);
	}

	while (!pq.empty()) 
	{
		vec[p++] = pq.top(); 
		pq.pop();
	}
}

int main()
{
	vector<int> vec{ 6, 5, 3, 2, 8, 10, 9 };
	k_sorted(vec, 3);
	for (auto e : vec) cout << e << " ";
	cout << '\n';
	return 0;
}
