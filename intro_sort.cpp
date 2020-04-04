class Solution {
public:
  void insertion_sort(vector<int>& v, int l, int h) {
    for(int i = l+1; i <= h; ++i) {
      int j = i-1;
      while(j >= 0 and v[j] > v[j+1]) {
        swap(v[j], v[j+1]);
        --j;
      }
    }
  }
  
  void heap_sort(vector<int>& v, int l, int h) {
    make_heap(begin(v) + l, begin(v) + h + 1);
    sort_heap(begin(v) + l, begin(v) + h + 1);
  }
  
  int partition(vector<int>& v, int l, int h) {
    swap(v[l + (rand() % (h - l + 1))], v[h]);
    int i = l - 1;
    for(int j = l; j <= h; ++j) {
      if(v[j] <= v[h]) {
        swap(v[++i], v[j]);
      }
    }
    return i;
  }
  
  void intro_sort(vector<int>& v, int max_depth, int l, int h) {
    if(l >= h) return;
    if(h - l + 1 <= 16) {
      insertion_sort(v, l, h);
    } else if(max_depth == 0) {
      heap_sort(v, l, h);
    } else {
      int p = partition(v, l, h);
      intro_sort(v, max_depth - 1, l, p-1);
      intro_sort(v, max_depth - 1, p+1, h);
    }
  }
  
  void quick_sort(vector<int>& v, int l, int h) {
    if(l >= h) return;
    int p = partition(v, l, h);
    quick_sort(v, l, p-1);
    quick_sort(v, p+1, h);
  }
  
  vector<int> sortArray(vector<int>& nums) {
    intro_sort(nums, 32, 0, nums.size() - 1);
    return nums;     
  }
};
