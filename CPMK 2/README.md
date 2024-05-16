# <h1 align="center">Tugas 2 Struktur Data</h1>

<p align="center">Muhammad Azka</p>

#### CPMK 2 – SubCPMK 2

1. **Penjelasan Alur dan Runtime Algoritma Sorting**

   - **Bubble Sort**
     - **Alur:** Bubble Sort bekerja dengan membandingkan dua elemen yang berdampingan dan menukarnya jika berada dalam urutan yang salah. Proses ini diulang sampai seluruh array terurut.
     - **Best Case:** O(n) - terjadi ketika array sudah terurut.
     - **Worst Case:** O(n^2) - terjadi ketika array terurut dalam urutan terbalik.

   - **Selection Sort**
     - **Alur:** Selection Sort mencari elemen terkecil dari bagian array yang tidak terurut dan menukarnya dengan elemen pertama dari bagian tersebut. Proses ini diulang sampai seluruh array terurut.
     - **Best Case:** O(n^2) - karena harus melakukan n(n-1)/2 perbandingan dalam kasus terbaik sekalipun.
     - **Worst Case:** O(n^2) - karena tetap melakukan n(n-1)/2 perbandingan dalam kasus terburuk.

   - **Merge Sort**
     - **Alur:** Merge Sort adalah algoritma divide and conquer yang membagi array menjadi dua bagian, mengurutkan kedua bagian tersebut secara rekursif, dan kemudian menggabungkan keduanya menjadi array yang terurut.
     - **Best Case:** O(n log n) - pembagian dan penggabungan tetap membutuhkan waktu O(log n).
     - **Worst Case:** O(n log n) - pembagian dan penggabungan tetap membutuhkan waktu O(log n).

2. **Fungsi Bubble Sort**

   ```cpp
   #include <iostream>
   using namespace std;

   void bubbleSort(int arr[], int n) {
       for (int i = 0; i < n-1; i++) {
           for (int j = 0; j < n-i-1; j++) {
               if (arr[j] > arr[j+1]) {
                   // Tukar arr[j] dan arr[j+1]
                   int temp = arr[j];
                   arr[j] = arr[j+1];
                   arr[j+1] = temp;
               }
           }
       }
   }

   void printArray(int arr[], int size) {
       for (int i = 0; i < size; i++)
           cout << arr[i] << " ";
       cout << endl;
   }

   int main() {
       int arr[] = {64, 25, 12, 22, 11};
       int n = sizeof(arr)/sizeof(arr[0]);
       bubbleSort(arr, n);
       cout << "Array terurut: \n";
       printArray(arr, n);
       return 0;
   }
   ```

   **Penjelasan Program:** Program ini mengimplementasikan algoritma Bubble Sort untuk mengurutkan array `arr`. Fungsi `bubbleSort` akan membandingkan dan menukar elemen jika tidak dalam urutan yang benar. Fungsi `printArray` digunakan untuk mencetak array yang terurut.

3. **Fungsi Anagram Checker**

   ```cpp
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
       string str1 = "bahu";
       string str2 = "buah";
       if (areAnagram(str1, str2))
           cout << "Anagram" << endl;
       else
           cout << "Tidak Anagram" << endl;

       str1 = "makan";
       str2 = "minum";
       if (areAnagram(str1, str2))
           cout << "Anagram" << endl;
       else
           cout << "Tidak Anagram" << endl;

       return 0;
   }
   ```

   **Penjelasan Program:** Program ini mengimplementasikan fungsi `areAnagram` yang mengecek apakah dua string adalah anagram. Jika panjang string berbeda, maka bukan anagram. Jika panjang sama, kedua string diurutkan dan dibandingkan.

