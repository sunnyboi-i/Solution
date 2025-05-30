#include <climits>
#include <fstream>
#include <iostream>
#include <vector>

class Solution {
 private:
  std::vector<int> sequence;
  int n;

 public:
  Solution() = default;

  void Read() {
    std::ifstream in("input.txt");
    in >> n;
    sequence.resize(n);
    for (int& letter : sequence) {
      in >> letter;
    }
  }

  void solve() const {
    int min_len = INT_MAX;
    bool found = false;
    int i, j;
    for (int start = 0; start < n; ++start) {
      std::vector<int> freq(27, 0);
      int unique = 0;

      for (int end = start; end < n; ++end) {
        int val = sequence[end];
        if (val >= 1 && val <= 26) {
          if (freq[val] == 0) ++unique;
          ++freq[val];
        }

        if (unique == 26) {
          int len = end - start + 1;
          if (len < min_len) {
            min_len = len;
            found = true;
          }
          break;
        }
      }
    }

    if (found) {
      std::cout << min_len << '\n';

    } else {
      std::cout << "NONE\n";
    }
  }
};

int main() {
  Solution solver;
  solver.Read();
  solver.solve();
  return 0;
}
