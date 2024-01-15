#include "BinaryTree.h"

int main(void)
{

    BTree b_tree = BTree();

    /*
    1. 존재하지 않는 데이터를 조회하는 경우.
       b_tree.search(0);
    2. 존재하지 않는 데이터를 삭제하는 경우.
       b_tree.remove(1);
    */

    try
    {
        b_tree.search(0);
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
        std::cout << "test 1 passed" << std::endl;
    }

    try
    {
        b_tree.insert(10);
        b_tree.insert(5);
        b_tree.insert(15);
        b_tree.insert(20);
        b_tree.insert(13);
        b_tree.insert(3);
        b_tree.insert(7);
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }

    std::cout << std::endl;
    std::cout << "insert end" << std::endl;
    std::cout << std::endl;

    try
    {
        std::cout << b_tree.search(10).get_value() << std::endl;
        std::cout << b_tree.search(5).get_value() << std::endl;
        std::cout << b_tree.search(15).get_value() << std::endl;
        std::cout << b_tree.search(20).get_value() << std::endl;
        std::cout << b_tree.search(13).get_value() << std::endl;
        std::cout << b_tree.search(3).get_value() << std::endl;
        std::cout << b_tree.search(7).get_value() << std::endl;
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }

    std::cout << std::endl;
    std::cout << "search end" << std::endl;
    std::cout << std::endl;

    try
    {
        b_tree.remove(100);
    }
    catch (char const *e) // 존재하지 않는 데이터를 삭제하려 한 경우
    {
        std::cout << e << std::endl;
        std::cout << "None Exist Error passed" << std::endl;
    }

    b_tree.remove(5);
    b_tree.remove(10);
    b_tree.remove(15);
    b_tree.remove(7);
    b_tree.remove(13);

    return 0;
}