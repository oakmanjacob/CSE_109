#ifndef linked_list
#define linked_list

class Node {
    public: 
        Node(int data);
        ~Node();
        int data;
        Node* next;
        Node* find_tail();
};

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        bool insert(int data);
		bool insert_head(int data);
		bool insert_tail(int data);
		bool insert_at_index(int index, int data);
		bool remove_head();
		bool remove_tail();
		bool remove_at_index(int index);
        int find(int data);
        int len();

    protected:
        int length;
        Node* head;
        Node* tail;
};

#endif