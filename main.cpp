#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;

ll n;
vl A;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;

  A = vl(n);
  for (auto&& x : A) {
    cin >> x;
  }

  sort(A.begin(), A.end());

  auto i = ll{0};
  auto j = ll{n - 1};
  auto ans = numeric_limits<ll>::max();
  auto vi = ll{};
  auto vj = ll{};
  while (i < j) {
    const auto& s = A[i] + A[j];
    if (abs(s) < ans) {
      ans = abs(s);
      vi = A[i];
      vj = A[j];

      if (0 == ans) {
        break;
      }
    }

    if (s < 0) {
      ++i;
    } else {
      --j;
    }
  }

  cout << vi << ' ' << vj;

  return 0;
}