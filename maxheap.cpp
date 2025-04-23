#include <iostream>
using namespace std;
#define MAXSIZE 100
void swap(int *x, int *y) {
    *x += *y;
    *y = *x - *y;
    *x = *x - *y;
}
class MaxHeap {
    int last;
    int heap[MAXSIZE];
    public:
    MaxHeap() {
        last = -1;
    }
    void heapify(int i) {
        int largest = i;
        int left = (2 * i + 1);
        int right = (2 * i + 2);
        if ((left <= last) && (heap[left] >= heap[largest])) {
            largest = left;
        }
        if ((right <= last) && (heap[right] >= heap[largest])) {
            largest = right;
        }
        if (largest != i) {
            // Swap child with parent and heapify for child
            swap(&heap[i], &heap[largest]);
            heapify(largest);
        }
    }
    void insert(int value) {
        if (last == (MAXSIZE - 1)) {
            cout << "Heap overflow" << endl;
            return;
        }
        last += 1;
        int i = last;
        while ((i > 0) && (value > heap[(i - 1) / 2])) {
            heap[i] = heap[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        heap[i] = value;
        cout << "Inserted element: " << value << endl;
    }
    int remove(int elem = -1) {
        if (last == -1) {
            cout << "Heap underflow" << endl;
            return -1;
        }
        int result;
        if (elem == -1) {
            // Delete root node (max value)
            result = heap[0];
            swap(&heap[0], &heap[last]);
            last -= 1;
            heapify(0);
        } else {
            // Delete node with value elem
            int i;
            for (i = 0; i <= last; i++) {
                if (heap[i] == elem) {
                    break;
                }
            }
            if (i == (last + 1)) {
                return -1;
            }
            result = heap[i];
            swap(&heap[i], &heap[last]);
            last -= 1;
            heapify(i);
        }
        return result;
    }
    void display() {
        if (last == -1) {
            cout << "Empty" << endl;
            return;
        }
        int i;
        for (i = 0; i <= last; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    MaxHeap heap;
    int choice, x;
    cout << "1. Insert element in heap\n2. Remove maximum element from heap\n3. Remove any element from heap\n4. Display heap\n5. Exit" << endl;
    do {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1: {
                cout << "Enter value of element to insert: ";
                cin >> x;
                heap.insert(x);
                break;
            }
            case 2: {
                x = heap.remove(-1);
                cout << "Maximum element removed is: " << x << endl;
                break;
            }      
            case 3: {
                cout << "Enter value of element to remove: ";
                cin >> x;
                if (x == -1) {
                    cout << "Element to remove cannot be -1" << endl;
                    continue;
                }
                x = heap.remove(x);
                if (x == -1) {
                    cout << "Element not found in the heap" << endl;
                    continue;
                }
                cout << "Element removed is: " << x << endl;
                break;
            }
            case 4: {
                cout << "Heap: ";
                heap.display();
                break;
            }
            case 5: {
                cout << "Exiting the program" << endl;
                break;
            }
        default: {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    } while (choice != 5);
    return 0;
}