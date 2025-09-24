/*
 * Структура Node:
 *   Представляє вузол двозв’язного списку, містить дані, покажчики на наступний і попередній вузол.
 *
 * Node* createList(int n):
 *   Створює двозв’язний список з n елементів, дані вводяться з консолі. Повертає голову списку.
 *
 * void printForward(Node* head):
 *   Виводить елементи списку від голови до хвоста.
 *
 * void printBackward(Node* head):
 *   Виводить елементи списку від хвоста до голови.
 *
 * Node* delete2Node(Node* head, Node* node):
 *   Видаляє заданий вузол зі списку. Приймає голову списку та вузол для видалення. Повертає нову голову.
 *
 * Node* insert2Before(Node* head, Node* node, int value):
 *   Додає новий вузол зі значенням value перед заданим вузлом. Приймає голову, вузол, значення. Повертає нову голову.
 *
 * Node* insert2After(Node* head, Node* node, int value):
 *   Додає новий вузол зі значенням value після заданого вузла. Приймає голову, вузол, значення. Повертає голову.
 *
 * Node* findNode(Node* head, int value):
 *   Шукає вузол за значенням value. Приймає голову списку та значення. Повертає знайдений вузол або nullptr.
 *
 * void freeList(Node* head):
 *   Звільняє пам’ять, видаляючи всі вузли списку. Приймає голову списку.
 *
 * bool isSymmetric(Node* head):
 *   Перевіряє, чи є список симетричним (паліндромом). Приймає голову списку. Повертає true або false.
 */
#include <iostream>
using namespace std;

// Структура вузла двозв’язного списку
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Функція створення двозв’язного списку
Node* createList(int n) {
    if (n <= 0) return nullptr;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        cout << "Введіть елемент " << i + 1 << ": ";
        cin >> newNode->data;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail != nullptr)
            tail->next = newNode;
        else
            head = newNode;

        tail = newNode;
    }
    return head;
}

// Вивід списку вперед
void printForward(Node* head) {
    cout << "Список вперед: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Вивід списку назад
void printBackward(Node* head) {
    if (!head) return;

    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    cout << "Список назад: ";
    while (tail != nullptr) {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}

// Видалення заданого елемента
Node* delete2Node(Node* head, Node* node) {
    if (!head || !node) return head;

    if (node->prev) node->prev->next = node->next;
    else head = node->next; // якщо видаляємо голову

    if (node->next) node->next->prev = node->prev;

    delete node;
    return head;
}

// Додавання перед заданим елементом
Node* insert2Before(Node* head, Node* node, int value) {
    if (!node) return head;

    Node* newNode = new Node{value, node, node->prev};

    if (node->prev) node->prev->next = newNode;
    else head = newNode; // якщо вставка перед головою

    node->prev = newNode;

    return head;
}

// Додавання після заданого елемента
Node* insert2After(Node* head, Node* node, int value) {
    if (!node) return head;

    Node* newNode = new Node{value, node->next, node};

    if (node->next) node->next->prev = newNode;
    node->next = newNode;

    return head;
}

// Пошук вузла за значенням (допоміжна функція)
Node* findNode(Node* head, int value) {
    Node* temp = head;
    while (temp) {
        if (temp->data == value) return temp;
        temp = temp->next;
    }
    return nullptr;
}

// Звільнення пам’яті
void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


bool isSymmetric(Node* head) {
    if (!head || !head->next) return true; // 0 або 1 елемент – симетрично

    // знайти хвіст
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    // порівнювати з обох кінців
    while (head != tail && head->prev != tail) {
        if (head->data != tail->data) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    int n;
    cout << "Введіть кількість елементів: ";
    cin >> n;

    Node* head = createList(n);

    printForward(head);
    printBackward(head);

    // Демонстрація роботи
    int val;
    cout << "\nВведіть значення для пошуку (видалення): ";
    cin >> val;
    Node* node = findNode(head, val);
    if (node) {
        head = delete2Node(head, node);
        cout << "Елемент видалено.\n";
        printForward(head);
    } else {
        cout << "Елемент не знайдено.\n";
    }

    cout << "\nВведіть значення після якого вставити новий елемент: ";
    cin >> val;
    node = findNode(head, val);
    if (node) {
        int newVal;
        cout << "Введіть нове значення: ";
        cin >> newVal;
        head = insert2After(head, node, newVal);
        printForward(head);
    } else {
        cout << "Елемент не знайдено.\n";
    }

    cout << "\nВведіть значення перед яким вставити новий елемент: ";
    cin >> val;
    node = findNode(head, val);
    if (node) {
        int newVal;
        cout << "Введіть нове значення: ";
        cin >> newVal;
        head = insert2Before(head, node, newVal);
        printForward(head);
    } else {
        cout << "Елемент не знайдено.\n";
    }

    freeList(head);
    return 0;
}
