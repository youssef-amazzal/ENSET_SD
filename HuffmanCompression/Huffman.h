#pragma once
#include "HeapVect.h"
#include <vector>
#include <fstream>
#include <filesystem>
#include <map>

struct CharFreq {
    char data;
    int freq;
};

class Node {
public:
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq)
        : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

class HuffmanTree {
    MinHeapVect<Node*> minHeap;
public:
    std::map<char, std::string> huffmanCodes;

    void storeHuffmanCodes(Node* root, const std::string& str) {
        if (!root)
            return;

        if (root->data != '$')
            huffmanCodes[root->data] = str;

        storeHuffmanCodes(root->left, str + "0");
        storeHuffmanCodes(root->right, str + "1");
    }

    std::string getHuffmanCode(char ch) {
        return huffmanCodes[ch];
    }

    void buildHuffmanTree(std::vector<CharFreq>& freq) {
        for (auto cf : freq) {
            minHeap.push(new Node(cf.data, cf.freq));
        }

        while (minHeap.size() != 1) {
            Node *left = minHeap.top();
            minHeap.pop();

            Node *right = minHeap.top();
            minHeap.pop();

            Node *top = new Node('$', left->freq + right->freq);
            top->left = left;
            top->right = right;

            minHeap.push(top);
        }

        storeHuffmanCodes(minHeap.top(), "");
    }

    void compressFile(const std::filesystem::path& inputFilePath, const std::filesystem::path& outputFilePath) {
        // Open the input file
        std::ifstream inputFile(inputFilePath);
        if (!inputFile.is_open()) {
            std::cerr << "Unable to open file " << inputFilePath << "\n";
            return;
        }

        // Count the frequency of each character
        std::map<char, int> freq;
        char ch;
        while (inputFile.get(ch)) {
            freq[ch]++;
        }

        // Close the input file
        inputFile.close();

        // Build the Huffman tree
        std::vector<CharFreq> freqVec;
        for (const auto& pair : freq) {
            freqVec.push_back({pair.first, pair.second});
        }
        buildHuffmanTree(freqVec);

        std::ofstream outputFile(outputFilePath);
        if (!outputFile.is_open()) {
            std::cerr << "Unable to open file " << outputFilePath << "\n";
            return;
        }

        inputFile.open(inputFilePath);
        while (inputFile.get(ch)) {
            outputFile << getHuffmanCode(ch);
        }

        outputFile.close();
    }

    void decompressFile(const std::filesystem::path& inputFilePath, const std::filesystem::path& outputFilePath) {
        // Open the input file
        std::ifstream inputFile(inputFilePath);
        if (!inputFile.is_open()) {
            std::cerr << "Unable to open file " << inputFilePath << "\n";
            return;
        }

        // Read the compressed data
        std::string compressedData;
        std::getline(inputFile, compressedData);

        // Close the input file
        inputFile.close();

        // Open the output file
        std::ofstream outputFile(outputFilePath);
        if (!outputFile.is_open()) {
            std::cerr << "Unable to open file " << outputFilePath << "\n";
            return;
        }

        // Decompress the data
        Node* current = minHeap.top();
        for (char bit : compressedData) {
            if (bit == '0')
                current = current->left;
            else
                current = current->right;

            if (current->left == nullptr && current->right == nullptr) { // leaf node
                outputFile << current->data;
                current = minHeap.top();
            }
        }

        // Close the output file
        outputFile.close();
    }
};

