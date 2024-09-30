#include <stdio.h>

int main() {
    int nums[] = {1, 2, 3, 2, 5, 6, 1, 7, 8, 9};
    int n = sizeof(nums) / sizeof(nums[0]);

    int inc_len = 1, dec_len = 1;
    int max_inc_len = 1, max_dec_len = 1;
    int inc_start = 0, dec_start = 0;

    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i-1]) {
            inc_len++;
            if (inc_len > max_inc_len) {
                max_inc_len = inc_len;
                inc_start = i - inc_len + 1;
            }
        } else {
            inc_len = 1;
        }

        if (nums[i] < nums[i-1]) {
            dec_len++;
            if (dec_len > max_dec_len) {
                max_dec_len = dec_len;
                dec_start = i - dec_len + 1;
            }
        } else {
            dec_len = 1;
        }
    }

    printf("The longest increasing set has length %d: ", max_inc_len);
    for (int i = inc_start; i < inc_start + max_inc_len; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    printf("The longest decreasing set has length %d: ", max_dec_len);
    for (int i = dec_start; i < dec_start + max_dec_len; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
