#include <iostream>
#include <vector>

//https://contest.yandex.ru/contest/30914/run-report/58486345/

struct Pairs {
    int Start;
    int Finish;

    bool operator<(const Pairs &Other) const {
        if (Finish < Other.Finish) {
            return true;
        } else if (Finish == Other.Finish) {
            if (Start <= Other.Start) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};

void Print(std::vector<Pairs> &arr, int n) {

    int finish = -999999999;
    int start = -999999999;
    int minuts = 0;

    for (int i = 0; i < n; i++) {

        if (start < arr[i].Start) {
            if (finish < arr[i].Start) {
                minuts += 2;
                finish = arr[i].Finish;
                start = arr[i].Finish - 1;

            } else if (finish < arr[i].Finish) {
                minuts += 1;
                start = finish;
                finish = arr[i].Finish;

            } else if (finish == arr[i].Finish) {
                minuts += 1;
                start = arr[i].Finish - 1;
            }
        }
    }
    std::cout << minuts;
}

void SiftDown(std::vector<Pairs> &pair, int i, int n) {
    while (i < n) {

        int one = i * 2 + 1;
        int two = i * 2 + 2;
        int help = i;

        if (one < n && (pair[help] < pair[one])) {
            help = one;
        }

        if (two < n && (pair[help] < pair[two])) {
            help = two;
        }

        if (help != i) {
            std::swap(pair[i], pair[help]);
            i = help;
        } else {
            break;
        }
    }
}

void BuildHeap(std::vector<Pairs> &pair, int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        SiftDown(pair, i, n);
    }
}

void HeapSort(std::vector<Pairs> &pair, int n) {
    BuildHeap(pair, n);
    for (int i = n - 1; i >= 0; i--) {
        std::swap(pair[0], pair[i]);
        SiftDown(pair, 0, i);
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    std::cin >> n;
    std::vector<Pairs> pair;

    for (int i = 0; i < n; i++) {
        Pairs p;
        std::cin >> p.Start >> p.Finish;
        pair.push_back(p);
    }

    HeapSort(pair, n);
    Print(pair, n);

    return 0;
}