4. **Fungsi Menggabungkan Dua Array**

   ```cpp
   #include <iostream>
   using namespace std;

   void merge(int arr1[], int arr2[], int n1, int n2, int arr3[]) {
       int i = 0, j = 0, k = 0;
       while (i < n1 && j < n2) {
           if (arr1[i] < arr2[j])
               arr3[k++] = arr1[i++];
           else
               arr3[k++] = arr2[j++];
       }
       while (i < n1)
           arr3[k++] = arr1[i++];
       while (j < n2)
           arr3[k++] = arr2[j++];
   }

   int main() {
       int arr1[] = {1, 3, 5, 7};
       int n1 = sizeof(arr1)/sizeof(arr1[0]);
       int arr2[] = {2, 4, 6, 8};
       int n2 = sizeof(arr2)/sizeof(arr2[0]);
       int arr3[n1+n2];

       merge(arr1, arr2, n1, n2, arr3);

       cout << "Array setelah digabung: \n";
       for (int i = 0; i < n1 + n2; i++)
           cout << arr3[i] << " ";

       return 0;
   }
   ```

   **Penjelasan Program:** Program ini menggabungkan dua array terurut `arr1` dan `arr2` menjadi array `arr3` yang juga terurut. Fungsi `merge` menggabungkan kedua array dengan membandingkan elemen-elemen dari kedua array secara berurutan.

#### CPMK 2 – SubCPMK 3

1. **Penjelasan Alur dan Runtime Algoritma Searching**

   - **Binary Search**
     - **Alur:** Binary Search mencari elemen dengan membagi array menjadi dua dan memeriksa apakah elemen tengah adalah elemen yang dicari, atau elemen tersebut berada di kiri atau kanan. Proses ini diulang pada bagian array yang sesuai.
     - **Best Case:** O(1) - terjadi ketika elemen tengah adalah elemen yang dicari.
     - **Worst Case:** O(log n) - terjadi ketika harus membagi array sampai hanya tersisa satu elemen.

   - **Linear Search**
     - **Alur:** Linear Search mencari elemen dengan memeriksa setiap elemen dalam array satu per satu dari awal hingga akhir.
     - **Best Case:** O(1) - terjadi ketika elemen yang dicari adalah elemen pertama.
     - **Worst Case:** O(n) - terjadi ketika elemen yang dicari berada di akhir array atau tidak ada dalam array.

2. **Fungsi Binary Search**

   ```cpp
   #include <iostream>
   using namespace std;

   int binarySearch(int arr[], int l, int r, int x) {
       while (l <= r) {
           int m = l + (r - l) / 2;
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
       int arr[] = {2, 3, 4, 10, 40};
       int n = sizeof(arr) / sizeof(arr[0]);
       int x = 10;
       int result = binarySearch(arr, 0, n - 1, x);
       (result == -1) ? cout << "Elemen tidak ditemukan" : cout << "Elemen " << x << " ditemukan pada indeks ke-" << result;
       return 0;
   }
   ```

   **Penjelasan Program:** Program ini mengimplementasikan Binary Search untuk mencari elemen `x` dalam array `arr`. Fungsi `binarySearch` menggunakan loop untuk membagi array dan mencari elemen yang sesuai.

3. **Fungsi Mencari Kata dalam Array dengan String Kosong**

   ```cpp
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
   ```

   **Penjelasan Program:** Program ini mencari indeks dari kata `x` dalam array `arr` yang berisi string kosong. Fungsi `searchString` menggunakan modifikasi Binary Search untuk melewati string kosong dan mencari kata yang diinginkan.

#### CPMK 2 – SubCPMK 4

