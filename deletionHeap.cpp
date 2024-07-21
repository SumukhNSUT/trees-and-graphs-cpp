#include<iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int size = 0;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {

        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }

    }

    // deleting root node
    void deleteFromHeap() {
        if (size == 0) {
            return;
        }

        // swap 1st and last node or simply put value of last node to 1st node(root node)
        arr[1] = arr[size];
        // remove last node
        size--;

        // propagate new root node to correct place
        int i = 1;
        while (i < size) {
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left > size && arr[i] < arr[left]) {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (right < size && arr[i] < arr[right]) {
                swap(arr[i], arr[right]);
                i = right;
            }
            return;
        }
    }

    void print() {
        for (int i = 1; i <= size;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();
    return 0;
}