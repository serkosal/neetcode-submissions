class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0], cur_sz = 0, appeared = 0;
        for (int num : nums) {
            ++cur_sz;
            if (num == maj) ++appeared;
            if (appeared <= cur_sz / 2) {
                maj = num;
                appeared = 0;
                cur_sz = 0;
            }
        }

        return maj;
    }


};