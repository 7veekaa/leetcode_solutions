#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution {
private:
    vector<int> nextSmallerElements(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> answer(n);

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            answer[i] = s.top();
            s.push(i);
        }
        return answer;
    }

    vector<int> prevSmallerElements(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> answer(n);

        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            answer[i] = s.top();
            s.push(i);
        }
        return answer;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = nextSmallerElements(heights, n);
        vector<int> prev = prevSmallerElements(heights, n);
        int area = INT_MIN;

        for (int i = 0; i < n; i++) {
            int l = heights[i];
            if (next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newarea = l * b;
            area = max(area, newarea);
        }
        return area;
    }
};
