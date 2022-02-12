#include <cstdio>
#include <cstring>
#include <algorithm>

class MaxHeap {
    public:
        MaxHeap(int *src, unsigned int n) {
            size = n;
            heap = new int [size + 1];
            memcpy(heap + 1, src, sizeof(int) * n);
        }
        ~MaxHeap() {
            size = 0;
            if (heap) {
                delete [] heap;
                heap = NULL;
            }
        }
        void heapify();
        void insert(int x);
        int delMax();
        void sort();
        int at(unsigned int i);
        unsigned int len() {return size;}
        bool empty() { return size == 0; }
        void print();

    private:
        void swim(unsigned int k);
        void sink(unsigned int k);

    private:
        unsigned int size = 0;
        int *heap = NULL;
};

int MaxHeap::at(unsigned int i) {
    if (i >= 1 && i <= size) return heap[i];
    else exit(-1);
}

void MaxHeap::swim(unsigned int k) {
    while (k > 1 && heap[k] > heap[k/2]) {
        std::swap(heap[k], heap[k/2]);
        k /= 2;
    }
}

void MaxHeap::sink(unsigned int k) {
    while (2 * k <= size) {
        unsigned int l = 2 * k;
        if (heap[k] < heap[l] 
                && heap[l] < heap[l + 1]
                && l+1 <= size) l++;
        if (heap[k] < heap[l]) {
            std::swap(heap[k], heap[l]);
            k = l;
        } else {
            break;
        }
    }
}

void MaxHeap::heapify() {
    unsigned int k = size / 2;    
    while (k >= 1) {
        sink(k);
        k--;
    }
}

void MaxHeap::insert(int x) {
    heap[++size] = x;
    swim(size);
}

int MaxHeap::delMax() {
    if (size) {
        std::swap(heap[1], heap[size]);
        size--;
        sink(1);
        return heap[size + 1];
    } else {
        exit(-1);
    }
}

void MaxHeap::sort() {
    heapify();
    unsigned k = size;
    while (size) {
        delMax();
    }
    size = k;
}

void MaxHeap::print() {
    for (unsigned int i = 1; i <= size; i++) {
        printf("%d%c", heap[i], i == size ? '\n' : ' ');
    }
}

int main()
{
    int a[] = {9, 1, 8, 3, 7, 2, 6, 5, 4};
    {
        MaxHeap h(a, sizeof(a)/sizeof(int));
        h.heapify();
        while (!h.empty()) {
            printf("%d ", h.delMax());
        }
        printf("\n");
    }
    {
        MaxHeap h(a, sizeof(a)/sizeof(int));
        h.sort();
        h.print();
    }
}
