#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

struct Segment {
  int l, r;
};

class Solution {
  int n;
  std::vector<Segment> segments;

 public:
  Solution() = default;
  void Read() {
    std::ifstream in("input.txt");
    in >> n;
    segments.resize(n);
    for (int i = 0; i < n; ++i) {
      int x1, x2;
      in >> x1 >> x2;
      segments[i] = {std::min(x1, x2), std::max(x1, x2)};
    }
    in.close();
    
  }
  void Solve() {
    std::sort(segments.begin(), segments.end(),
              [](Segment a, Segment b) { return a.r < b.r; });
    int points = 0;
    int last_p = -1;
    for (const auto& seg : segments) {
      if (seg.l > last_p) {
        last_p = seg.r;
        ++points;
      }
    }
    std::cout << points << '\n';
  }
};

int main() {
  Solution sol;
  sol.Read();
  sol.Solve();
}
