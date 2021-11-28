#include <iostream>
#include <stdint.h>
#include <vector>

//https://contest.yandex.ru/contest/30914/run-report/58485583/

int64_t merge_sort(std::vector<int> &v, int left, int right) {

    if (right - left <= 1) {
        return 0;
    }

    const int mid = (left + right) / 2;

    int64_t inversions_count = merge_sort(v, left, mid);
    inversions_count += merge_sort(v, mid, right);

    int m_left = left;
    int m_right = mid;
    std::vector<int> buffer(right - left);
    int merge_index = 0;

    while (m_left < mid || m_right < right) {

        if (m_left < mid && m_right < right) {
            if (v[m_left] <= v[m_right]) {
                inversions_count += m_right - mid;
                buffer[merge_index++] = v[m_left++];

            } else {
                buffer[merge_index++] = v[m_right++];
            }

        } else if (m_left < mid) {
            inversions_count += right - mid;
            buffer[merge_index++] = v[m_left++];

        } else {
            buffer[merge_index++] = v[m_right++];
        }
    }

    for (int i = 0; i < buffer.size(); i++) {
        v[left + i] = buffer[i];
    }

    return inversions_count;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int a = 0;
    std::vector<int> v;

    while (std::cin >> a) {
        v.push_back(a);
    }

    int64_t cnt = merge_sort(v, 0, v.size());
    printf("%ld\n", cnt);

    return 0;
}
