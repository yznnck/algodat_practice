#include "binary_search.h"

int binary_search(int *arr, int len, int val) {
    int l = 0;
    int r = len - 1;
    int mid = r / 2;

    while (l != r) {
        if (arr[mid] == val) {
            return arr[mid];
        } else if (arr[mid] < val) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }

        mid = l + ((r - l) / 2);
    }

    if (arr[mid] == val) return arr[mid];
    return -1;
}

int binary_search_rec(int *arr, int val, int l, int r) {
    int m = (l + r) / 2;
    if (arr[m] == val) return arr[m];
    else if (m == l && m == r) return -1;
    else if (arr[m] < val) {
        l = m + 1;
        return binary_search_rec(arr, val, l, r);
    } else {
        r = m - 1;
        return binary_search_rec(arr, val, l, r);
    }
}

void test_binary_search() {
    int arr[] = {1, 3, 4, 6, 9, 33, 80, 120};
    assert(binary_search(arr, arr_size(arr), 1) == 1);
    assert(binary_search(arr, arr_size(arr), 3) == 3);
    assert(binary_search(arr, arr_size(arr), 4) == 4);
    assert(binary_search(arr, arr_size(arr), 6) == 6);
    assert(binary_search(arr, arr_size(arr), 9) == 9);
    assert(binary_search(arr, arr_size(arr), 33) == 33);
    assert(binary_search(arr, arr_size(arr), 80) == 80);
    assert(binary_search(arr, arr_size(arr), 120) == 120);
    assert(binary_search(arr, arr_size(arr), 20) == -1);
}

void test_binary_search_rec() {
    int arr[] = {1, 3, 4, 6, 9, 33, 80, 120};
    assert(binary_search_rec(arr, 1, 0, arr_size(arr) - 1) == 1);
    assert(binary_search_rec(arr, 3, 0, arr_size(arr) - 1) == 3);
    assert(binary_search_rec(arr, 4, 0, arr_size(arr) - 1) == 4);
    assert(binary_search_rec(arr, 6, 0, arr_size(arr) - 1) == 6);
    assert(binary_search_rec(arr, 9, 0, arr_size(arr) - 1) == 9);
    assert(binary_search_rec(arr, 33, 0, arr_size(arr) - 1) == 33);
    assert(binary_search_rec(arr, 80, 0, arr_size(arr) - 1) == 80);
    assert(binary_search_rec(arr, 120, 0, arr_size(arr) - 1) == 120);
    assert(binary_search_rec(arr, 20, 0, arr_size(arr) - 1) == -1);
}

void run_all_tests() {
    test_binary_search();
    test_binary_search_rec();
}

int main() {
    run_all_tests();
    return 0;
}