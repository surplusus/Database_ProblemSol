namespace LeetCode_Problem
{
    public class FindPivotIndex
    {
        public static int PivotIndex(int[] nums) {
            for(int idx = 0; idx < nums.Length; ++idx) {
                int leftSum = 0, rightSum = 0;
                for (int sumi = 0; sumi < nums.Length; sumi++) {
                    if (sumi < idx) {
                        leftSum += nums[sumi];
                    } else if (sumi > idx){
                        rightSum += nums[sumi];
                    }
                }
                if (leftSum == rightSum) {
                    return idx;
                }
            }
            return -1;
        }
    }
}