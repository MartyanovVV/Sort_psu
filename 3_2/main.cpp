#include <iostream>
#include <vector>

//https://contest.yandex.ru/contest/30914/run-report/58485912/

int Median3(std::vector<int> &v, int l, int m, int r) {
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

int Partition(std::vector<int> &v, int l, int r) {

    int m = (l + r) / 2;
    int pivot = Median3(v, l, m, r);
    std::swap(v[pivot], v[l]);
    int i = r, j = r;
    while (l < i) {
        if (v[i] < v[l] && l < i || l < i && j <= i)
        {
            i--;
        }
        if (v[j] >= v[l] && l < j)
        {
            j--;
        }
        if (i < j) {
            std::swap(v[i], v[j]);
        }
    }
    return j;
}

int KStat(std::vector<int> &v, int n, int k) {
    int l = 0, r = n - 1;
    while (true) {
        int pivot_pos = Partition(v, l, r);
        if (k == pivot_pos)
        {
            return v[k];
        } else if (k > pivot_pos)
        {
            l = pivot_pos + 1;
        } else {
            r = pivot_pos - 1;
        }
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    std::cin >> n;
    int k = 0;
    std::cin >> k;
    std::vector<int> v(n, 0);

    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    std::cout << KStat(v, n, k);
    return 0;
}
