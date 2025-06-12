int secLargest(vector<int> arr) {
    if (arr.size() < 2) {
        throw runtime_error("Array must contain at least two elements.");
    }

    int m = INT_MIN;
    int m2 = INT_MIN;

    for (int i : arr) {
        if (i > m) {
            m2 = m;
            m = i;
        } else if (i > m2 && i < m) {
            m2 = i;
        }
    }

    if (m2 == INT_MIN) {
        throw runtime_error("No second largest element found (all elements may be equal).");
    }

    return m2;
}
