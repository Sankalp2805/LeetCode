class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const vector<int>* a = &nums1;
        const vector<int>* b = &nums2;
        if (a->size() > b->size()) swap(a, b);

        int m = a->size(), n = b->size();
        int totalLeft = (m + n + 1) / 2;
        int left = 0, right = m;

        while (left <= right) {
            int partitionA = left + (right - left) / 2;
            int partitionB = totalLeft - partitionA;

            int maxLeftA = (partitionA == 0) ? INT_MIN : (*a)[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : (*a)[partitionA];
            int maxLeftB = (partitionB == 0) ? INT_MIN : (*b)[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : (*b)[partitionB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0) {
                    long long sum = (long long)max(maxLeftA, maxLeftB) +
                                     min(minRightA, minRightB);
                    return sum / 2.0;
                }
                return max(maxLeftA, maxLeftB);
            } else if (maxLeftA > minRightB) {
                right = partitionA - 1;
            } else {
                left = partitionA + 1;
            }
        }
        return 0.0;
    }
};