1. **Penjelasan Struct dan Contoh Program**

   **Penjelasan Struct:** `struct` adalah tipe data yang digunakan untuk mengelompokkan beberapa variabel dengan tipe data yang berbeda di bawah satu nama. Struct sering digunakan untuk membuat tipe data yang lebih kompleks yang menggambarkan objek dunia nyata.

   ```cpp
   #include <iostream>
   using namespace std;

   struct Mahasiswa {
       string nama;
       int umur;
       string jurusan;
   };

   int main() {
       Mahasiswa mhs1;
       mhs1.nama = "Azka";
       mhs1.umur = 18;
       mhs1.jurusan = "Sains Data";

       cout << "Nama    : " << mhs1.nama << endl;
       cout << "Umur    : " << mhs1.umur << endl;
       cout << "Jurusan : " << mhs1.jurusan << endl;

       return 0;
   }
   ```

   **Penjelasan Program:** Program ini mendefinisikan sebuah `struct` bernama `Mahasiswa` dengan tiga anggota: `nama`, `umur`, dan `jurusan`. Kemudian, program membuat objek `Mahasiswa`, mengisi data anggota, dan mencetaknya.

#### CPMK 2 – SubCPMK 5

1. **Fungsi Menghilangkan Duplikasi pada Unsorted Linked List**

   ```cpp
   #include <iostream>
   #include <unordered_set>
   using namespace std;

   struct Node {
       int data;
       Node* next;
   };

   void removeDuplicates(Node* head) {
       unordered_set<int> seen;
       Node* current = head;
       Node* prev = NULL;
       while (current != NULL) {
           if (seen.find(current->data) != seen.end()) {
               prev->next = current->next;
               delete current;
           } else {
               seen.insert(current->data);
               prev = current;
           }
           current = prev->next;
       }
   }

   void push(Node** head_ref, int new_data) {
       Node* new_node = new Node();
       new_node->data = new_data;
       new_node->next = (*head_ref);
       (*head_ref) = new_node;
   }

   void printList(Node *node) {
       while (node != NULL) {
           cout << node->data << " ";
           node = node->next;
       }
   }

   int main() {
       Node* head = NULL;
       push(&head, 10);
       push(&head, 20);
       push(&head, 10);
       push(&head, 30);
       push(&head, 40);
       push(&head, 30);

       cout << "Linked list sebelum duplikasi dihilangkan: \n";
       printList(head);

       removeDuplicates(head);

       cout << "\nLinked list setelah duplikasi dihilangkan: \n";
       printList(head);

       return 0;
   }
   ```

   **Penjelasan Program:** Program ini menghilangkan duplikasi pada linked list dengan menggunakan `unordered_set` untuk melacak elemen yang telah ditemukan. Fungsi `removeDuplicates` akan menghapus node yang berisi data duplikat.

2. **Algoritma dan Fungsi Menghapus Node di Tengah Single Linked List**

   ```cpp
   #include <iostream>
   using namespace std;

   struct Node {
       int data;
       Node* next;
   };

   void deleteMiddleNode(Node* head) {
       if (head == NULL || head->next == NULL)
           return;
       Node *slow = head, *fast = head, *prev = NULL;
       while (fast != NULL && fast->next != NULL) {
           fast = fast->next->next;
           prev = slow;
           slow = slow->next;
       }
       prev->next = slow->next;
       delete slow;
   }

   void push(Node** head_ref, int new_data) {
       Node* new_node = new Node();
       new_node->data = new_data;
       new_node->next = (*head_ref);
       (*head_ref) = new_node;
   }

   void printList(Node *node) {
       while (node != NULL) {
           cout << node->data << " ";
           node = node->next;
       }
   }

   int main() {
       Node* head = NULL;
       push(&head, 1);
       push(&head, 2);
       push(&head, 3);
       push(&head, 4);
       push(&head, 5);

       cout << "Linked list sebelum menghapus node tengah: \n";
       printList(head);

       deleteMiddleNode(head);

       cout << "\nLinked list setelah menghapus node tengah: \n";
       printList(head);

       return 0;
   }
   ```

   **Penjelasan Program:** Program ini menghapus node di tengah linked list dengan menggunakan dua pointer: `slow` dan `fast`. Pointer `slow` bergerak satu langkah setiap iterasi, sedangkan pointer `fast` bergerak dua langkah. Saat `fast` mencapai akhir, `slow` berada di tengah.

