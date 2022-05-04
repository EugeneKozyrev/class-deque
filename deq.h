#define SIZE (8)
class Deque{
    private:
        struct Node {
            char item[SIZE];
            Node *next;
            Node *prev;
 
            Node( char* i, Node *n = NULL, Node *l = NULL) {
                for (int idx = 0; idx < SIZE; idx++){
                    item[idx] = i[idx];
                }
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
        char* Head() const;
        char* Tail() const;
        void push_front(char* item);
        void push_back(char* item);
        char* pop_front();
        char* pop_back();
        void printCount();
        void printFront();
        void printBack();
        void Clear();
};
