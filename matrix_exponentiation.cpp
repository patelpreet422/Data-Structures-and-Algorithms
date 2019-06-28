#include <iostream>
#include <vector>
#include <initializer_list>
#include <unordered_map>
using namespace std;

template <typename T>
struct matrix{
    matrix(size_t r, size_t c, T value)
    {
        data = vector<vector<T>>(r, vector<T>(c, value));
    }

    matrix(const vector<vector<T>>& m): data(m) {}

    matrix(std::initializer_list<vector<T>> init)
    {
        data = init;
    }

    vector<vector<T>> data;

    pair<size_t, size_t> shape() const { return {this->row(), this->column()}; }

    size_t size() const { return this->row(); }
    size_t row() const { return data.size(); }
    size_t column() const { return data[0].size(); }

    vector<T> operator[](size_t r) const { return data[r]; }

    vector<T>& operator[](size_t r) { return data[r]; }

    matrix<T> identity()
    {
        matrix<T> eye(this->row(), this->column(), 0);
        for(auto i = 0; i < this->row(); ++i)
            for (auto j = 0; j < this->column(); ++j)
                eye[i][j] = (i == j);
        return eye;
    }

    matrix<T> operator*(const matrix<T>& m2) const
    {
        matrix<T> res(this->row(), m2.column(), 0);
        for(size_t i = 0; i < res.row(); ++i)
        {
            for(size_t j = 0; j < res.column(); ++j)
            {
                for(T k = 0; k < this->column(); ++k)
                    res[i][j] += data[i][k]*m2[k][j];
            }
        }
        return res;
    }

    matrix<T> operator*=(const matrix<T>& m2)
    {
        *this = (*this) * m2;
        return *this;
    }

    matrix<T> pow(uintmax_t p)
    {
        matrix m = *this;
        matrix<T> res = this->identity();

        for(; p; m *= m, p >>= 1)
        {
            if(p & 1) res *= m;
        }
        return res;
    }
};

template <typename T>
matrix<T> matrix_power(matrix<T> m, int64_t p)
{
    matrix<T> res = m.identity();

    for(; p; m *= m, p >>= 1)
    {
        if(p & 1) res *= m;
    }
    return res;
}


int main()
{
    matrix<int64_t> mat {
        {1, 1},
        {1, 0}
    };
    
    // Fibonacci 
    // 0 1 2 3 4 5  6  7  8  9 10...
    // 1 1 2 3 5 8 13 21 34 55 89
    auto r = mat.pow(10);

    for(auto i = 0; i < r.row(); ++i)
    {
        for(auto j = 0; j < r.column(); ++j)
        {
            cout << r[i][j] << " ";
        }
        cout << '\n';
    }

    cout << '\n';
    for(auto i = 0; i < mat.row(); ++i)
    {
        for(auto j = 0; j < mat.column(); ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
