# <h1 align="center">Tugas 3 Struktur Data</h1>

<p align="center">Muhammad Azka</p>

## Features

- [Priority Queue](#priority-queue)
- [Hash Table](#hash-table)
- [Rekursif](#rekursif)
- [Graph & Tree](#graph--tree)
- [Referensi](#referensi)

## Priority Queue

Priority queue adalah struktur data yang memiliki elemen dengan prioritas tertentu untuk mengurutkan elemen-elemennya [1]. Elemen dengan prioritas tinggi akan menempati posisi paling atas dari antrian. Priority queue biasanya dilibatkan menggunakan heap biner atau heap biner minim dan maksimum.

Contoh program priority queue menggunakan C++:

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
  priority_queue<int> pq;

  pq.push(5);
  pq.push(3);
  pq.push(6);
  pq.push(2);
  pq.push(1);

  cout << "The maximum element is: " << pq.top() << endl;

  pq.pop();

  cout << "After deleting an element, the next maximum element is: "
       << pq.top() << endl;

  return 0;
}
```

Program diatas membuat priority queue dengan tipe data integer. Kemudian elemen dimasukkan ke dalam antrian dengan push. Fungsi top() digunakan untuk mendapatkan elemen dengan prioritas tertinggi. Fungsi pop() digunakan untuk menghapus elemen teratas.

## Hash Table

Hash table adalah struktur data yang digunakan untuk menyimpan pasangan kunci-nilai [2]. Hash table bekerja dengan mengkalkulasikan nilai hash dari kunci, kemudian menyimpan nilai yang sesuai pada lokasi tertentu di dalam tabel berdasarkan nilai hash tersebut. Penambahan, penghapusan dan pencarian nilai sangat efisien karena diakses langsung melalui hash function.

Contoh program hash table menggunakan C++:

```cpp
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

int main() {
  unordered_map<string, int> um;

  um["cpp"] = 35;
  um["java"] = 30;
  um["python"] = 27;

  cout << "python value is : " << um["python"] << endl;

  um.erase("cpp");

  return 0;
}
```

Program diatas membuat hash table menggunakan unordered_map dengan kunci string dan nilai integer. Kemudian nilai dimasukkan dan dicetak. Fungsi erase() digunakan untuk menghapus pasangan kunci-nilai.

## Rekursif

Rekursi adalah teknik pemrograman dimana suatu fungsi memanggil dirinya sendiri secara langsung atau tidak langsung [3]. Fungsi rekursif membutuhkan kondisi dasar untuk menghentikan rekursi dan mengembalikan nilai. Rekursi dapat digunakan untuk memecahkan masalah secara berulang seperti factorial, fibonacci, pencarian binary dan lain-lain.

Contoh program faktorial secara rekursif menggunakan C++:

```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
  if (n <= 1)
    return 1;
  else
    return n * factorial(n-1);
}

int main() {
  int number = 5;
  cout << number << " factorial is " << factorial(number) << endl;

  return 0;
}
```

Program diatas mendefinisikan fungsi factorial secara rekursif. Jika n ≤ 1 maka return 1, jika tidak maka panggil kembali factorial dengan nilai n - 1 dan kali dengan n. Fungsi ini akan terus dipanggil sampai n ≤ 1.

## Graph & Tree

Graph adalah kumpulan nodes yang saling terhubung [4]. Graph dapat direpresentasikan menggunakan adjacency list atau adjacency matrix. Sedangkan tree adalah graph khusus tanpa cycle dimana setiap pasangan nodes hanya terhubung oleh satu edge.

Contoh program representasi graph menggunakan adjacency list dalam C++:

```cpp
#include <list>
#include <iostream>
using namespace std;

class Graph {
  int V;
  list<int> *adj;

  public:
    Graph(int V);
    void addEdge(int v, int w);
    void printGraph();
};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

void Graph::printGraph() {
  for(int i = 0; i < V; i++) {
    cout << i << "->";
    for (int x : adj[i])
      cout << x << ",";
    cout << endl;
  }
}
```

Program ini merepresentasikan graf menggunakan adjacency list dimana setiap nodes memiliki list berisi nodes yang terhubung. Fungsi addEdge() untuk menambahkan edge dan printGraph untuk mencetak graf.

## Referensi

[1] GeeksForGeeks, "Priority Queue in C++ STL," 2022. [Online]. Available: https://www.geeksforgeeks.org/priority-queue-cpp-stl/. [Accessed June 20, 2024].

[2] GeeksForGeeks, "Unordered Map in C++ STL," 2022. [Online]. Available: https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/. [Accessed June 20, 2024].

[3] GeeksForGeeks, "Recursive Functions in C++," 2022. [Online]. Available: https://www.geeksforgeeks.org/recursive-functions-cpp/. [Accessed June 20, 2024].

[4] GeeksForGeeks, "Graph and its Representations," 2022. [Online]. Available: https://www.geeksforgeeks.org/graph-and-its-representations/. [Accessed June 20, 2024].
