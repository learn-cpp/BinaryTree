#include <iostream>
#include "src/BinaryTree.cpp"

int main(int argc, const char * argv[])
{
    BinaryTree<double, const char*> bt;

    try {
        bt.add(3.14, "pi");
        bt.add(2.7, "e");
        std::cout << bt.search(3.14) << std::endl;
        std::cout << bt.search(5.5) << std::endl;
    } catch (const char *e) {
        std::cerr << "Exception message: " << e << std::endl;
        return -1;
    }
}