#include <iostream>

//https://contest.yandex.ru/contest/30914/run-report/55737692/

struct Trio {
    int X;
    int Y;
    int Z;
    int Indx;

    bool operator<(const Trio &other) const {
        if (X < other.X && Y < other.Y && Z < other.Z) {
            return true;
        } else if (X < other.X && Y < other.Z && Z < other.Y) {
            return true;
        } else if (X < other.Y && Y < other.X && Z < other.Z) {
            return true;
        } else if (X < other.Y && Y < other.Z && Z < other.Y) {
            return true;
        } else if (X < other.Z && Y < other.Y && Z < other.X) {
            return true;
        } else if (X < other.Z && Y < other.X && Z < other.Y) {
            return true;
        } else {
            return false;
        }
    }
};

void SortTrio(Trio *arr, int i) {

    Trio Troyechka = arr[i];

    if (Troyechka.X < Troyechka.Z && Troyechka.Z < Troyechka.Y) {
        int a = Troyechka.Y;
        Troyechka.Y = Troyechka.Z;
        Troyechka.Z = a;

    } else if (Troyechka.Y < Troyechka.Z && Troyechka.Z < Troyechka.X) {
        int a = Troyechka.X;
        Troyechka.X = Troyechka.Y;
        Troyechka.Y = a;

        a = Troyechka.Y;
        Troyechka.Y = Troyechka.Z;
        Troyechka.Z = a;

    } else if (Troyechka.Y < Troyechka.X && Troyechka.X < Troyechka.Z) {
        int a = Troyechka.X;
        Troyechka.X = Troyechka.Y;
        Troyechka.Y = a;

    } else if (Troyechka.Z < Troyechka.Y && Troyechka.Y < Troyechka.X) {
        int a = Troyechka.X;
        Troyechka.X = Troyechka.Z;
        Troyechka.Z = a;

    } else if (Troyechka.Z < Troyechka.X && Troyechka.X < Troyechka.Y) {
        int a = Troyechka.X;
        Troyechka.X = Troyechka.Z;
        Troyechka.Z = a;

        a = Troyechka.Y;
        Troyechka.Y = Troyechka.Z;
        Troyechka.Z = a;
    }
    arr[i] = Troyechka;
}

void Sort(Trio *arr, int n) {
    for (int i = 1; i < n; i++) {
        Trio key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    std::cin >> n;
    Trio *arr = new Trio[n];
    for (int i = 0; i < n; i++) {
        Trio Troyechka;
        int a = 0, b = 0, c = 0;
        std::cin >> a >> b >> c;
        Troyechka.X = a;
        Troyechka.Y = b;
        Troyechka.Z = c;
        Troyechka.Indx = i;

        arr[i] = Troyechka;
    }

    Sort(reinterpret_cast<Trio *>(arr), n);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i].Indx << " ";
    }

    delete[] arr;
    //делитнуть матрицу
    return 0;
}
