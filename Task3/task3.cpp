#include <iostream>
#include <string>
#include <vector>

struct Matrix {
  std::string a;
  std::string b;
  std::string c;
  std::string d;
};

class Solution {
 public:
  Solution() = default;
  std::string multiply(std::string num1, std::string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    std::vector<int> result(len1 + len2, 0);

    for (int i = len1 - 1; i >= 0; i--) {
      for (int j = len2 - 1; j >= 0; j--) {
        int product = (num1[i] - '0') * (num2[j] - '0');
        int sum = product + result[i + j + 1];
        result[i + j + 1] = sum % 10;
        result[i + j] += sum / 10;
      }
    }

    std::string res;
    for (int num : result) {
      if (!(res.empty() && num == 0)) {
        res.push_back(num + '0');
      }
    }
    return res.empty() ? "0" : res;
  }
  std::string add(std::string num1, std::string num2) {
    std::string res;
    int i = num1.size() - 1, j = num2.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
      int n1 = (i >= 0) ? num1[i--] - '0' : 0;
      int n2 = (j >= 0) ? num2[j--] - '0' : 0;
      int sum = n1 + n2 + carry;
      res.push_back(sum % 10 + '0');
      carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
  }

  Matrix multiplyMatrices(const Matrix& m1, const Matrix& m2) {
    Matrix res;
    res.a = add(multiply(m1.a, m2.a), multiply(m1.b, m2.c));
    res.b = add(multiply(m1.a, m2.b), multiply(m1.b, m2.d));
    res.c = add(multiply(m1.c, m2.a), multiply(m1.d, m2.c));
    res.d = add(multiply(m1.c, m2.b), multiply(m1.d, m2.d));
    return res;
  }
  Matrix matrixPower(const Matrix& m, int power) {
    if (power == 1) return m;
    if (power % 2 == 0) {
      Matrix half = matrixPower(m, power / 2);
      return multiplyMatrices(half, half);
    } else {
      return multiplyMatrices(m, matrixPower(m, power - 1));
    }
  }

  std::string computeF(int n) {
    if (n == 0) return "1";
    if (n == 1) return "3";

    Matrix m;
    m.a = "5";
    m.b = "1";
    m.c = "1";
    m.d = "0";

    Matrix powered = matrixPower(m, n - 1);

    std::string f1 = "3";
    std::string f0 = "1";

    std::string fn = add(multiply(powered.a, f1), multiply(powered.b, f0));
    return fn;
  }

  void solve() {
    std::cout << computeF(58);
  }
};

int main() {
  Solution sol;
  sol.solve();
  return 0;
}