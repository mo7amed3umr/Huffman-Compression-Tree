//
// Created by abdallahdarwesh on 5/8/19.
//
#include "huffMan.h"
#include <bitset>
#include <iostream>
void decompress(std::ifstream &infile, std::ofstream &outfile) {
    if (infile) {
        std::map<char, std::string> mapcode;
        std::string str{};
        char c1 = 0, c2 = 0;

        //reading mapcode from input file
        while (infile.get(c1)) {
            if (c1 == '\0')
                break;
            for (infile.get(c2); c2 != char(255); infile.get(c2)) {
                str.push_back(c2);
            }
            std::pair<char, std::string> pair{c1, str};
            mapcode.insert(pair);
            str = "";
        }

        str="";
        //reading the code and store it in str
        std::bitset<8> bits{};
        while(infile.get(c1)){
            bits=c1;
            str.append(bits.to_string());
        }

        hNode<char> *root = buildHuffManTree(mapcode);
        hNode<char>* pn =root;
        if(str.size()>16) {
            for (long long i = 0; i < str.size() - 16; i++) {
                char c = str[i];
                if (c == '0') {
                    pn = pn->left;
                } else {
                    pn = pn->right;
                }
                if (pn->left == pn->right) {
                    outfile.put(pn->data);
                    pn = root;
                }
            }

            std::string lastByte = str.substr(str.size() - 16, 8);
            std::string byteLength = str.substr(str.size() - 8, 8);
            std::bitset<8> length{byteLength};
            int l=length.to_ullong();
            int size=lastByte.size();
            for (int j = 8-l; j < size; ++j) {
                char c = lastByte[j];
                if (c == '0') {
                    pn = pn->left;
                } else {
                    pn = pn->right;
                }
                if (pn->left == pn->right) {
                    outfile.put(pn->data);
                    pn = root;
                }
            }
        } else{
            std::string firstByte = str.substr(0, 8);
            std::string byteLength = str.substr(8, 8);
            std::bitset<8> length{byteLength};
            int l =length.to_ullong();
            int size =firstByte.size();
            for (int j = 8-l ; j < size; ++j) {
                char c = firstByte[j];
                if (c == '0') {
                    pn = pn->left;
                } else {
                    pn = pn->right;
                }
                if (pn->left == pn->right) {
                    outfile.put(pn->data);
                    pn = root;
                }
            }

        }
    } else {
        std::cerr << "ERROR" << std::endl;
    }
}
