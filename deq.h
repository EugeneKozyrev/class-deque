class Deque{
    private:
        struct Node {
            int item;
            Node *next;
            Node *prev;
 
            Node( int i, Node *n = NULL, Node *l = NULL) {
                item = i;
                next = n;
                prev = l;
            }
        };
 
        int size;
        Node *first;
        Node *last;
 
    public:
        Deque();
        ~Deque();
        int Head() const;
        int Tail() const;
        void push_front(int item);
        void push_back(int item);
        int pop_front();
        int pop_back();
        void printCount();
        void printFront();
        void printBack();
        void Clear();
};
