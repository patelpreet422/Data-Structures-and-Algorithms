int minimumSwaps(vector<int> arr) {
    int c = 0, n = arr.size();
    for(int i = 0 ; i < n;)
    {
        while(arr[i] != i+1)
        {
            ++c;
            swap(arr[i], arr[arr[i]-1]);
        }
        ++i;
    }
    return c;
}
