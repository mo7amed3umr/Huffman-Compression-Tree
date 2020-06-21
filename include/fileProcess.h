//
// Created by abdallahdarwesh on 5/1/19.
//

#ifndef HUFFMANCODE_FILEPROCESS_H
#define HUFFMANCODE_FILEPROCESS_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>


std::map<char, int> getMap(std::string path) {

    std::ifstream file{path, std::ios::in};
    std::map<char, int> char_freq;

    if (file) {
        char c;
        while (file.get(c)) {
            char_freq[c]++;
        }
    } else {
        std::cerr << "ERROR" << std::endl;
        exit(1);
    }

    file.close();
    return char_freq;
}

#endif //HUFFMANCODE_FILEPROCESS_H