3. **Fungsi Mengecek Linked List Palindrom**

   ```cpp
   #include <iostream>
   using namespace std;

   struct Node {
       char data;
       Node* next;
   };

   bool isPalindromeUtil(Node** left, Node* right) {
       if (right == NULL)
           return true;
       bool isp = isPalindromeUtil(left, right->next);
       if (isp == false)
           return false;
       bool isp1 = (right->data == (*left)->data);
       *left = (*left)->next;
       return isp1;
   }

   bool isPalindrome(Node* head) {
       return isPalindromeUtil(&head, head);
   }

   void push(Node** head_ref, char new_data) {
       Node* new_node = new Node();
       new_node->data = new_data;
       new_node->next = (*head_ref);
       (*head_ref) = new_node;
   }

   void printList(Node *node) {
       while (node != NULL) {
           cout << node->data << " ";
           node = node->next;
       }
   }

   int main() {
       Node* head = NULL;
       push(&head, 'r');
       push(&head, 'a');
       push(&head, 'd');
       push(&head, 'a');
       push(&head, 'r');

       cout << "Linked list: \n";
       printList(head);

       if (isPalindrome(head))
           cout << "\nLinked list adalah palindrom\n";
       else
           cout << "\nLinked list bukan palindrom\n";

       return 0;
   }
   ```

   **Penjelasan Program:** Program ini mengecek apakah linked list adalah palindrom dengan membandingkan data dari awal dan akhir linked list secara rekursif menggunakan dua pointer.

#### CPMK 2 – SubCPMK 6

1. **Program Operasi Stack**

   ```cpp
    #include <iostream>
    using namespace std;

    const int maksimal = 5;
    string arrayBuku[maksimal];
    int top = 0;

    bool isFull() {
        return (top == maksimal);
    }

    bool isEmpty() {
        return (top == 0);
    }

    void pushArrayBuku(string data) {
        if (isFull()) {
            cout << "Data telah penuh" << endl;
        } else {
            arrayBuku[top++] = data;
        }
    }

    void popArrayBuku() {
        if (isEmpty()) {
            cout << "Tidak ada data yang dihapus" << endl;
        } else {
            arrayBuku[--top] = "";
        }
    }

    void peekArrayBuku(int posisi) {
        if (isEmpty()) {
            cout << "Tidak ada data yang bisa dilihat" << endl;
        } else if (posisi <= top) {
            cout << "Posisi ke " << posisi << " adalah " << arrayBuku[top - posisi] << endl;
        } else {
            cout << "Posisi melebihi data yang ada" << endl;
        }
    }

    int countStack() {
        return top;
    }

    void changeArrayBuku(int posisi, string data) {
        if (posisi <= top) {
            arrayBuku[top - posisi] = data;
        } else {
            cout << "Posisi melebihi data yang ada" << endl;
        }
    }

    void destroyArraybuku() {
        while (!isEmpty()) {
            popArrayBuku();
        }
    }

    void cetakArrayBuku() {
        if (isEmpty()) {
            cout << "Tidak ada data yang dicetak" << endl;
        } else {
            for (int i = top - 1; i >= 0; i--) {
                cout << arrayBuku[i] << endl;
            }
        }
    }

    int main() {
        pushArrayBuku("Kalkulus");
        pushArrayBuku("Struktur Data");
        pushArrayBuku("Matematika Diskrit");
        pushArrayBuku("Dasar Multimedia");
        pushArrayBuku("Inggris");

        cetakArrayBuku();
        cout << "\n";

        cout << "Apakah data stack penuh? " << isFull() << endl;
        cout << "Apakah data stack kosong? " << isEmpty() << endl;

        peekArrayBuku(2);
        popArrayBuku();

        cout << "Banyaknya data = " << countStack() << endl;

        changeArrayBuku(2, "Bahasa Jerman");
        cetakArrayBuku();

        cout << "\n";
        destroyArraybuku();
        cout << "Jumlah data setelah dihapus: " << top << endl;

        cetakArrayBuku();

        return 0;
    }
   ```

   **Penjelasan Program:** Program ini mengimplementasikan operasi dasar stack (push, pop, peek, destroy, change, cetak, isEmpty, isFull) menggunakan array.

