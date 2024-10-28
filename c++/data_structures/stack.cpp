#include <vector>

using std::vector;

template <class T>
class Stack {
    // push, pop, peek, size
    void push(T item) {
        items.push_back(item);
    }

    T pop () {
        return items.pop_back();
    }

    size_t size () {
        return items.size();
    }

    T peek () {
        return items[-1];
    }

    private:
        vector<T> items;
};

int main (int argc, char *argv[]) {
    Stack<int> s;
    return 0;
}
