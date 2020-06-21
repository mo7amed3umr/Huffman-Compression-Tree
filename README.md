## Huffman Compression Tree
## Team members:
* Ahmed Khaled
* Abdullah Elsayed
* Abdullah Darwesh
* Zeinab Walid
* Mohamed Elsayed
* Mohamed omar


### Introduction

In information theory, Huffmann code is a particular type that is used commonly for lossless data compression.
Huffma coding is an algorithm for compression of data devloped by David A. Huffman. The output from Huffman's algorithm can be viewed as a variable-length code table for encoding a source symbol such as a character in a file. The algorithm derives a table from getting characters and their frequencies (e.g. in a text).
This table show new representations of these characters instead of their original ASCII binary representations. These new "codes" for characters often are less in bits than original ASCII. For example, 'A' is represented as "01000001" but Huffman algorithm can reduce it for example into "1010". Of course, the later representation isn't constant for all files as it depends on the character frequency in the text file. The more frequency, the less length its representation has and vice versa.

### Algorithm

The algorith we used here depends on min heap in the following systematic:

1. Building a minheap based on the frequency of each character in whatever file or string is being read in.
2. Popping off the 2 smallest values from the minheap and combining their weights into a new node.
3. Re-inserting the new node back into the same minheap.

After having our Huffman's tree we indicate transition in the right direction as '1' and in the left direction as '0'. So for a character required to reach to move from head in a right -> left -> right has "101" representation.

### Headers

#### 1. fileProcess.h

```cpp
std::map<char, int> getMap(std::string path)
{
 /*
  *   this function takes recieves the path of the file
  *   required to be compressed, iterate on each character
  *   and inserting it them in a map with increasing its
  *   frequency each time the iterartor pass by that
  *   character.
  */
}
```

#### 2. huffMan.h

```cpp
struct hNode
{
   /*
    * Here we create a data structure with the name of
    * hNode has three members; `data` for the data of the
    * node, `left` and `right` represent the next
    * pointer of the node in the tree
    */
};

struct comparator {
    /* comparator has a bool operator() that changes the
     * default oreintation of the priority queue and
     * changes it from max heap to min heap
     */
};

hNode<std::pair<char, int>> *buildHuffManTree(std::map<char, int> &);
/*
 * this function build our Huffman tree using the min heap
 * after commuting the two lowest frequncies then the
 * scond lowest and so on adding each commuted frequency
 * in a node inserting this node again in the min heap.
 * After finishing iteration, the function returns the new
 * root of the min heap.
 */

void get(hNode<std::pair<char, int>> *root, std::map<char, std::string> &map, std::string code);
/*
 * this function gets the new representation of the character
 * in the huffman tree in the same way we mentioned in
 * the Algoritm section. Using recursion iterating on
 * each node in the Huffman tree until we reach the nodes
 * adding to the code of character '0' if we moved right
 * and '1' if we moved left.
 */

std::map<char, std::string> getCode(hNode<std::pair<char, int>> *root);
/*
 * this function uses `get` function and return a map
 * of each character in the text file and its new representation.
 */

void travin(hNode<std::pair<char, invoid travin(hNode<std::pair<char, int>> *root)t>> *root);
/*
 * this function travese the Huffman tree in-order and
 * print the pair of the character and its frequency.
 */

void compress(std::ifstream &infile, std::ofstream &outfile, std::map<char, std::string> &mapcode);
/*
 * this function recives two paths, the first for the file required to be
 * compressed, the second is for the compressed format itself and also
 * recieves the map of the new representation for each character in the
 * text file.
 * after decoding each character to its new code, every eight bits are
 * concatenated and are casted into character and this character is then
 * being recorded in the compressed file `outfile`.
 * Also, `compress` compress the codeMap so that at decompressing
 * the file, it also recives the codeMap that contains the new representations
 * for each character.
 * the codeMap and the compressed text are seperated by the null terminator'\0' and between pairs of character
 * and new representation we find '-1' character which has the ASCII of 255, a character we rarely meet in the
 * compressed sequence.
 */

void decompress(std::ifstream &infile, std::ofstream &outfile);
 /* 'decompress' function recives two parameters; 'infile' that has the path
  * of the file required to be decompressed, and 'outfile' that recives the path
  * of the file which will receive the original data we compressed earlier.
  * This time we iterate on the compressed file 'infile' until we reach the '-1' separator
  * between pairs of character and code. inserting each character and code into a new Huffman tree
  * Continuing the iterating on the compressed file until we reach the null terminator '\0'.
  * After that, we iterate on the characters, decoding it into the 8 bits represent the character and
  * concatenates these bits into an empty string.
  * Then, we itearate on that string and we start traversing on the Huffman tree we made eariler
  * from the compressed file. As we mentioned before in Algoritm section above, for each '0' we move left and for
  * each '1' we move right until we reach the leaf node then we get the character of that leaf node and push it
  * into the final file which is `outfile`.
  */
```