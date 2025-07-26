#define ALL(x) begin(x), end(x)

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long sol = 0;

        vector<vector<int>> checkpoint(n + 1);
        for (auto& pair : conflictingPairs) {
            int a = min(pair[0], pair[1]);
            int b = max(pair[0], pair[1]);
            checkpoint[b].push_back(a);
        }

        int maxPrev = 0, secondMaxPrev = 0;
        vector<long long> post_operation(n + 1, 0);

        for (int end = 1; end <= n; ++end) {
            for (int u : checkpoint[end]) {
                if (u >= maxPrev) {
                    secondMaxPrev = maxPrev;
                    maxPrev = u;
                } else if (u > secondMaxPrev) {
                    secondMaxPrev = u;
                }
            }

            sol += end - maxPrev;
            post_operation[maxPrev] += maxPrev - secondMaxPrev;
        }

        return sol + *max_element(ALL(post_operation));
    }
};
