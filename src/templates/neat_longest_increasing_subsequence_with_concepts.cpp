#include <iostream>
#include <vector>
#include <algorithm>
#include <concepts>

template<typename Container>
concept Range = requires(Container c) {
  c.begin(); // Check if Container has a begin() function
  c.end();   // Check if Container has an end() function
};

using namespace std;

static const int inf = 1<<30;

template <Range v>
int longest_increasing_subsequence(const v& a) {
    auto n = a.size();
    vector<int> dp(n, inf);
    for (auto x : a) {
        auto it2 = lower_bound(dp.begin(), dp.end(), x);
        *it2 = x;
    }
    return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf));
}


template <typename T>
int longest_increasing_subsequence(T begin, T end) {
    auto n = end - begin;
    vector<int> dp(n, inf);
    for (auto it = begin; it != end; ++it) {
        auto x = *it;
        auto it2 = lower_bound(dp.begin(), dp.end(), x);
        *it2 = x;
    }
    return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf));
}


int main() {
    vector<int> a = {1, 4, 3, 2, 3, 4, 9, 5, 6, 8, 7, 8, 9};
    cout << longest_increasing_subsequence(a.begin(), a.end()) << endl;
    cout << longest_increasing_subsequence(a) << endl;
    return 0;
}