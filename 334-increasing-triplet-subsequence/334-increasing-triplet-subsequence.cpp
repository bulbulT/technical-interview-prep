class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        
        int c1 = INT_MAX;
        int c2 = INT_MAX;
        
        for(auto x : nums){
            if(x <= c1){
                c1 = x;
            }
            
            else if(x <= c2){
                c2 = x;
            }
            
            else{
                return true;
            }
        }
        
        return false;
        
        
    }
};