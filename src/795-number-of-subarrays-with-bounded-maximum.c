#include <stdio.h>

int numSubarrayBoundedMax(int* A, int ASize, int L, int R) {
    int j = 0;
    int result = 0;
    int count = 0;
    for(int i=0;i<ASize;i++){
        if(A[i]>=L && A[i]<=R){
            result+=i-j+1;count=i-j+1;
        }
        else if(A[i]<L){
            result+=count;
        }
        else{
            j=i+1;
            count=0;
        }
    }
    return result;
}

int main() {
    int nums[] = {2,1,4,3};
    printf("%d", numSubarrayBoundedMax(nums, 4, 2, 3));
}
