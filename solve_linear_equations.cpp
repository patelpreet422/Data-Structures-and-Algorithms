// https://www.algorithm-archive.org/contents/gaussian_elimination/gaussian_elimination.html

#include <vector>
#include <numeric>
#include <valarray>
#include <iostream>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &vec)
{
	for(auto e: vec) os << e << " ";
	return os;
}

template<typename T>
void gaussianElimination(std::vector<std::vector<T> > &eqns) {
  int rows = eqns.size(), cols = eqns[0].size();

  for (int i = 0; i < rows - 1; i++) {
    int pivot = i;

    for (int j = i + 1; j < rows; j++) {
      if (fabs(eqns[j][i]) > fabs(eqns[pivot][i])) pivot = j;
    }

    if (eqns[pivot][i] == 0.0)
      continue; 

    if (i != pivot) 
      std::swap(eqns[pivot], eqns[i]); 

    for (int j = i + 1; j < rows; j++) {
      double scale = eqns[j][i] / eqns[i][i];

      for (int k = i + 1; k < cols; k++)   
        eqns[j][k] -= scale * eqns[i][k];  
      eqns[j][i] = 0.0;
    }
  }
}

template<typename T>
void gaussJordan(std::vector<std::vector<T> > &eqns) {
  // 'eqns' is the (Row-echelon) matrix, 'rows' is no. of vars
  int rows = eqns.size();

  for (int i = rows - 1; i >= 0; i--) {

    if (eqns[i][i] != 0) {

      eqns[i][rows] /= eqns[i][i];
      eqns[i][i] = 1;  // We know that the only entry in this row is 1

      // subtracting rows from below
      for (int j = i - 1; j >= 0; j--) {
        eqns[j][rows] -= eqns[j][i] * eqns[i][rows];
        eqns[j][i] = 0;  // We also set all the other values in row to 0 directly
      }
    }
  }
}

template<typename T>
void print_mat(const vector<vector<T>>& mat)
{
	for(auto& r: mat){
		cout << r << '\n';
	}
}


template<typename T>
vector<T> solveLinearSystem(vector<vector<T>> eqn)
{
	vector<T> unknowns(eqn.size());
	gaussianElimination(eqn);
	gaussJordan(eqn);
	for(auto c = 0; c < eqn.size(); ++c)
	{
		unknowns[c] = eqn[c][eqn.size()];
	}
	return unknowns;
}

int main()
{
	vector<vector<float>> mat{
		{2, 3, 1, 5},
		{1, 1, 1, 10},
		{1, 1, 2, 20}
	};
	//gaussianElimination(mat);
	//gaussJordan(mat);
	print_mat(mat);
	cout << solveLinearSystem(mat) << '\n';
	return 0;
}