2. **Program Mengurutkan Stack**

   ```cpp
   #include <iostream>
   #include <stack>
   using namespace std;

   void sortedInsert(stack<int>& s, int x) {
       if (s.empty() || x > s.top()) {
           s.push(x);
           return;
       }
       int temp = s.top();
       s.pop();
       sortedInsert(s, x);
       s.push(temp);
   }

   void sortStack(stack<int>& s) {
       if (!s.empty()) {
           int x = s.top();
           s.pop();
           sortStack(s);
           sortedInsert(s, x);
       }
   }

   void printStack(stack<int> s) {
       while (!s.empty()) {
           cout << s.top() << " ";
           s.pop();
       }
       cout << endl;
   }

   int main() {
       stack<int> s;
       s.push(30);
       s.push(10);
       s.push(20);
       s.push(5);
       s.push(1);

       cout << "Stack sebelum diurutkan: \n";
       printStack(s);

       sortStack(s);

       cout << "Stack setelah diurutkan: \n";
       printStack(s);

       return 0;
   }
   ```

   **Penjelasan Program:** Program ini mengurutkan stack menggunakan rekursi. Fungsi `sortedInsert` memasukkan elemen ke dalam stack yang telah diurutkan, sedangkan `sortStack` mengeluarkan elemen dari stack dan memasukkannya kembali dalam urutan yang benar.

#### CPMK 2 – SubCPMK 7

1. **Program Operasi Queue**

   ```cpp
    #include <iostream>

    using namespace std;

    const int maksimalQueue = 5;
    int front = 0;
    int back = 0;

    string queueTeller[5];

    bool isFull() {
        if (back == maksimalQueue) {
            return true;
        } else {
            return false;
        }
    }

    bool isEmpty() {
        if (back == 0) {
            return true;
        } else {
            return false;
        }
    }

    void enqueueAntrian(string data) {
        if (isFull()) {
            cout << "Antrian Penuh" << endl;
        } else {
            if (isEmpty()) {
                queueTeller[0] = data;
                front++;
                back++;
            } else {
                queueTeller[back] = data;
                back++;
            }
        }
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            for (int i = 0; i < back; i++) {
                queueTeller[i] = queueTeller[i + 1];
            }
            back--;
        }
    }

    int countQueue() {
        return back;
    }

    void clearQueue() {
        if (isEmpty()) {
            cout  << "Antrian masih kosong" << endl;
        } else {
            for  (int i = 0 ; i < back ; i++ )
                queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }

    void viewQueue() {
        cout << "Data antrian teller: " << endl;
        for (int i = 0; i < maksimalQueue; i++) {
            if (queueTeller[i] != "") {
                cout << i + 1 << ". " << queueTeller[i] << endl;
            } else {
                cout << i + 1 << ". (kosong)" << endl;
            }
        }
    }

    int main() {
        enqueueAntrian("Andi");
        enqueueAntrian("Maya");
        viewQueue();
        cout << "Jumlah antrian = " << countQueue() << endl;
        dequeueAntrian();
        viewQueue();
        cout << "Jumlah antrian = " << countQueue() << endl;
        clearQueue();
        viewQueue();
        cout << "Jumlah antrian = " << countQueue() << endl;
        return 0;
    }
   ```

   **Penjelasan Program:** Program ini mengimplementasikan operasi dasar queue (enqueue, dequeue, countqueue, view, clear, isEmpty, isFull) menggunakan array.

