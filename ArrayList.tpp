template <typename T>
ArrayList<T>::ArrayList(int i) {
    this->maxSize = i;
    this->buffer = new T[maxSize];
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayList<T>::~ArrayList() {
    clear();
}

template <typename T>
void ArrayList<T>::append(const T& elem) {
    if (!isFull()) {
        *(this->buffer + this->length++) = elem;
    } else { throw static_cast<string>("Array is full, could not append"); }
}

template <typename T>
void ArrayList<T>::clear() {
    delete[] this->buffer;
    this->buffer = new T[maxSize];
    this->length = 0;
}

template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& copyObj) {
    this->maxSize = copyObj.getMaxSize();
    clear();
    this->length = copyObj.getLength();
    for (int i = 0; i < this->length; i++) {
        *(this->buffer + i) = copyObj.getElement(i);
    }
}

template <typename T>
T ArrayList<T>::getElement(int position) const {
    if (isEmpty()) { throw static_cast<string>("List is empty"); }
    if ((position < 0) || (position >= this->length)) { throw static_cast<string>("Invalid index, could not get"); }
    if (position < this->length) {
        return *(this->buffer + position);
    } else {
        return *(this->buffer + (this->length - 1));
    }
}

template <typename T>
int ArrayList<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayList<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
void ArrayList<T>::insert(int position, const T& elem) {
    if (isFull()) { throw static_cast<string>("Array is full, could not insert"); }
    if ((position < 0) || (position >= this->length)) { throw static_cast<string>("Invalid index, could not insert"); }
    T newVal = elem;
    T oldVal = *(this->buffer + position);
    for (int i = position; i < this->length; i++) {
        *(this->buffer + i) = newVal;
        newVal = oldVal;
        oldVal = *(this->buffer + (i + 1));
    }
    append(newVal);
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayList<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
void ArrayList<T>::remove(int position) {
    if (isEmpty()) { throw static_cast<string>("List is empty, could not remove"); }
    if ((position >= this->length) || (position < 0)) { throw static_cast<string>("Invalid index, could not remove"); }
    for (int i = position; i < this->length; i++) {
        *(this->buffer + i) = *(this->buffer + (i + 1));
    }
    --this->length;
}

template <typename T>
void ArrayList<T>::replace(int position, const T& elem) {
    if (isEmpty()) { throw static_cast<string>("List is empty, could not replace"); }
    if ((position >= this->length) || (position < 0)) { throw static_cast<string>("Invalid index, could not replace"); }
    *(this->buffer + position) = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        for (int i = 0; i < myObj.length; i++) {
            outStream << myObj.buffer[i] << ' ';
        }
        outStream << endl;
    }

    return outStream;
}
