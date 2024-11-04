#include <iostream>
#include <optional>

using std::optional;

template <class T> class Node {
  public:
    T value;
    Node *next;

    Node(T v) : value(v), next(nullptr) {}
    void set_next(Node *n) { next = n; }
};

template <class T> class LinkedList {
  public:
    ~LinkedList() {
        while (head != nullptr) {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add_to_head(T n) {
        Node<T> *new_node = new Node<T>(n);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->set_next(head);
            head = new_node;
        }
    }

    optional<T> remove_from_head() {
        if (head == nullptr) {
            return std::nullopt;
        }
        T value = head->value;
        Node<T> *to_delete_head = head;
        head = head->next;
        delete to_delete_head;
        return value;
    }

    void add_to_tail(T n) {
        Node<T> *new_node = new Node<T>(n);
        if (tail)
            tail->set_next(new_node);
        else {
            head = new_node;
        }
        tail = new_node;
    }

    optional<T> remove_from_tail() {
        if (tail == nullptr)
            return std::nullopt;
        T value = tail->value;
        Node<T> *to_delete_tail = tail;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node<T> *new_tail = head;
            while (new_tail->next != to_delete_tail) {
                new_tail = new_tail->next;
            }
            tail = new_tail;
            tail->next = nullptr;
        }
        delete to_delete_tail;
        return value;
    }

    friend std::ostream &operator<<(std::ostream &os,
                                    const LinkedList<T> &list) {
        auto *current = list.head;
        while (current) {
            os << current->value << " -> ";
            current = current->next;
        }
        os << "nullptr";
        return os;
    }

  private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
};

int main(int argc, char *argv[]) {
    LinkedList<int> linked_list;
    linked_list.add_to_head(1);
    linked_list.add_to_head(2);
    linked_list.add_to_tail(3);
    linked_list.add_to_tail(4);
    linked_list.add_to_tail(5);
    linked_list.add_to_tail(6);
    std::cout << "removed head: " << linked_list.remove_from_head().value_or(-1)
              << std::endl;
    std::cout << "removed head: " << linked_list.remove_from_tail().value_or(-1)
              << std::endl;

    std::cout << "Linked List: " << linked_list << std::endl;

    return 0;
}