2. **Implementasi Queue dengan Dua Stack**

   ```cpp
    #include <iostream>
    #include <string>

    using namespace std;

    struct Animal {
        string type;
        string name;
        int order;
    };

    struct Node {
        Animal data;
        Node* next;
    };

    Node* frontDog = NULL;
    Node* backDog = NULL;
    Node* frontCat = NULL;
    Node* backCat = NULL;
    int order = 0;

    bool isEmpty(Node* front) {
        return front == NULL;
    }

    void enqueueAnimal(string type, string name) {
        Node* newNode = new Node;
        newNode->data.type = type;
        newNode->data.name = name;
        newNode->data.order = order++;
        newNode->next = NULL;

        if (type == "anjing") {
            if (isEmpty(frontDog)) {
                frontDog = backDog = newNode;
            } else {
                backDog->next = newNode;
                backDog = newNode;
            }
        } else if (type == "kucing") {
            if (isEmpty(frontCat)) {
                frontCat = backCat = newNode;
            } else {
                backCat->next = newNode;
                backCat = newNode;
            }
        } else {
            cout << "Tipe hewan invalid!" << endl;
            delete newNode;
        }
    }

    Animal dequeueDog() {
        if (isEmpty(frontDog)) {
            throw runtime_error("Tidak ada anjing di selter");
        }
        Node* temp = frontDog;
        Animal dog = temp->data;
        frontDog = frontDog->next;
        if (frontDog == NULL) {
            backDog = NULL;
        }
        delete temp;
        return dog;
    }

    Animal dequeueCat() {
        if (isEmpty(frontCat)) {
            throw runtime_error("Tidak ada kucing di selter");
        }
        Node* temp = frontCat;
        Animal cat = temp->data;
        frontCat = frontCat->next;
        if (frontCat == NULL) {
            backCat = NULL;
        }
        delete temp;
        return cat;
    }

    Animal dequeueAny() {
        if (isEmpty(frontDog) && isEmpty(frontCat)) {
            throw runtime_error("Tidak ada hewan di selter");
        } else if (isEmpty(frontDog)) {
            return dequeueCat();
        } else if (isEmpty(frontCat)) {
            return dequeueDog();
        }

        if (frontDog->data.order < frontCat->data.order) {
            return dequeueDog();
        } else {
            return dequeueCat();
        }
    }

    void viewQueue(Node* front) {
        Node* current = front;
        while (current != NULL) {
            cout << "- Nama: " << current->data.name << ", Tipe: " << current->data.type << ", Urutan: " << current->data.order << endl;
            current = current->next;
        }
    }

    int main() {
        enqueueAnimal("anjing", "Buddy");
        enqueueAnimal("kucing", "Whiskers");
        enqueueAnimal("anjing", "Rex");
        enqueueAnimal("kucing", "Mittens");

        cout << "Semua hewan di selter:" << endl;
        cout << "Anjing:" << endl;
        viewQueue(frontDog);
        cout << "Kucing:" << endl;
        viewQueue(frontCat);

        try {
            Animal adopted = dequeueAny();
            cout << "Hewan yang diadopsi: " << adopted.type << " bernama " << adopted.name << endl;
            adopted = dequeueDog();
            cout << "Anjing yang diadopsi: " << adopted.name << endl;
            adopted = dequeueCat();
            cout << "Kucing yang diadopsi: " << adopted.name << endl;
            adopted = dequeueAny();
            cout << "Hewan yang diadopsi: " << adopted.type << " bernama " << adopted.name << endl;
        } catch (const exception& e) {
            cout << e.what() << endl;
        }

        return 0;
    }
   ```

   **Penjelasan Program:** Program ini mengimplementasikan antrian hewan terlantar menggunakan struktur data linked list dengan dua antrian terpisah untuk anjing dan kucing. Fungsi enqueueAnimal menambahkan hewan ke antrian yang sesuai berdasarkan tipe (anjing atau kucing). Fungsi dequeueAny mengadopsi hewan yang paling tua tanpa memandang tipe, sementara fungsi dequeueDog dan dequeueCat masing-masing mengadopsi anjing atau kucing yang paling tua. Fungsi viewQueue menampilkan semua hewan dalam antrian yang diberikan.