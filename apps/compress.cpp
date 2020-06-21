//
// Created by abdallahdarwesh on 5/8/19.
//
#include "huffMan.h"
#include <vector>
#include <iostream>
#include <bitset>

void compress(std::ifstream &infile, std::ofstream &outfile, std::map<char, std::string> &mapcode) {

    if (infile && outfile) {

        char c;                                   //to get chars in infile
        std::string code{};                       //to store the code of each char
        std::string str{};                        //to store the whole string of code
        std::vector<char> v{};                    //to store the char values after compression


        while (infile.get(c)) {                   //getting chars of in file
            code = mapcode[c];
            str.append(code);
        }

        /* first store the mapcode */

        for (auto[Char, Code]:mapcode) {
            v.push_back(Char);
            for (char C :Code)
                v.push_back(C);
            v.push_back(char(255));               //end of code
        }

        v.push_back('\0');                       //seperating the original data from compressed

        /* second store the compressed values */

        unsigned long long length = str.size();   //length of whole srting code
        unsigned long long i = 0;                 //iterator used in the next while loop


        while (length > 8) {

            code = str.substr(i, 8);
            std::bitset<8> bits{code};
            v.push_back(bits.to_ulong());

            i += 8;
            length -= 8;
        }
        if (length) {
            code = str.substr(i, length);
            std::bitset<8> bits{code};
            v.push_back(bits.to_ulong());
            v.push_back(length);                 //storing the length of last byte
        }

        /* Compression */
        for (char C:v) {
            outfile.put(C);
        }

    } else {
        std::cerr << "ERROR" << std::endl;
        exit(1);
    }
    outfile.close();
    infile.close();
}
