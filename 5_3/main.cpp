#include <iostream>
#include <vector>

//https://contest.yandex.ru/contest/30914/run-report/58830384/

int GetDigit(long long n, int i) {
//i [0;15]
    return (n >> (i * 4)) & ((1 << 4) - 1);
}

void CountingSort(std::vector<int64_t> &v, long long n, int i) {
    std::vector<int> buckets(16, 0);
    //массив ,в котором на j-том месте колличество элементов у которых 4 бит=j
    for (int j = 0; j < n; j++) {
        buckets[GetDigit(v[j], i)]++;
    }

    std::vector<int> borders(16, 0);
    //массив границ 4 битных значений borders[k-1]-левая граница,borders[k]-правая
    for (int k = 1; k < 16; k++) {
        borders[k] = borders[k - 1] + buckets[k - 1];
    }
    std::vector<int64_t> sorted(n);
    //расставляем элементы по местам, по их границам для их 4 битных значений
    for (int64_t number: v) {
        sorted[borders[GetDigit(number, i)]++] = number;
    }

    std::swap(v, sorted);
}

void SortLSD(std::vector<int64_t> &v, long long n) {
    for (int i = 0; i < 16; i++) {
        CountingSort(v, n, i);
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n = 0;
    std::cin >> n;

    std::vector<int64_t> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    SortLSD(v, n);

    for (int i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }

    return 0;
}
