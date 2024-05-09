#include "Huffman.h"

struct CharFreq;

static const auto ROOT_PATH = std::filesystem::current_path().parent_path();

int main() {
    HuffmanTree huffTree;

    huffTree.compressFile(ROOT_PATH / "input.txt", ROOT_PATH / "output.txt");
    huffTree.decompressFile(ROOT_PATH / "output.txt", ROOT_PATH / "decompressed.txt");
    return 0;
}
