class BSTNode:
    def __init__(self, val=None):
        self.value = val
        self.left = None
        self.right = None

    def insert(self, val):
        print(f"Inserting: {val}. Current node: {self.value}")
        # if the node was instantiated with a None value we will assign the new
        # value to the current node.
        if not self.value:
            self.value = val
            return

        # if the value exists then we will return - possibly return something
        # to indicate the insertion status
        if self.value == val:
            return

        # if the value to insert is less than the current value and there is a
        # left child we recursively call insert on the the left child.
        # after checking if there is a left child to call insert recursively we
            # will assign the left child a new BSTNode with the value to insert
        if val < self.value:
            if self.left:
                self.left.insert(val)
            else:
                self.left = BSTNode(val)

        # repeat the process for the right tree
        if val > self.value:
            if self.right:
                self.right.insert(val)
            else:
                self.right = BSTNode(val)

    def get_min(self):
        current_node = self
        while current_node.left is not None:
            current_node = self.left
        return current_node.value

    def get_max(self):
        current_node = self
        while current_node.right is not None:
            current_node = self.right
        return current_node.value

    def delete(self, val):
        # if the node we call delete does not exist then we return None
        # this may happen when recursively calling delete through the tree.
        if self is None:
            return self

        # if the value to delete is less than the current node's value
        # we call delete recursively on the left tree and assign the result
        # to self.left also we will return self
        if val < self.value:
            if self.left:
                self.left = self.left.delete(val)
            return self

        # repeat the process for the right branch
        if val > self.value:
            if self.right:
                self.right = self.right.delete(val)
            return self

        # if while traversing the tree one node doesn't have a left or a right
        # branch we will return the opposite branch
        if self.left is None:
            return self.right
        if self.right is None:
            return self.left

        # this case handles the situation where the current node has both a
        # left and right child
        # finding the first largest value compared to the current node will
        # help to ensure the BST properties remain valid after deletion.
        min_larger_node = self.right
        while min_larger_node.left:
            min_larger_node = min_larger_node.left
        # instead of removing the node directly we copy the value of the
        # min_larger_node into the current node, this effectively deletes
        # the current node's value by replacing it with a valid, in order one.
        self.value = min_larger_node.value
        # because the node whose value copied into the current (to delete) node
        # we need to call delete on that node
        self.right = self.right.delete(min_larger_node.value)
        return self

    def preorder(self, visited):
        # first we append to the visited list the current node's value.
        visited.append(self.value)
        # we then traverse down the left and right trees if they exist
        if self.left is not None:
            self.left.preorder(visited)
        if self.right is not None:
            self.right.preorder(visited)
        # finally we return the updated list
        return visited

    def postorder(self, visited):
        # first we traverse the trees in both directions
        if self.left is not None:
            self.left.postorder(visited)
        if self.right is not None:
            self.right.postorder(visited)
        # once the traversing is done we start appending the current node's
        # value and then return the list
        visited.append(self.value)
        return visited

    def inorder(self, visited):
        # traverse the left tree
        if self.left:
            self.left.inorder(visited)
        # append the current value after the left tree is traversed
        if self.value:
            visited.append(self.value)
        # traverse the right tree and append the value
        if self.right:
            self.right.inorder(visited)
        return visited

    def exists(self, val):
        if self.value == val:
            return True
        if val < self.value and self.left:
            self.left.exists(val)
        if val > self.value and self.right:
            self.right.exists(val)
        return False


def main():
    nums = [12, 6, 18, 19, 21, 11, 3, 5, 4, 24, 18]
    bst = BSTNode()
    for num in nums:
        bst.insert(num)
    print("preorder:")
    print(bst.preorder([]))
    print("#")

    print("postorder:")
    print(bst.postorder([]))
    print("#")

    print("inorder:")
    print(bst.inorder([]))
    print("#")

    nums = [12, 2, 6, 20]
    print("deleting " + str(nums))
    for num in nums:
        bst.delete(num)
    print("#")

    print("4 exists:")
    print(bst.exists(4))
    print("2 exists:")
    print(bst.exists(2))
    print("12 exists:")
    print(bst.exists(12))
    print("18 exists:")
    print(bst.exists(18))
    print(bst.inorder([]))


if __name__ == "__main__":
    main()
