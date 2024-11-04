# linked list will have a head, and a possibly a tail
# without at tail adding to tail will take O(n)
# add_to_head
# add_to_tail


class Node():
    def __init__(self, val):
        self.value = val
        self.next = None

    def set_next(self, node):
        self.next = node

    def __repr__(self):
        return str(self.value)


class LinkedList():
    def __init__(self, node=None):
        self.head = node
        self.tail = node

    def add_to_head(self, node):
        if self.head is None:
            self.tail = node
        node.next = self.head
        self.head = node

    def add_to_tail(self, node):
        if self.head is None:
            self.head = node
            self.tail = node
            return
        self.tail.next = node
        self.tail = node

    def remove_from_head(self):
        current_head = self.head
        self.head = self.head.next
        return current_head

    def remove_from_tail(self):
        current_tail = self.tail
        pre_tail = self.head
        while pre_tail.next is not current_tail:
            pre_tail = pre_tail.next
        self.tail = pre_tail
        self.tail.next = None
        return current_tail

    def __iter__(self):
        node = self.head
        while node is not None:
            yield node
            node = node.next

    def __repr__(self):
        nodes = []
        for node in self:
            nodes.append(str(node.value))

        return " <- ".join(nodes)


if __name__ == "__main__":
    linked_list = LinkedList()
    linked_list.add_to_head(Node(1))
    print(linked_list)
    linked_list.add_to_head(Node(2))
    print(linked_list)
    linked_list.add_to_tail(Node(3))
    linked_list.add_to_tail(Node(4))
    linked_list.add_to_tail(Node(5))
    linked_list.add_to_tail(Node(6))
    print(linked_list)
    print(f"removed head: {linked_list.remove_from_head()}")
    print(f"removed tail: {linked_list.remove_from_tail()}")
    print(linked_list)
