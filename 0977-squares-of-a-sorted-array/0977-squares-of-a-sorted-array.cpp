class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans(n); 
        int left = 0,right = n-1;
        int pos = n-1;
        while(left <= right){
            if(nums[left]*nums[left] > nums[right]* nums[right]){
                ans[pos]=nums[left]*nums[left];
                left++;
            }
            else{
                ans[pos]=nums[right]*nums[right];
                right--;
            }
            pos--;
        }
        return ans;
        
        
    }
};