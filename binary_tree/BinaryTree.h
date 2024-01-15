#include <iostream>
#include <memory>

// B Tree를 구성하는 노드
class TreeNode
{
private:
    int value;
    std::shared_ptr<TreeNode> Left;
    std::shared_ptr<TreeNode> Right;

public:
    TreeNode(int input_value) : value(input_value) {} // 생성자

    int get_value();
    std::shared_ptr<TreeNode> get_left();
    std::shared_ptr<TreeNode> get_right();
    void set_left(std::shared_ptr<TreeNode> left);
    void set_right(std::shared_ptr<TreeNode> left);
};

// 이진탐색트리
class BTree
{
private:
    std::shared_ptr<TreeNode> Root;

public:
    BTree() : Root(nullptr) {}

    void insert(int value);
    void remove(int value);
    TreeNode search(int value);
};