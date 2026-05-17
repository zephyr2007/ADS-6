
template<typename T>
class TPQueue {
 public:
    TPQueue() :head(nullptr) {}
    ~TPQueue() {
        while (head) {
            Node* Next = head->Next;
            delete head;
            head = Next;
        }
    }

    T pop() {
        if (head) {
            T temp = head->data;
            Node* Next = head->Next;
            delete head;
            head = Next;
            return temp;
        } else {
            return T();
        }
    }

    void push(T data) {
        if (head) {
            Node* temp = head;
            if (head->data.prior < data.prior) {
                head = new Node;
                head->data = data;
                head->Next = nullptr;
                head->Next = temp;
            } else {
                while ((temp->Next != nullptr)
                    && data.prior <= temp->Next->data.prior)
                    temp = temp->Next;
                Node* newNode = new Node;
                newNode->data = data;
                newNode->Next = nullptr;
                newNode->Next = temp->Next;
                temp->Next = newNode;
            }
        } else {
            head = new Node;
            head->data = data;
            head->Next = nullptr;
        }
    }

 private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
};
struct SYM {
    char ch;
    int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
