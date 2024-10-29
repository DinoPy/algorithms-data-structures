#include <vector>

using std::vector;

template <class T>
class Queue {
    // enqueue, dequeue, peek, size

public:
    void enqueue (T item) {
        items.insert(items.begin(), item);
    }

    T dequeue () {
        if (items.size() == 0)
            return -1;
        T i = items[-1];
        items.pop_back();
        return i;
    }

    size_t size() {
        return items.size();
    }

    T peek() {
        if (items.size() == 0)
            return -1;
        return items[-1];
    }

    private:
        vector<T> items {};
};

int main (int argc, char *argv[]) {
    Queue<int> a = {};
    a.enqueue(2);
    a.dequeue();
    a.enqueue(3);
    a.peek();

    return 0;
}
