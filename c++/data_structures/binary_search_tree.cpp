#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;
using std::vector;

template <class T> class BSTNode {
  public:
    T value;
    unique_ptr<BSTNode<T>> left;
    unique_ptr<BSTNode<T>> right;

    BSTNode(T val) : value(val), left(nullptr), right(nullptr) {}

    void insert(T val) {
        if (!value)
            value = val;
        if (value == val)
            return;
        if (val < value) {
            if (left)
                left->insert(val);
            else
                left = make_unique<BSTNode<T>>(val);
        } else if (val > value) {
            if (right)
                right->insert(val);
            else
                right = make_unique<BSTNode<T>>(val);
        }
    }

    T get_min() {
        const BSTNode<T> *current = this;
        while (current->left) {
            current = current->left.get();
        }
        return current->value;
    }

    T get_max() {
        const BSTNode<T> *current = this;
        while (current->right) {
            current = current->right.get();
        }
        return current->value;
    }

    static unique_ptr<BSTNode<T>> del(unique_ptr<BSTNode<T>> &node, T val) {
        if (!node)
            return nullptr;
        if (val < node->value) {
            node->left = del(node->left, val);
        } else if (val > node->value) {
            node->right = del(node->right, val);
        } else {
            if (!node->left)
                return std::move(node->right);
            if (!node->right)
                return std::move(node->left);

            node->value = node->right->get_min();
            node->right = del(node->right, node->value);
        }
        return std::move(node);
    }

    vector<T> &inorder(vector<T> &accumulator) {
        if (left)
            left->inorder(accumulator);
        if (value)
            accumulator.push_back(value);
        if (right)
            right->inorder(accumulator);
        return accumulator;
    }

    vector<T> &preorder(vector<T> &accumulator) {
        if (value)
            accumulator.push_back(value);
        if (left)
            left->inorder(accumulator);
        if (right)
            right->inorder(accumulator);
        return accumulator;
    }

    vector<T> &postorder(vector<T> &accumulator) {
        if (left)
            left->inorder(accumulator);
        if (right)
            right->inorder(accumulator);
        if (value)
            accumulator.push_back(value);
        return accumulator;
    }

    bool find(T val) {
        if (value == val)
            return true;
        if (val < value && left)
            return left->find(val);
        if (val > value && right)
            return right->find(val);

        return false;
    }
};

template <class T> void print(vector<T> list) {
    for (T val : list) {
        cout << val << " ";
    }
    cout << endl;
}

template <class T>
class BST {
public:
    BST() : root(nullptr) {}

    void insert(T val) {
        if (!root)
            root = make_unique<BSTNode<T>>(val);
        else
            root->insert(val);
    }

    void remove(T val) {
        root = BSTNode<T>::del(root, val);
    }

    vector<T> inorder() const {
        vector<T> result;
        if (root)
            root->inorder(result);
        return result;
    }

    vector<T> preorder() const {
        vector<T> result;
        if (root)
            root->preorder(result);
        return result;
    }

    vector<T> postorder() const {
        vector<T> result;
        if (root)
            root->postorder(result);
        return result;
    }


    T get_min() const {
        if (!root)
            throw std::runtime_error("Tree is empty");
        return root->get_min();
    }

    T get_max() const {
        if (!root)
            throw std::runtime_error("Tree is empty");
        return root->get_max();
    }

    bool empty() const {
        return root == nullptr;
    }

    bool find(T val) const {
        if (root)
            return root->find(val);
        return false;
    }

private:
    unique_ptr<BSTNode<T>> root;
};

int main(int argc, char *argv[]) {
    vector<int> nums{12, 6, 18, 19, 21, 11, 3, 5, 4, 24, 18};
    BST<int> tree;
    for (auto num : nums) {
        tree.insert(num);
    }

    cout << "inorder:" << endl;
    print(tree.inorder());
    cout << " #### " << endl;

    tree.remove(3);
    tree.remove(22);
    tree.remove(12);

    cout << "Min: " << tree.get_min() << " -- Max: " << tree.get_max() << endl;
    cout << "inorder:" << endl;
    print(tree.inorder());
    cout << "preorder:" << endl;
    print(tree.preorder());
    cout << "postorder:" << endl;
    print(tree.postorder());
    cout << tree.find(18) << endl;
    cout << tree.find(55) << endl;

    return 0;
}
