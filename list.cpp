#include <iostream>

using namespace std;

class Node{
    public:

    int value{};
    Node* next{nullptr};

    Node(int value_to_insert) : value(value_to_insert) {}
};


class List{
    public:

    bool is_empty(){
        return head == nullptr;
    };

    void add_end(int data){
        
        Node* new_node = new Node(data);

        if(is_empty())
            head = new_node;
        else{
            Node* current{ head };
            while(current->next != nullptr) 
                current = current->next;

            current->next = new_node;
        }
    }

    void add_beginning(int data){

        Node* new_node = new Node(data);

        if(is_empty())
            head = new_node;
        else{
            new_node->next = head;
            head = new_node;
        }
    }

    void remove(int data) {
        if (is_empty()) {
            std::cout << "Linked List is empty." << std::endl;
            return;
        }

        if (head->value == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->value == data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }

        std::cout << data << " not found in the Linked List." << std::endl;
    }

    void print() {
        if (is_empty()) 
            std::cout << "This list is empty." << std::endl;
        else {
            Node* current = head;
            while (current != nullptr) {
                std::cout << current->value << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }

    private:
    Node* head{nullptr};
};
int main(){

    List list{};

    for(int i{0};i<5;++i)
        list.add_end(i);

    list.print();

}