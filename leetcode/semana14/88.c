void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p = m - 1;
    int r = n - 1;

    int t = nums1Size - 1;

    while ( p >= 0 && r >= 0) {
        if ( nums1[p] > nums2[r] ) {
            nums1[t] = nums1[p];
            p--;
        } else {
            nums1[t] = nums2[r];
            r--;
        }
        t--;
    }

    while (r >= 0) {
        nums1[t] = nums2[r];
        r--;
        t--;
    }
}