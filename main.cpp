#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T> *next = NULL;
    Node<T> *prev = NULL;

    Node(T data){
        this->data = data;
    }
};

template <typename T>
class List{
private:
    Node<T> *head = NULL;
    Node<T> *tail = NULL;
public:
    T front(){
        if (head != NULL){
            return head->data;
        }
        else{
            return NULL;
        }
    }

    T back(){
        if (tail != NULL){
            return tail->data;
        }
        else{
            return NULL;
        }
    }

    void push_front(T t){
        Node<T> *nodo = new Node<T>(t);
        //nodo->data = t;

        if (head == NULL){
            head = nodo;
            tail = nodo;
        }
        else {
            nodo->next = head;
            head->prev = nodo;
            head = nodo;
        }

    }

    void push_back(T t){
        Node<T> *nodo = new Node<T>(t);
        //nodo->data = t;

        if (head == NULL){
            head = nodo;
            tail = nodo;
        }
        else {
            nodo->prev = tail;
            tail->next = nodo;
            tail = nodo;
        }

    }

    void pop_front(){
        if (head == NULL){
            return;
        }
        else if (head->next == NULL){
            delete head;
            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;
            delete head->prev;
            head->prev = NULL;
        }
    }

    void pop_back(){
        if (head == NULL){
            return;
        }
        else if (head->next == NULL){
            delete head;
            head = NULL;
            tail = NULL;
        }
        else {
            tail = tail->prev;
            delete tail->next;
            tail->next = NULL;
        }
    }

    void insert(T t, int pos){
        Node<T>* nodo = new Node<T>(t);
        if (head == NULL) {
            cout<<"Lista vacia, insertando en primera posición..."<<endl;
            head = nodo;
            tail = nodo;
        }else{
            Node<T>* temp = head;
            for(int i=0; i< pos-1; i++){
                temp = temp->next;
            }
            nodo->next = temp->next;
            nodo->prev = temp;
            temp->next = nodo;
            nodo->next->prev = nodo;
        }

    }

    void remove(int pos){
        if (head == NULL) {
            cout<<"No hay nada que eliminar"<<endl;
        }else{
            Node<T>* temp = head;
            for(int i=0; i< pos-1; i++){
                temp = temp->next;
            }
            Node<T>* removed = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            delete removed;

        }
    }

    T operator[](int pos){

    }

    bool empty(){
        return head == NULL ? true : false;
    }

    int size(){
        if (head == NULL){
            return 0;
        }

        if (head == tail){
            return 1;
        }

        int count = 1;
        Node<T> *temp = head;

        while (temp != tail){
            temp = temp->next;
            count++;
        }

        return count;
    }

    void clear(){
        Node<T> *temp = head;
    }

    void reverse(){

    }

    void print(){
        if (head == NULL){
            return;
        }

        Node<T> *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != NULL);
        cout << endl;
    }
};

int main(){
    List<int> lista;
    lista.push_front(3);
    lista.push_back(5);
    lista.push_back(8);
    lista.push_front(1);
    lista.print();
    lista.insert(7,2);
    lista.print();
    lista.remove(2);
    lista.print();

    return 0;
}