
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {

        // Remove smaller or equal elements
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // Find next greater element
        if (!st.empty()) {
            ans[i] = st.top();
        }

        // Push current element
        st.push(arr[i]);
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 3, 2, 4};

    vector<int> ans = nextGreaterElement(arr);

    cout << "Next Greater Elements: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
