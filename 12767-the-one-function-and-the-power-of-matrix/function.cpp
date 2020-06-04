#include "function.h"
#define ll long long

Matrix::Matrix(int n) {
  this->n = n;
  this->matrix = new long long*[n];
  for (int i = 0; i < n; i++) {
    this->matrix[i] = new long long[n];
  }
  this->toZero();
}

Matrix::~Matrix() {
  for (int i = 0; i < n; i++)
    delete [] matrix[i];
}

Matrix::Matrix(const Matrix& ref) { *this = ref; }

Matrix& Matrix::operator=(const Matrix& ref) {
  if (this == &ref) return *this;
  for (int i = 0; i < n; i++)
    delete [] matrix[i];

  this->n = ref.n;
  ll** m = new ll*[n];
  for (int i = 0; i < n; i++) m[i] = new ll[n];

  long long** r = ref.matrix;
  for (int i = 0; i < this->n; i++) {
    for (int j = 0; j < this->n; j++) {
      m[i][j] = r[i][j];
    }
  }
  this->matrix = m;

  return *this;
}

long long& Matrix::operator()(const int& row, const int& column) const {
  return this->matrix[row][column];
}

void Matrix::toIdentity() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      this->matrix[i][j] = (i == j) ? 1 : 0;
    }
  }
}

Matrix Matrix::operator*(const Matrix& rhs) const {
  Matrix ans = Matrix(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        ans.matrix[i][j] += (this->matrix[i][k] * rhs.matrix[k][j]) % mod;
        ans.matrix[i][j] %= mod;
      }
    }
  }
  return ans;
}

Matrix Matrix::power(int k) const {
  Matrix init = Matrix(n);
  init.toIdentity();
  Matrix ret = *this;

  while (k > 0) {
    if (k % 2 == 1) init = init * ret;
    ret = ret * ret;
    k /= 2;
  }
  return init;
}

Matrix constructMatrix(int n) {
  Matrix ans = Matrix(n);
  ans.toZero();
  for (int i = 0; i < n - 1; i++) ans(i, i+1) = 1;
  for (int i = 0; i < n; i++) ans(n - 1, i) = 1;
  return ans;
}
