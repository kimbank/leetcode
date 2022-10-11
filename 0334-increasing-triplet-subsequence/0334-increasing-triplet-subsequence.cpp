class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        
        int f = nums[0], s = 2147483647;
        for (auto t : nums) {
            if (t > s) return true;
            if (t > f) s = t;
            if (t < f) f = t;
        }
        
        return false;
    }
};