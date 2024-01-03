#include <vector>
using namespace std;
#include <unordered_set>
#include <set>
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> pair(2);
        // unordered_set<int> diff;
        // unordered_set<int> numsh;
        // for(int i = 0; i < nums.size(); i++){
        //     if(numsh.count(nums[0]) == 0 ){
        //         numsh.insert(nums[0]);
        //         if(diff.count(target - nums[0]) == 0){
        //             diff.insert(target - nums[0]);
        //         }
        //         else{

        //         }
        //     }
        // }
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    pair[0] = i;
                    pair[1] = j;
                }
            }
        }
        return pair;
        /*class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        indices= [0] * 2 # makes an array = [0,0]
        dict = {}
        # 2 ways to loop: for i in range(something): OR for element in nums: enumerate gives us an index to iterate and the value that i is currently at.
        for i, val in enumerate(nums):
            if val in dict.keys():
                indices[0] = i
                indices[1] = dict[val]
                return indices
            dict[target - val] = i
        */
    }
};