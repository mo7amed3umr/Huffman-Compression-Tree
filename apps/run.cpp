//
// Created by abdallahdarwesh on 5/8/19.
//
#include <iostream>
#include "fileProcess.h"
#include "huffMan.h"
#include <fstream>

int main(){
    std::string in_path ="../test/originaltext.txt";
    std::string out_path1="../test/textaftercompress.txt";
    std::string out_path2="../test/textafterdecompress.txt";
    std::ifstream infile {in_path};
    std::ofstream compressFile {out_path1,std::ios::trunc};
    std::ofstream decompressFile{out_path2,std::ios::trunc};

    std::map<char, int> char_freq = getMap(in_path);
    hNode<std::pair<char, int>> *root = buildHuffManTree(char_freq);
    std::map<char, std::string> mapCode=getCode(root);

    compress(infile,compressFile,mapCode);
    //open the compress file
    infile.open(out_path1);
    if(infile){
        decompress(infile, decompressFile);
    }else{
        std::cerr<<"ERROR"<<std::endl;
    }
    return 0;
};

