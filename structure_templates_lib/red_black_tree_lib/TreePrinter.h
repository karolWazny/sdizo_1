#ifndef SDIZO_1_TREEPRINTER_H
#define SDIZO_1_TREEPRINTER_H

#include <string>
#include "red_black_tree_lib/nodes/Node.h"

using string = std::string;

template<typename T,typename U>
class TreePrinter
{
public:
    string toString(NodePointer<T, U> root);
private:
    string stringarize(NodePointer<T, U> root);
};

template<typename T, typename U>
string TreePrinter<T, U>::toString(NodePointer <T, U> root) {
    string output = "[";
    output += stringarize(root);
    output += "]";
    return output;
}

template<typename T, typename U>
string TreePrinter<T, U>::stringarize(NodePointer <T, U> root) {
    if(root->isNil())
        return "";
    string output;
    output += stringarize(root->getLeft());
    if(!output.empty())
        output += ", ";
    output += std::to_string(root->getKey());
    string buffer = stringarize(root->getRight());
    if(!buffer.empty())
        output += ", ";
    output += buffer;
    return output;
}

#endif //SDIZO_1_TREEPRINTER_H
