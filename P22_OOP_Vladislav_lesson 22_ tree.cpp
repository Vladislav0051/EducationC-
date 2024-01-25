#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    int key;  // значение, по которому происходит сортировка
    int value;  // данные узла
    Node* left;  // левый потомок
    Node* right;  // правый потомок

    // Конструктор
    Node(int k, int v) : key(k), value(v), left(nullptr), right(nullptr) {}

    // Методы
    int getMax() {
        if (right == nullptr) {
            return key;
        }
        return right->getMax();
    }

    int getMin() {
        if (left == nullptr) {
            return key;
        }
        return left->getMin();
    }

    Node* find(int key_f) {
        if (key_f == key) {
            return this;
        }
        else if (key_f < key) {
            if (left != nullptr) {
                return left->find(key_f);
            }
        }
        else {
            if (right != nullptr) {
                return right->find(key_f);
            }
        }
        return nullptr;
    }

    void printTree() {
        if (left != nullptr) {
            left->printTree();
        }
        cout << key << " ";
        if (right != nullptr) {
            right->printTree();
        }
    }

    void deleteTree() {
        if (left != nullptr) {
            left->deleteTree();
        }
        if (right != nullptr) {
            right->deleteTree();
        }
        cout << key << " ";
        delete this;
    }

    Node* copyTree() {
        Node* newNode = new Node(key, value);
        if (left != nullptr) {
            newNode->left = left->copyTree();
        }
        if (right != nullptr) {
            newNode->right = right->copyTree();
        }
        return newNode;
    }

    void insert(int key_n, int value_n) {
        if (key_n < key) {
            if (left == nullptr) {
                left = new Node(key_n, value_n);
            }
            else {
                left->insert(key_n, value_n);
            }
        }
        else if (key_n > key) {
            if (right == nullptr) {
                right = new Node(key_n, value_n);
            }
            else {
                right->insert(key_n, value_n);
            }
        }
    }

    void deleteNode(int key_d) {
        Node* nodeToDelete = find(key_d);
        if (nodeToDelete != nullptr) {
            if (nodeToDelete->left == nullptr && nodeToDelete->right == nullptr) {
                // Удаляем лист
                delete nodeToDelete;
            }
            else if (nodeToDelete->left == nullptr) {
                // Удаляем узел с одним листом
                Node* temp = nodeToDelete;
                nodeToDelete = nodeToDelete->right;
                delete temp;
            }
            else if (nodeToDelete->right == nullptr) {
                // Удаляем узел с одним листом
                Node* temp = nodeToDelete;
                nodeToDelete = nodeToDelete->left;
                delete temp;
            }
            else {
                // Удаляем узел с двумя листьями
                int minKey = nodeToDelete->right->getMin();
                nodeToDelete->key = minKey;
                nodeToDelete->right->deleteNode(minKey);
            }
        }
    }
};

