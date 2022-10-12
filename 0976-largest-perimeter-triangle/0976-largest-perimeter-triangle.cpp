class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int MAX = 0, SUM = 1, len = nums.size();
        sort(nums.begin(), nums.end());
        
        int one, two, three;
        
        for (int i = len - 1; i >= 2; i--) {
            three = nums[i];
            
            for (int j = i - 1; j >= 1; j--) {
                two = nums[j];
                
                for (int k = j - 1; k >= 0; k--) {
                    one = nums[k];
                    
                    SUM = one + two + three;
                    
                    if (one + two > three && SUM > MAX) MAX = SUM;
                    if (one + two <= three || SUM <= MAX) break;
                }
                
                if (one + two <= three || SUM <= MAX) break;
            }
        }
        
        cout << one << " " << two << " " << three;
        
        return MAX;
    }
};