template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    // TODO
    buffer = new T[i];
    maxSize = i;
    this->length = 0;
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    // TODO
    this->length = 0;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    // TODO
    buffer = new T[copyObj.getMaxSize()];
    maxSize = copyObj.getMaxSize();
    this->length = copyObj.getLength();
    for (int i = 0; i < maxSize; i++)
        buffer[i] = copyObj.buffer[i];
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    // TODO
    if (this->length == 0) throw string("Empty Stack");
    return buffer[this->length - 1];
}

template <typename T>
void ArrayStack<T>::pop() {
    // TODO
    if (this->length == 0) throw string("Can't pop. The stack is empty");
    this->length--;
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    // TODO
    if (this->length + 1 > maxSize) throw string("Stack Overflow");
    buffer[this->length] = elem;
    this->length++;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TODO

    if (dir == Stack<T>::Direction::LEFT)
    {
        T top = buffer[this->length - 1];
        for (int i = this->length - 1; i > 0; i--)
            buffer[i] = buffer[i - 1];

        buffer[0] = top;
    }
    else
    {
        T bottom = buffer[0];
        for (int i = 0; i < this->length - 1; i++)
            buffer[i] = buffer[i + 1];

        buffer[this->length - 1] = bottom;
    }
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}

