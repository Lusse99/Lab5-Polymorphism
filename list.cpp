#include <iostream>

template <class T>
struct element { //element
    T data;
    element<T> *next;
    element<T> *prev;

    element(T data) : data(data), next(nullptr), prev(nullptr){}
};

template <class T>
class list {
private:
    element<T> *head;
    element<T> *tail;
    int count;
public:
    list() : head(nullptr), tail(nullptr), count(0){}
    ~list();

    element<T>* begin(){ return head; }
    element<T>* end(){ return nullptr; }

    T& front(){ return head->data; }
    T& back(){ return tail->data; }

    bool empty(){ return count == 0; }
    int size(){ return count; }

    void clear();
    bool insert(T data, int position);
    void erase(int position);

    void push_front(T data);
    void push_back(T data);
    void pop_front();
    void pop_back();
};

template <class T>
list<T>::~list() {
    clear();
}

template <class T>
void list<T>::clear(){
    while(!empty()){
        pop_front();
    }
}

template <typename T>
bool list<T>::insert(T data, int position){
    if (position < 0 || position > count){
        return false;
    }

    element<T>* newnode = new element<T>(data);

    if (empty()){
        head = tail = newnode;
        ++count;
        return true;
    }

    if (position == 0){//inserting at the front
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        ++count;
        return true;
    }

    if (position == count){//inserting at the back
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
        ++count;
        return true;
    }

    //inserting somewhere else in the list
    element<T>* index = head;
    for (int i = 0; i < position; i++){ //moves to next node until reached position
        index = index->next;
    }

    //inserting new node before node att index
    newnode->next = index;
    newnode->prev = index->prev;
    index->prev->next = newnode;
    index->prev = newnode;
    ++count;
    
    return true;
}


template <class T>
void list<T>::erase(int position){
    element<T>* index = head;
    for (int i = 0; i < position; i++){ //find node
        index = index->next;
    }

    if (index->prev){
        index->prev->next = index->next;
    } else {
        head = index->next;
    }

    if (index->next){
        index->next->prev = index->prev;
    } else {
        tail = index->prev;
    }

    delete index;
    count--;
}

template <class T>
void list<T>::push_front(T data){
    element<T>* newnode = new element<T>(data);
    if (empty()){
        head = tail = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }

    count++;
}

template <class T>
void list<T>::push_back(T data){
    element<T>* newnode = new element<T>(data);
    if (empty()){
        head = tail = newnode;
    } else {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }

    count++;
}

template <class T>
void list<T>::pop_front(){
    element<T>* temp = head;
    if (head->next){
        head = head->next;
        head->prev = nullptr;
    } else {
        head = tail = nullptr;
    }

    delete temp;
    count--;
}


template <class T>
void list<T>::pop_back(){
    element<T>* temp = tail;
    if (tail->prev){
        tail = tail->prev;
        tail->next = nullptr;
    } else {
        head = tail = nullptr;
    }

    delete temp;
    count--;
}


template <class T>
void printlist(list<T> &list){
    for (element<T>* temp = list.begin(); temp != list.end(); temp = temp->next){
        std::cout << temp->data << " ";
    }
    std::cout << std::endl;
}


int main(){
    list<int> list;

    list.push_back(5);
    list.push_back(7);
    list.push_back(9);
    list.push_front(3);

    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " << list.back() << std::endl;

    printlist(list);

    list.pop_front();
    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " << list.back() << std::endl;

    printlist(list);

    list.insert(2, 0);
    std::cout << "Inserted 2 at front: " << list.front() << std::endl;

    printlist(list);

    list.erase(0);
    std::cout << "Erased front: " << list.front() << std::endl;

    printlist(list);

    list.insert(10, 0);
    std::cout << "After inserting 10 at front: " << std::endl;
    printlist(list);

    list.insert(20, list.size());
    std::cout << "Inserted 20 at end: " << list.back() << std::endl;

    printlist(list);

    list.clear();
    std::cout << "After clearing the list: " << std::endl;
    printlist(list);

    return 0;
}

