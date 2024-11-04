class Node<T> {
    value: T;
    next: Node<T> | null;

    constructor(value: T) {
        this.value = value
        this.next = null
    }

    set_next(node: Node<T>) {
        this.next = node
    }

    toString() {
        return this.value
    }
}

class LinkedList<T> {
    #head: Node<T> | null
    #tail: Node<T> | null

    constructor(node: Node<T> | null = null) {
        this.#head = node
        this.#tail = node
    }

    addToHead(node: Node<T>) {
        node.next = this.#head;
        this.#head = node
        if (!this.#tail) this.#tail = node

    }

    addToTail(node: Node<T>) {
        if (!this.#head) {
            this.#head = node
            this.#tail = node
            return
        }

        this.#tail.next = node
        this.#tail = node
    }

    removeFromHead() {
        const current_head = this.#head
        this.#head = this.#head.next;
        return current_head;
    }

    removeFromTail() {
        const tail = this.#tail;
        let pre_tail = this.#head;

        while (pre_tail.next !== tail) {
            pre_tail = pre_tail.next
        }

        this.#tail = pre_tail
        this.#tail.next = null
        return tail
    }

    *[Symbol.iterator]() {
        let current = this.#head;
        while (current) {
            yield current.value;
            current = current.next
        }
    }

    toString() {
        let nodes = []
        for (let node of this) {
            nodes.push(node);
        }

        return nodes.join(" <- ");
    }
}




const main = () => {
    const linkedList = new LinkedList<number>()
    linkedList.addToHead(new Node(1))
    linkedList.addToHead(new Node(2))
    linkedList.addToTail(new Node(3))
    linkedList.addToTail(new Node(4))
    linkedList.addToTail(new Node(5))
    linkedList.addToTail(new Node(6))
    console.log(`removed head: ${linkedList.removeFromHead()}`)
    console.log(`removed tail: ${linkedList.removeFromTail()}`)
    console.log(linkedList.toString())
}

main()
