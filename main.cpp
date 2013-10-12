#include <iostream>
#include "src/BinaryTree.cpp"

int main(int argc, const char * argv[])
{
    BinaryTree<double, const char*> bt;

    try {
        bt.add(3.14, "pi");
        bt.add(2.7, "e");
        bt.add(2.1, "e");
        bt.add(2.5, "e");
        bt.add(3.7, "e");
        bt.add(9.7, "e");
        bt.add(10.7, "e");
        bt.out(std::cout);
    } catch (const char *e) {
        std::cerr << "Exception message: " << e << std::endl;
        return -1;
    }
}