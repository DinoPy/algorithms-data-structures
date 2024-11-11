
class BSTNode<T> {
    value: T | null;
    left: null | BSTNode<T>;
    right: null | BSTNode<T>;

    constructor(val: T | null = null) {
        this.value = val;
        this.left = null;
        this.right = null;
    }

    insert(val: T) {
        if (this.value == null) {
            this.value = val;
            return
        }

        if (this.value == val) return;

        if (this.value > val) {
            if (this.left)
                this.left.insert(val);
            else
                this.left = new BSTNode(val);
        } else {
            if (this.right)
                this.right.insert(val);
            else
                this.right = new BSTNode(val);
        }
    }

    getMin(): T | null {
        let currentNode: BSTNode<T> = this;
        while (currentNode.left) {
            currentNode = currentNode.left;
        }
        return currentNode.value
    }

    getMax(): T | null {
        let currentNode: BSTNode<T> = this;
        while (currentNode.right) {
            currentNode = currentNode.right;
        }
        return currentNode.value;
    }

    delete(val: T): BSTNode<T> | null {
        if (this.value! > val) {
            if (this.left) this.left = this.left.delete(val);
            return this
        } else if (this.value! < val) {
            if (this.right) this.right = this.right.delete(val);
            return this
        } else {
            if (!this.left) return this.right;
            if (!this.right) return this.left;

            let min_largest_value = this.right;
            while (min_largest_value.left) {
                min_largest_value = min_largest_value.left;
            }
            this.value = min_largest_value.value
            this.right = this.right.delete(min_largest_value.value!)
            return this
        }
    }

    preorder (accumulator: T[]) {
        accumulator.push(this.value!);
        if (this.left)
            this.left.preorder(accumulator);
        if (this.right)
            this.right.preorder(accumulator);
        return accumulator;
    }

    postorder (accumulator: T[]) {
        if (this.left)
            this.left.postorder(accumulator);
        if (this.right)
            this.right.postorder(accumulator);
        accumulator.push(this.value!);
        return accumulator;
    }

    inorder(accumulator: T[]) {
        if (this.left)
            this.left.inorder(accumulator);
        if (this.value)
            accumulator.push(this.value);
        if (this.right)
            this.right.inorder(accumulator);
        return accumulator;
    }

    exists (val: T) {
        if (this.value == val)
            return true;
        if (val < this.value! && this.left)
            this.left.exists(val);
        if (val > this.value! && this.right)
            this.right.exists(val);
        return false;
    }
}

const main = () => {
    const nums = [12, 6, 18, 19, 21, 11, 3, 5, 4, 24, 18]
    const bst = new BSTNode<number>()
    for (let num of nums) {
        bst.insert(num)
    }
    console.log("preorder:")
    console.log(bst.preorder([]))
    console.log("#")

    console.log("postorder:")
    console.log(bst.postorder([]))
    console.log("#")

    console.log("inorder:")
    console.log(bst.inorder([]))
    console.log("#")

    const del = [12, 2, 6, 20]
    console.log("deleting " + nums)
    for (let num of del)
        bst.delete(num)
    console.log("#")

    console.log("4 exists:")
    console.log(bst.exists(4))
    console.log("2 exists:")
    console.log(bst.exists(2))
    console.log("12 exists:")
    console.log(bst.exists(12))
    console.log("18 exists:")
    console.log(bst.exists(18))
    console.log(bst.inorder([]))

}

main();
