#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


bool helper1(float num) {
    float diff = num - 24;
    return diff < 1e-5 && diff > -1e-5;
}

bool helper2(float* nums) {
    return (helper1(nums[0]+nums[1]) || helper1(nums[0]-nums[1]) || helper1(nums[0]*nums[1]) || (nums[1] && helper1(nums[0]/nums[1])));
}

bool helper3(float* nums) {
    for (int i = 0; i < 2; ++i) {
        for (int j = i+1; j < 3; ++j) {
            float tmpi = nums[i];
            float tmpj = nums[j];
            nums[i] = nums[j] = 0;
            float nums2[2];
            int l = 0;
            for (int k = 0; k < 3; ++k) {
                if (nums[k] != 0) {
                    nums2[l++] = nums[k];
                }
            }
            nums2[l] = tmpi+tmpj;
            if (helper2(nums2)) {
                return true;
            }
            nums2[l] = tmpi-tmpj;
            if (helper2(nums2)) {
                return true;
            }
            nums2[l] = tmpj-tmpi;
            if (helper2(nums2)) {
                return true;
            }
            nums2[l] = tmpi*tmpj;
            if (helper2(nums2)) {
                return true;
            }
            if (tmpj != 0) {
                nums2[l] = tmpi/tmpj;
                if (helper2(nums2)) {
                    return true;
                }
            }
            if (tmpi != 0) {
                nums2[l] = tmpj/tmpi;
                if (helper2(nums2)) {
                    return true;
                }
            }
            nums[i] = tmpi;
            nums[j] = tmpj;
        }
    }
    return false;
}


bool helper4(float* nums) {
    for (int i = 0; i < 3; ++i) {
        for (int j = i+1; j < 4; ++j) {
            float tmpi = nums[i];
            float tmpj = nums[j];
            nums[i] = nums[j] = 0;
            float nums3[3];
            int l = 0;
            for (int k = 0; k < 4; ++k) {
                if (nums[k] != 0) {
                    nums3[l++] = nums[k];
                }
            }
            nums3[l] = tmpi+tmpj;
            if (helper3(nums3)) {
                return true;
            }
            nums3[l] = tmpi-tmpj;
            if (helper3(nums3)) {
                return true;
            }
            nums3[l] = tmpj-tmpi;
            if (helper3(nums3)) {
                return true;
            }
            nums3[l] = tmpi*tmpj;
            if (helper3(nums3)) {
                return true;
            }
            nums3[l] = tmpi/tmpj;
            if (helper3(nums3)) {
                return true;
            }
            nums3[l] = tmpj/tmpi;
            if (helper3(nums3)) {
                return true;
            }
            nums[i] = tmpi;
            nums[j] = tmpj;
        }
    }
    return false;
}

// exhausted search.
bool judgePoint24(int* nums, int numsSize) {
    float numscpy[4];
    numscpy[0] = nums[0];numscpy[1] = nums[1];numscpy[2] = nums[2];numscpy[3] = nums[3];
    return helper4(numscpy);
}


int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

// "data orientated programming", will be revised.
bool judgePoint24Fast(int* nums, int numsSize) {
    int impossibles[] = {1111,1112,1113,1114,1115,1116,1117,1119,1122,1123,1124,1125,1133,1159,1167,1177,1178,1179,1189,1199,1222,1223,1299,1355,1499,1557,1558,1577,1667,1677,1678,1777,1778,1899,1999,2222,2226,2279,2299,2334,2555,2556,2599,2677,2777,2779,2799,2999,3358,3467,3488,3555,3577,4459,4466,4467,4499,4779,4999,5557,5558,5569,5579,5777,5778,5799,5899,5999,6667,6677,6678,6699,6777,6778,6779,6788,6999,7777,7778,7779,7788,7789,7799,7888,7899,7999,8888,8889,8899,8999,9999};
    qsort(nums, numsSize, sizeof(*nums), cmp);
    int num = nums[0]*1000+nums[1]*100+nums[2]*10+nums[3];
    for (int i = 0; i < sizeof(impossibles)/sizeof(impossibles[0]); ++i) {
        if (num == impossibles[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int nums[] = {4,1,8,7};
    printf("%s", judgePoint24(nums, 4) ? "yes" : "no");
    return 0;
}
