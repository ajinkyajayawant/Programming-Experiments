/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int loc[2] = {0,0};
int* twoSum(int* nums, int numsSize, int target) {
    int *pnum;
  bool got = false;
  for(int i=0;i<numsSize && !got;++i){
    for(int j=i+1;j<numsSize && !got;++j){
      if(nums[i]+nums[j]==target){
	loc[0] = i;
	loc[1] = j;
	got = true;
      }
    }
  }
  pnum = loc;
  return pnum;
}
