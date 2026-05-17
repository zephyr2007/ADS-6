
template<typename T>
class TPQueue {
 public:
    TPQueue() :head(nullptr) {}
    ~TPQueue() {
        while (head) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    T pop() {
        if (head) {
            T temp = head->data;
            Node* next = head->next;
            delete head;
            head = next;
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
                head->next = nullptr;
                head->next = temp;
            } else {
                while ((temp->next != nullptr)
                    && data.prior <= temp->next->data.prior)
                    temp = temp->next;
                Node* newNode = new Node;
                newNode->data = data;
                newNode->next = nullptr;
                newNode->next = temp->next;
                temp->next = newNode;
            }
        } else {
            head = new Node;
            head->data = data;
            head->next = nullptr;
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
