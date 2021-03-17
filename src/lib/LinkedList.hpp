namespace Algorithms {
    class Node {
       public:
        int value;
        Node *next;

        Node(int valueNode) : value(valueNode), next(nullptr){};
    };

    class LinkedList {
       public:
        Node *head;
        Node *tail;

        LinkedList() : head(nullptr), tail(nullptr){};

        void add_in_tail(Node *item);
        
        Node *find(int val);

        bool remove(int val);

        void remove_all(int val);

        void clear();

        int size();

        void insert_after(Node *nodeAfter, Node *nodeToInsert);
    };
}  // namespace Algorithms