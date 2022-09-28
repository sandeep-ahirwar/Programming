class Solution {
private:
    bool isEven(int n){
        if(n%2==0) return true;
        else return false;
    }
public:
    int mostFrequentEven(vector<int>& nums) {
        int len = sizeof(nums) / sizeof(nums[0]);
        unordered_map<int, int> even;
        for (int i=0; i<len; i++){
            if (isEven(nums[i])){
                even[nums[i]]++;
            }
        }
        
        int mCount = 0, result = -1;
        for (auto i : even) {
            if (mCount < i.second) {
                result = i.first;
                mCount = i.second;
            }
            
            if(i.second == i.first){
                result = min(i.first, i.second);
            }
        }
        return result;
        
    }
};