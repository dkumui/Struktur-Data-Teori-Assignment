#include <iostream>
#include <algorithm>
using namespace std;

bool areAnagram(string str1, string str2) {
    // Jika panjang kedua string tidak sama, maka bukan anagram
    if (str1.length() != str2.length())
        return false;

    // Mengurutkan kedua string
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Membandingkan string yang diurutkan
    for (int i = 0; i < str1.length(); i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}

int main() {
    string str1;
    string str2;
    cout << "Masukkan string pertama: ";
    cin >> str1;
    cout << "Masukkan string kedua: ";
    cin >> str2;

    if (areAnagram(str1, str2)) {
        cout << "kata " + str1 + " dan " + str2 + " anagram" << endl;
    } else {
        cout << "kata " + str1 + " dan " + str2 + " tidak anagram" << endl;
    }
}