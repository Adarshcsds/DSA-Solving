class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {

    deque<int> dq;
    vector<int> ans;

    for(int i = 0; i < arr.size(); i++) {

        // 1. Remove elements outside current window
        if(!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // 2. Remove smaller elements from back
        while(!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

        // 3. Add current index
        dq.push_back(i);

        // 4. Window is complete
        if(i >= k - 1)
            ans.push_back(arr[dq.front()]);
    }

    return ans;
}
};