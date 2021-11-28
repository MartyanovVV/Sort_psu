#include "sort.h"
#include <stack>

//https://contest.yandex.ru/contest/30914/run-report/59018964/

int Median3(unsigned int *v, int l, int m, int r) {
    if (v[l] <= v[m] && v[m] <= v[r]) {
        return m;
    } else if (v[l] <= v[r] && v[r] <= v[m]) {
        return r;
    } else if (v[m] <= v[l] && v[l] <= v[r]) {
        return l;
    } else if (v[m] <= v[r] && v[r] <= v[l]) {
        return r;
    } else if (v[r] <= v[l] && v[l] <= v[m]) {
        return l;
    } else if (v[r] <= v[m] && v[m] <= v[l]) {
        return m;
    }
}

int Partition(unsigned int *v, int l, int r) {

    int m = (l + r) / 2;
    int pivot = Median3(v, l, m, r);
    std::swap(v[pivot], v[l]);
    int i = r, j = r;
    while (l < i) {
        if (v[i] < v[l] && l < i || l < i && j <= i) {
            i--;
        }
        if (v[j] >= v[l] && l < j) {
            j--;
        }
        if (i < j) {
            std::swap(v[i], v[j]);
        }
    }
    return j;
}

void insertion_sort(unsigned int *arr, unsigned int size) {
    for (int i = 1; i < size; i++) {
        int temporary = arr[i];
        int j = i - 1;
        while (j >= 0 && temporary < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temporary;
    }
}

void Sort(unsigned int *arr, unsigned int n) {
    std::stack<int> stack_borders;

    stack_borders.push(n - 1);
    stack_borders.push(0);
    int left = 0, right = 0;

    do {
        left = stack_borders.top();
        stack_borders.pop();
        right = stack_borders.top();
        stack_borders.pop();
        int index_pivot = 0;

        if (((right - left) == 1) && (arr[left] > arr[right])) {
            std::swap(arr[left], arr[right]);
        } else {
            index_pivot = Partition(arr, left, right);
        }

        if (index_pivot - left <= 43) {
            //от left до idex_pivot-1
            insertion_sort(arr + left, index_pivot - left);
        } else {

            if (left < index_pivot - 1) {
                stack_borders.push(index_pivot - 1);
                stack_borders.push(left);
            }
        }
        //43 т.к. на примерах с контеста работае быстрее
        if (right - index_pivot <= 43) {

            insertion_sort(arr + index_pivot + 1, right - index_pivot);
            //от index_pivot+1 до right

        } else {

            if (index_pivot + 1 < right) {
                stack_borders.push(right);
                stack_borders.push(index_pivot + 1);
            }
        }

    } while (!stack_borders.empty());
}
