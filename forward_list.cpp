#include <iostream>
#include <functional>
#include <string>


template<typename T>
class ForwardList {
    struct Node {
        T data;
        Node* next;
        Node() : data(T()), next(nullptr) {} // Default constructor, nos ayuda a inicializar los valores de los nodos 
        Node(T data, Node* next = nullptr) : data(data), next(next) {} // Node constructor, ths helps us avoid using the -> operator
    };

    Node* head;

public:
    ForwardList() : head(nullptr) {}

    ~ForwardList() {
        while(!empty()) {
            pop_front();
        }
    }

    void push_front(T input) {
        Node* newNode = new Node(input, head);
        /* otra manera de hacerlo
        Node* newNode = new Node;
        newNode->data = input;
        newNode->next = head;
        */
        head = newNode;
    }

    void pop_front() {
        if(!empty()) {
            Node* oldHead = head;
            head = head->next;
            delete oldHead;
        }
    }

    T front() {
        if(!empty()) {
            return head->data;
        }
        throw std::runtime_error("List is empty");
    }

    T back() {
        if(!empty()) {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            return temp->data;
        }
        throw std::runtime_error("List is empty");
    }

    void push_back(T input) {
    Node* newNode = new Node;
    newNode->data = input;

    Node* temp = head;
    while (temp && temp->next != nullptr) {
        temp = temp->next;
    }
    if (temp) {
        temp->next = newNode;
    } else {
        head = newNode;
    }
    newNode->next = nullptr;
}

void pop_back() {
    if(!empty()) {
        Node* temp = head;
        while (temp && temp->next && temp->next->next != nullptr) {
            temp = temp->next;
        }
        if (temp && temp->next) {
            delete temp->next;
            temp->next = nullptr;
        } else {
            delete head;
            head = nullptr;
        }
    }
}

T operator[](int index) {
    if (index < 0) {
        throw std::out_of_range("Index cannot be negative");
    }

    Node* temp = head;
    int count = 0;

    while (temp != nullptr) {
        if (count == index) {
            return temp->data;
        }
        count++;
        temp = temp->next;
    }

    throw std::out_of_range("Index is out of range");
}

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void clear() {
        while(!empty()) {
            pop_front();
        }
    }

    void reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev; 
        prev = current; 
        current = next; 
    }
    head = prev;
}

// Merge sort

void sort() {
    if (empty()) {
        throw std::runtime_error("Error: List is empty");
    }

    std::function<Node*(Node*)> mergeSort;
    std::function<Node*(Node*, Node*)> sortedMerge;

    sortedMerge = [&](Node* a, Node* b) -> Node* {
        Node* result = nullptr;

        if (a == nullptr)
            return b;
        else if (b == nullptr)
            return a;

        if (a->data <= b->data) {
            result = a;
            result->next = sortedMerge(a->next, b);
        } else {
            result = b;
            result->next = sortedMerge(a, b->next);
        }
        return result;
    };

    mergeSort = [&](Node* h) -> Node* {
        if (h == nullptr || h->next == nullptr)
            return h;

        Node* slow = h;
        Node* fast = h->next;

        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        Node* middle = slow;
        Node* nextOfMiddle = slow->next;

        middle->next = nullptr;

        Node* left = mergeSort(h);
        Node* right = mergeSort(nextOfMiddle);

        Node* sortedList = sortedMerge(left, right);
        return sortedList;
    };

    head = mergeSort(head);
}

    bool empty() {
        return head == nullptr;
    }

    // for making things easier crearemos un print para visualizar la lista
    void print() {
        if (empty()) {
            throw std::runtime_error("Error: List is empty");
        }

        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};
