#include <iostream>

template <typename T>
class BST {
    private:
        // Node structure, private to encapsulate the implementation details
        struct Node {
            T data;
            Node* left;
            Node* right;
            Node(T value) : data(value), left(nullptr), right(nullptr) {}
        };
        // Root of the BST and size of the tree
        Node* root;
        size_t size;
        // Private methods for insertion, removal, clearing the tree
        Node* insert(Node* p, const T& key);
        Node* remove(Node* p, const T& key);
        void clear(Node* p);
        bool search(Node* p, const T& key);
        size_t get_height(Node *p);
        void print_in_order(Node* p);

    public:
        // default constructor, sets root to nullptr and size to 0
        BST() : root(nullptr), size(0) {}
        // destructor to clear the tree
        ~BST() { clear(root); }
        // Public methods for inserting, removing, searching
        void insert(const T& key);
        void remove(const T& key);
        void clear();
        bool search(const T& key);
        // Public methods that return the size and check if the tree is empty
        size_t get_size() const { return size; }
        size_t get_height();
        bool is_empty() const { return size == 0; }
        // Public method to print the tree in order
        void print_in_order();
};

// Public method for searching a key in the BST
template <typename T>
bool BST<T>::search(const T& key) {
    return search(root, key);
}

// Private method for searching a key in the BST recursively
template <typename T>
bool BST<T>::search(Node* p, const T& key) {
    if ( !p ) {
        return false;
    }
    if (key < p->data) {
        return search(p->left, key);
    } else if (key > p->data) {
        return search(p->right, key);
    } else {
        return true; // Key found
    }
}

// Public method to clear the BST
template <typename T>
void BST<T>::clear() {
    clear(root);
    root = nullptr;
    size = 0;
}

// Private method to clear the BST recursively
template <typename T>
void BST<T>::clear(Node *p) {
    if (p) {
        clear(p->left);
        clear(p->right);
        delete p;
    }
}

// Public method to insert a key into the BST
template <typename T>
void BST<T>::insert(const T& key) {
    root = insert(root, key);
}

// Private method to insert a key into the BST recursively
template <typename T>
typename BST<T>::Node* BST<T>::insert(Node* p, const T& key) {
    if ( !p ) {
        size ++;
        return new Node(key);
    }
    if (key < p->data) {
        p->left = insert(p->left, key);
    } else if (key > p->data) {
        p->right = insert(p->right, key);
    }
    return p;
}

// Public method to print the BST in order
template <typename T>
void BST<T>::print_in_order() {
    print_in_order(root);
    std::cout << std::endl;
}

// Private method to print the BST in order
template <typename T>
void BST<T>::print_in_order(Node* p) {
    if ( p ) {
        print_in_order(p->left);
        std::cout << p->data << " ";
        print_in_order(p->right);
    }
}

// Public method to remove a key from the BST
template <typename T>
void BST<T>::remove(const T& key) {
    root = remove(root, key);
    size --;
}

// Private method to remove a key from the BST recursively
template <typename T>
typename BST<T>::Node* BST<T>::remove(Node* p, const T& key) {
    Node* temp;
    if ( !p ) {
        return nullptr;
    }
    if (key < p->data) {
        p->left = remove(p->left, key);
    } else if (key > p->data) {
        p->right = remove(p->right, key);
    } else {
        // case 1 or 2: no child or one child
        if ( !p->left ) {
            temp = p->right;
            delete p;
            return temp;
        } else if ( !p->right ) {
            temp = p->left;
            delete p;
            return temp;
        }
        // case 3: find successor
        temp = p->right;
        while (temp->left) {
            temp = temp->left;
        }
        p->data = temp->data; // replace data with successor's data
        p->right = remove(p->right, temp->data); // remove the successor
    }
    return p; // return the modified node
}

// Public method to get the height of the BST
template <typename T>
size_t BST<T>::get_height() {
    return get_height(root);
}
// Private method to get the height of the BST recursively
template <typename T>
size_t BST<T>::get_height(Node* p) {
    // TODO:
    // replace the line below with a recursive implementation
    // that returns the height of the tree rooted at p
    return 0;
}