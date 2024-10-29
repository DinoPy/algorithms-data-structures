class Stack<T> {
    #items: T[]
    constructor() {
        this.#items = [];
    }

    //push, pop, peek, size
    push(item: T) {
        this.#items.push(item);
    }

    pop() {
        return this.#items.pop();
    }

    size() {
        return this.#items.length;
    }

    peek() {
        return this.#items[this.#items.length-1]
    }
}

const t_stack = new Stack();
