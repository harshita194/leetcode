class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        HashMap<Integer,Integer> mp = new HashMap<>();
        for(int i=0; i<n; i++){
            int count = mp.getOrDefault(nums[i], 0);
            mp.put(nums[i], count + 1);

            if (mp.get(nums[i]) > n / 2) {
                return nums[i];
            }
        } 
        return -1;
    }
}