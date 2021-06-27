using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace LeetCode_Problem {
    public class MajorityElement {
        public int Majority_Element(int[] nums) {
            int result = -1;
            int maxCnt = -1;
            var dic = new Dictionary<int,int>();
            int size = nums.Length;
            for (int i = 0; i < size; i++) {
                var cursor = nums[i];
                if (!dic.ContainsKey(cursor)) dic.Add(cursor, 0);
                if (dic[cursor] >= size / 2 + 1) {
                    result = cursor;
                    break;
                }

                ++dic[cursor];
                if (dic[cursor] > maxCnt) {
                    maxCnt = dic[cursor];
                    result = cursor;
                }
            }

            return result;
        }
    }
}