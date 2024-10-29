class Queue():
    def __init__(self):
        self.__items = []

    def enqueue(self, item):
        self.__items.insert(0, item)

    def dequeue(self):
        if len(self.__items) > 0:
            return self.__items.pop()
        return None

    def size(self):
        return len(self.__items)

    def peek(self):
        if len(self.__items) > 0:
            return self.__items[-1]
        return None


item = Queue()
item.enqueue(2)
item.enqueue(2)
print(item.peek())
print(item.dequeue())
print(item.size())
