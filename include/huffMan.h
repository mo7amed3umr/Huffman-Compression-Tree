//
// Created by abdallahdarwesh on 5/1/19.
//

#ifndef HUFFMANCODE_HUFFMAN_H
#define HUFFMANCODE_HUFFMAN_H

#include <map>
#include <string>
#include <fstream>

//huffmanTree node
template<typename T>
struct hNode {
    T data;
    hNode *left, *right;

    hNode(T Data) {
        data = Data;
        left = nullptr;
        right = nullptr;
    }

};

//comparator to priority_queue according to frequency of char
struct comparator {
    bool operator()(hNode<std::pair<char, int >> *&i, hNode<std::pair<char, int >> *&j) {
        return i->data.second > j->data.second;
    }
};

//function to build huffman tree from frequency map befor compress the file
hNode<std::pair<char, int>> *buildHuffManTree(std::map<char, int> &);
//function to build huffman tree from mapcode after the file is compressed
hNode<char> *buildHuffManTree(std::map<char, std::string> &);

std::map<char, std::string> getCode(hNode<std::pair<char, int>> *);

//used in getCode function
void get(hNode<std::pair<char, int>> *, std::map<char, std::string> &, std::string);
//used in the buildHuffManTree function
void build(hNode<char> *&, std::string, char c);

//void travin(hNode<std::pair<char, int>> *);

void compress(std::ifstream &, std::ofstream &, std::map<char, std::string> &);

void decompress(std::ifstream &, std::ofstream &);

#endif //HUFFMANCODE_HUFFMAN_H
