class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i: nums) mp[i]++;
        int maxStreak = 0;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i])) continue;
            int currentStreak = 0;
            int start = nums[i];
            while(mp.find(start)!=mp.end()){
                currentStreak++;
                start++;
                s.insert(start);
            }
            maxStreak = max(maxStreak, currentStreak);
        }
        return maxStreak;
    }
};
