#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(T d, Node<T>* n = nullptr) {
        data = d;
        next = n;
    }
};

template <typename T>
class List{
private:
    Node<T>* head;
public:
    List(){};

    T front(){
        Node<T>* temp = head;
        if (temp == NULL){
            throw out_of_range("No existe un primer elemento porque la lista está vacia.");
        }
        else{
            return temp->data;
        }
    };

    void push_front(T value){
      Node<T>* nodo = new Node<T>(value,head);
      head = nodo;
    }

    void push_back(T value){
        Node<T>* temp = head;
        Node<T>* nodo = new Node<T>(value);
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nodo;
    };

    void display(){
        Node<T>* temp = head;
        while(temp != NULL){
            cout<< temp->data <<" ";
            temp = temp->next;
        }
    }

    void pop_front(){
      Node<T>* temp = head;
      head = head->next;
      delete temp;
    };

    void pop_back(){
        if(head->next == NULL){
            delete head;
        }
        else {
            Node<T>* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    };
    
};

int main() {

    List<int> L1;

    //L1.display();
    cout<< L1.front()<<endl;



    return 0;
}
/*
int main() {
    List<int> L1;
    // ... otras operaciones con L1 ...

    try {
        cout << L1.front() << endl;
    } catch (const std::out_of_range& e) {
        cout << "Error: " << e.what() << endl;
        // Puedes poner aquí código adicional para manejar el error
    }

    // ... resto de tu código ...
}
*/

