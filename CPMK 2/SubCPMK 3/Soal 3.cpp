#include <iostream>
using namespace std;

int searchString(string arr[], int n, string x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        while (l <= r && arr[r] == "")
            r--;
        while (l <= r && arr[l] == "")
            l++;
        int m = l + (r - l) / 2;
        while (m < r && arr[m] == "")
            m++;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    string arr[] = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};
    int n = sizeof(arr) / sizeof(arr[0]);
    string x = "bola";
    int result = searchString(arr, n, x);
    (result == -1) ? cout << "Kata tidak ditemukan" : cout << "Kata ditemukan pada indeks " << result;
    return 0;
}