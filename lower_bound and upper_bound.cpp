vector<int> searchRange(vector<int> &v, int k) {
  if (v.empty())
    return {-1, -1};
  int lb = 0, ub = 0;

  int l = 0, h = v.size() - 1;
  while (l <= h) {
    int m = (l + h) / 2;
    if (v[m] >= k) {
      lb = m;
      h = m - 1;
    } else {
      l = m + 1;
    }
  }

  for (int i = log2(v.size()); i >= 0; --i) {
    int t = (ub | (1 << i));
    if (t < v.size() and v[t] <= k) {
      ub = t;
    }
  }

  if (v[lb] != k)
    lb = -1;

  if (v[ub] != k)
    ub = -1;
  return {lb, ub};
}
