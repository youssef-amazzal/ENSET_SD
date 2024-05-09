#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class MinHeapVect {
    std::vector<T> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }

    void swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int i) {
        if (i && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            heapifyUp(parent(i));
        }
    }

    void heapifyDown(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int smallest = i;

        if (left < heap.size() && heap[left] < heap[i])
            smallest = left;

        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void push(T key) {
        heap.push_back(key);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    void pop() {
        if (heap.empty())
            throw std::out_of_range("Heap is empty, cannot pop.");

        heap[0] = heap.back();
        heap.pop_back();

        heapifyDown(0);
    }

    T top() {
        if (heap.empty())
            throw std::out_of_range("Heap is empty.");

        return heap.front();
    }

    int size() {
        return heap.size();
    }

    bool empty() {
        return heap.empty();
    }

    void printArray() {
        for (T i : heap) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }

    void printTree(int i = 0, int spaces = 0) {
        if (i < heap.size()) {
            printTree(rightChild(i), spaces + 4);

            for (int j = 0; j < spaces; j++) {
                std::cout << ' ';
            }

            std::cout << heap[i] << '\n';

            printTree(leftChild(i), spaces + 4);
        }
    }
};