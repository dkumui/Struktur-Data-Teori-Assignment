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