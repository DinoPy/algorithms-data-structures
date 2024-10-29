class Queue<T> {
    #items : T[];
    constructor() {
        this.#items = [];
    }

    enqueue(item: T) {
        this.#items.unshift(item);
    }

    dequeue(): T | null {
        if (this.#items.length > 0)
            return this.#items.pop();
        return null
    }

    peek(): T | null {
        if (this.#items.length > 0)
            return this.#items[this.#items.length-1]
        return null
    }

    size(): number {
        return this.#items.length;
    }
}

const item = new Queue();
item.enqueue(2);
item.enqueue(2);
console.log(item.peek());
console.log(item.dequeue());
console.log(item.size());
