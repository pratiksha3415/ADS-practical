#include <iostream>
using namespace std;
#define MAXSIZE 100

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap {
    int last;
    int heap[MAXSIZE];
public:
    MinHeap() {
        last = -1;
    }

    void heapify(int i) {
        int smallest = i;
        int left = (2 * i + 1);
        int right = (2 * i + 2);
        if (left <= last && heap[left] <= heap[smallest]) {
            smallest = left;
        }
        if (right <= last && heap[right] <= heap[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            heapify(smallest);
        }
    }

    void insert(int value) {
        if (last == MAXSIZE - 1) {
            cout << "Heap overflow" << endl;
            return;
        }
        last += 1;
        int i = last;
        while (i > 0 && value < heap[(i - 1) / 2]) {
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
            // Remove root (min value)
            result = heap[0];
            swap(&heap[0], &heap[last]);
            last--;
            heapify(0);
        } else {
            // Remove a specific element
            int i;
            for (i = 0; i <= last; i++) {
                if (heap[i] == elem)
                    break;
            }
            if (i == last + 1) {
                return -1; // not found
            }
            result = heap[i];
            swap(&heap[i], &heap[last]);
            last--;
            heapify(i);
        }
        return result;
    }

    void display() {
        if (last == -1) {
            cout << "Heap is empty" << endl;
            return;
        }
        for (int i = 0; i <= last; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap heap;
    int choice, x;

    cout << "1. Insert element in heap\n";
    cout << "2. Remove minimum element from heap\n";
    cout << "3. Remove any element from heap\n";
    cout << "4. Display heap\n";
    cout << "5. Exit\n";

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value to insert: ";
                cin >> x;
                heap.insert(x);
                break;
            case 2:
                x = heap.remove();
                cout << "Minimum element removed is: " << x << endl;
                break;
            case 3:
                cout << "Enter value to remove: ";
                cin >> x;
                if (x == -1) {
                    cout << "Invalid value (-1 is reserved for removing min)" << endl;
                    break;
                }
                x = heap.remove(x);
                if (x == -1)
                    cout << "Element not found in the heap" << endl;
                else
                    cout << "Element removed is: " << x << endl;
                break;
            case 4:
                cout << "Heap: ";
                heap.display();
                break;
            case 5:
                cout << "Exiting the program" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 5);

    return 0;
}
