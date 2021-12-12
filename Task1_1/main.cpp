#include <iostream>

//https://contest.yandex.ru/contest/30914/run-report/55737692/
//
//
//
//https://contest.yandex.ru/contest/30914/run-report/60918325/
//все работает)
struct Trio{
    int X;
    int Y;
    int Z;
    int Indx;
    bool operator<(const Trio& other) const {
        if (X < other.X && Y < other.Y && Z < other.Z) {
            return true;
        }else if(X < other.X && Y < other.Z && Z < other.Y){
            return true;
        }else if(X < other.Y && Y < other.X && Z < other.Z){
            return true;
        }else if(X < other.Y && Y < other.Z && Z < other.Y){
            return true;
        }else if(X < other.Z && Y < other.Y && Z < other.X){
            return true;
        }else if(X < other.Z && Y < other.X && Z < other.Y){
            return true;
        }else {
            return false;
        }
    }
};

void Sort(Trio *arr,int n){
    for(int i=1;i<n;i++) {
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

    int n=0;
    std::cin>>n;
    Trio* arr=new Trio[n];
    for(int i=0;i<n;i++) {
        Trio Troyechka;
        int a=0,b=0,c=0;
        std::cin>>a>>b>>c;
        Troyechka.X=a;
        Troyechka.Y=b;
        Troyechka.Z=c;
        Troyechka.Indx=i;

        arr[i]=Troyechka;
    }

    Sort(arr, n);

    for(int i=0;i<n;i++){
        std::cout<<arr[i].Indx<<" ";
    }

    delete[] arr;
    return 0;
}
