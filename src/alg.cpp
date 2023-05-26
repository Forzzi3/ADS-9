// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    std::string oneword;
    if (!file) {
        std::cout << "File error!" << std::endl;
    }
    while (!file.eof()) {
        int ch = tolower(file.get());
        if (isalpha(ch)) {
            oneword += ch;
        } else {
            tree.add(oneword);
            oneword = "";
        }
    }
    file.close();
    return tree;
}
