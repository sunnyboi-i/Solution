#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
 public:
  std::string f(const std::string &n) {
    std::string reversed = n;
    std::reverse(reversed.begin(), reversed.end());
    size_t first_non_zero = reversed.find_first_not_of('0');
    if (first_non_zero == std::string::npos) {
      return "0";
    }
    return reversed.substr(first_non_zero);
  }
  double g(const std::string &n_str) {
    std::string f1 = f(n_str);
    std::string f2 = f(f1);

    double numerator = stod(f2);
    double denominator = stod(n_str);

    return numerator / denominator;
  }
  int distinct_g_values() {
    std::unordered_set<std::string> unique_values;
    unique_values.insert("1");

    for (int k = 1; k <= 29; ++k) {
      std::string value = "0." + std::string(k - 1, '0') + "1";
      unique_values.insert(value);
    }

    return unique_values.size();
  }
  void solve() { std::cout << distinct_g_values() << '\n'; }
};

int main() {
  Solution sol;
  sol.solve();
  return 0;
}