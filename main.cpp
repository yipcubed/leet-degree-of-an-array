#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    int findShortestSubArray(vector<int>& nums) {
        map<int, int> seen;
        map<int, int> starts;
        map<int, int> ends;
        int maxd = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int vi = nums[i];
            ++seen[vi];
            maxd = max(maxd, seen[vi]);
            if (!starts.count(vi))
                starts[vi] = i;
            ends[vi] = i;
        }
        int shortest = INT_MAX;
        for (auto& p : seen) {
            if (p.second == maxd) {
                shortest = min(shortest, ends[p.first] - starts[p.first] + 1);
            }
        }
        return shortest;
    }
};

void test1() {
    vector<int> v1{1, 2, 2, 3, 1};

    cout << "2 ? " << Solution().findShortestSubArray(v1) << endl;

    vector<int> v2{1,2,2,3,1,4,2};

    cout << "6 ? " << Solution().findShortestSubArray(v2) << endl;
}

void test2() {

}

void test3() {

}