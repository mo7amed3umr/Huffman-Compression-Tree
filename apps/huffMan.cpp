//
// Created by abdallahdarwesh on 5/1/19.
//
#include "huffMan.h"
#include <queue>
#include <vector>
#include <iostream>
#include <bitset>

hNode<std::pair<char, int >> *buildHuffManTree(std::map<char, int> &char_freq) {
    //std::priority_queue<hNode<Type,vector<Type>,comp>
    std::priority_queue<hNode<std::pair<char, int >> *, std::vector<hNode<std::pair<char, int >> *>, comparator> pq;

    for (auto element:char_freq) {//element of type std::pair
        hNode<std::pair<char, int >> *pHNode = new hNode<std::pair<char, int >>{element};
        pq.push(pHNode);
    }

    while (pq.size() != 1) {
        hNode<std::pair<char, int >> *p1 = pq.top();
        pq.pop();
        hNode<std::pair<char, int >> *p2 = pq.top();
        pq.pop();

        int sumFreq = p1->data.second + p2->data.second;

        std::pair<char, int> pa{'#', sumFreq};

        auto *pNewNode = new hNode<std::pair<char, int >>{pa};

        pNewNode->left = p1;
        pNewNode->right = p2;
        pq.push(pNewNode);
    }

    hNode<std::pair<char, int >> *root = pq.top();
    pq.pop();

    return root;
}

std::map<char, std::string> getCode(hNode<std::pair<char, int>> *root) {
    std::map<char, std::string> mapCode;

    std::string code{};

    get(root, mapCode, code);

    return mapCode;
}

void get(hNode<std::pair<char, int>> *root, std::map<char, std::string> &map, std::string code) {
    if (!root)return;
    else {
        if (root->right != root->left) {
            get(root->left, map, code + "0");
            get(root->right, map, code + '1');
        } else {
            map.insert(std::pair<char, std::string>(root->data.first, code));
        }
    }
}


//void travin(hNode<std::pair<char, int>> *root) {
//    if (!root) {
//        return;
//    } else {
//        travin(root->left);
//        std::cout << root->data.first << root->data.second << " ";
//        travin(root->right);
//    }
//}

hNode<char> *buildHuffManTree(std::map<char, std::string> &mapcode) {
    hNode<char> *root = nullptr;
    for (auto[c, str]:mapcode) {
        build(root, str, c);
    }
    return root;
}

void build(hNode<char> *&root, std::string strCode, char ch) {
    hNode<char> *pn = nullptr;
    if (!root) {
        for (char c: strCode) {
            if (!pn) {
                if (c == '0') {
                    root = new hNode<char>{'#'};
                    root->left = new hNode<char>{'#'};
                    pn = root->left;
                } else {
                    root = new hNode<char>{'#'};
                    root->right = new hNode<char>{'#'};
                    pn = root->right;
                }
            } else {
                if (c == '0') {
                    pn->left = new hNode<char>{'#'};
                    pn = pn->left;
                } else {
                    pn->right = new hNode<char>{'#'};
                    pn = pn->right;
                }

            }
        }

        pn->data = ch;
        return;
    }

    pn = root;

    for (char c:strCode) {
        if (c == '0') {
            if (pn->left)
                pn = pn->left;
            else {
                pn->left = new hNode<char>{'#'};
                pn = pn->left;
            }
        } else {
            if (pn->right)
                pn = pn->right;
            else {
                pn->right = new hNode<char>{'#'};
                pn = pn->right;
            }

        }
    }

    pn->data = ch;

}