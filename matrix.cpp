#include <exception>
#include <initializer_list>
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T> struct matrix {

  matrix(std::initializer_list<vector<T>> init) {
    cout << "initializer_list\n";
    data = move(init);
  }

  // matrix(const vector<vector<T>>& m): data(m) { cout << "copy_ctor\n"; }

  matrix(size_t r, size_t c, T value = T(0)) {
    cout << "user_defined\n";
    data = vector<vector<T>>(r, vector<T>(c, value));
  }

  matrix(const matrix<T> &m) {
    this->data = m.data;
    cout << "copy_ctor\n";
  }
  matrix(matrix<T> &&m) {
    this->data = std::move(m.data);
    cout << "move_ctor\n";
  }

  void operator=(const matrix<T> &m) {
    this->data = m.data;
    cout << "copy_assign\n";
  }
  void operator=(matrix<T> &&m) {
    this->data = std::move(m.data);
    cout << "move_assign\n";
  }

  vector<vector<T>> data;

  pair<size_t, size_t> shape() const {
    return make_pair(this->row(), this->column());
  }

  size_t size() const { return this->row(); }
  size_t row() const { return data.size(); }
  size_t column() const { return data[0].size(); }

  vector<T> operator[](size_t r) const { return data[r]; }

  vector<T> &operator[](size_t r) { return data[r]; }

  matrix<T> identity() {
    matrix<T> eye(this->row(), this->column(), 0);
    for (auto i = 0; i < this->row(); ++i)
      for (auto j = 0; j < this->column(); ++j)
        eye[i][j] = (i == j);
    return eye;
  }

  matrix<T> pow(uintmax_t p) {
    matrix m = *this;
    matrix<T> res = this->identity();

    for (; p; m = std::move(m * m), p >>= 1) {
      if (p & 1)
        res = std::move(res * m);
    }
    return res;
  }

  matrix<T> transpose() const {
    matrix<T> t(this->column(), this->row());
    for (auto i = 0; i < t.row(); ++i)
      for (auto j = 0; j < t.column(); ++j)
        t[i][j] = data[j][i];
    return t;
  }

  matrix<T> operator*(const matrix<T> &m) const {
    if (this->shape().second != m.shape().first)
      throw std::invalid_argument("inappropiate matrix shape");

    matrix<T> res(this->row(), m.column(), 0);
    for (size_t i = 0; i < res.row(); ++i) {
      for (size_t j = 0; j < res.column(); ++j) {
        for (T k = 0; k < this->column(); ++k)
          res[i][j] += data[i][k] * m[k][j];
      }
    }
    return res;
  }

  matrix<T> operator*(matrix<T> &&m) {
    if (this->shape().second != m.shape().first)
      throw std::invalid_argument("inappropiate matrix shape");

    matrix<T> res(this->row(), m.column(), 0);
    for (size_t i = 0; i < res.row(); ++i) {
      for (size_t j = 0; j < res.column(); ++j) {
        for (T k = 0; k < this->column(); ++k)
          res[i][j] += data[i][k] * m[k][j];
      }
    }
    return res;
  }

  matrix<T> operator*=(const matrix<T> &m) {
    *this = (*this) * m;
    return *this;
  }

  matrix<T> operator*=(matrix<T> &&m) {
    *this = (*this) * std::move(m);
    return *this;
  }

  matrix<T> operator+(const matrix<T> &m) const {
    if (m.shape() != this->shape())
      throw std::invalid_argument("inappropiate matrix shape");
    matrix<T> res = *this;
    for (auto i = 0; i < res.row(); ++i) {
      for (auto j = 0; j < res.column(); ++j) {
        res[i][j] += m[i][j];
      }
    }
    return res;
  }

  matrix<T> operator+(matrix<T> &&m) {
    if (m.shape() != this->shape())
      throw std::invalid_argument("inappropiate matrix shape");
    matrix<T> res = *this;
    for (auto i = 0; i < res.row(); ++i) {
      for (auto j = 0; j < res.column(); ++j) {
        res[i][j] += m[i][j];
      }
    }
    return res;
  }

  matrix<T> operator+=(const matrix<T> &m) {
    (*this) = (*this) + m;
    return *this;
  }

  matrix<T> operator+=(matrix<T> &&m) {
    (*this) = (*this) + std::move(m);
    return *this;
  }

  matrix<T> operator-(const matrix<T> &m) const {
    if (m.shape() != this->shape())
      throw std::invalid_argument("inappropiate matrix shape");
    matrix<T> res = *this;
    for (auto i = 0; i < res.row(); ++i) {
      for (auto j = 0; j < res.column(); ++j) {
        res[i][j] -= m[i][j];
      }
    }
    return res;
  }
  matrix<T> operator-(matrix<T> &&m) {
    if (m.shape() != this->shape())
      throw std::invalid_argument("inappropiate matrix shape");
    matrix<T> res = *this;
    for (auto i = 0; i < res.row(); ++i) {
      for (auto j = 0; j < res.column(); ++j) {
        res[i][j] -= m[i][j];
      }
    }
    return res;
  }

  matrix<T> operator-=(const matrix<T> &m) {
    *this = (*this) - m;
    return *this;
  }

  matrix<T> operator-=(matrix<T> &&m) {
    *this = (*this) - std::move(m);
    return *this;
  }
};

template <typename T> matrix<T> matrix_power(matrix<T> m, int64_t p) {
  matrix<T> res = m.identity();

  for (; p; m = std::move(m * m), p >>= 1) {
    if (p & 1)
      res = std::move(res * m);
  }
  return res;
}

int main() {
  /*
   * 1 3 5
   * 2 4 6
   */
  matrix<int64_t> mat{{2, 3, 1}, {1, 1, 1}, {1, 1, 2}};
  auto p = mat.pow(9);
  // 0 1 2 3 4 5  6  7  8  9 10...
  // 1 1 2 3 5 8 13 21 34 55 89
  for (int i = 0; i < p.row(); ++i) {
    for (auto e : p[i])
      cout << e << " ";
    cout << '\n';
  }

  return 0;
}
