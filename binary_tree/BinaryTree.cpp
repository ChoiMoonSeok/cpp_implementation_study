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
    TreeNode(int input_value) : value(input_value) {}             // 생성자
    ~TreeNode() { std::cout << value << " delete" << std::endl; } // 삭제자

    int get_value();
    std::shared_ptr<TreeNode> get_left();
    std::shared_ptr<TreeNode> get_right();
    void set_left(std::shared_ptr<TreeNode> left);
    void set_right(std::shared_ptr<TreeNode> left);
};

class BTree
{
private:
    std::shared_ptr<TreeNode> Root;
    std::shared_ptr<TreeNode> remove(std::shared_ptr<TreeNode> node, int value);

public:
    BTree() : Root(nullptr) {}

    void insert(int value);
    void remove(int value);
    TreeNode search(int value);
};

int TreeNode::get_value()
{
    return value;
}

std::shared_ptr<TreeNode> TreeNode::get_left()
{
    return Left;
}

std::shared_ptr<TreeNode> TreeNode::get_right()
{
    return Right;
}

void TreeNode::set_left(std::shared_ptr<TreeNode> left)
{
    Left = left;
}

void TreeNode::set_right(std::shared_ptr<TreeNode> right)
{
    Right = right;
}

void BTree::insert(int value)
{
    // 메모리 복사 횟수를 줄이기 위해 make_shared 사용
    std::shared_ptr<TreeNode> new_node = std::make_shared<TreeNode>(value);

    if (Root != nullptr)
    {

        std::shared_ptr<TreeNode> head = Root;
        while (true)
        {
            if (head != nullptr) // B_Tree가 비어있지 않은 경우
            {
                if (head->get_value() > value)
                {
                    if (head->get_left() == nullptr)
                    {
                        head->set_left(new_node);
                        break;
                    }
                    else
                        head = head->get_left();
                }
                else
                {
                    if (head->get_right() == nullptr)
                    {
                        head->set_right(new_node);
                        break;
                    }
                    else
                        head = head->get_right();
                }
            }
            else // B_Tree가 비어있는 경우
            {
                head = new_node;
                break;
            }
        }
    }
    else
    {
        Root = new_node;
    }
}

TreeNode BTree::search(int value)
{
    std::shared_ptr<TreeNode> head = Root;
    while (true)
    {
        if (head != nullptr)
        {
            if (head->get_value() == value)
            {
                break;
            }
            else if (head->get_value() > value)
            {
                head = head->get_left();
            }
            else
            {
                head = head->get_right();
            }
        }
        else
        {
            throw "Value None Exist Error";
        }
    }

    return *head;
}

std::shared_ptr<TreeNode> BTree::remove(std::shared_ptr<TreeNode> node, int value)
{
    // 삭제할 값이 현재 노드의 값보다 큰 경우
    if (node->get_value() < value)
    {
        if (node->get_right() != nullptr)
            node->set_right(remove(node->get_right(), value));
        else
            throw "None Exist Value Error";
    }
    else
    {
        // 삭제할 값이 현재 노드의 값보다 작은 경우
        if (node->get_value() != value)
        {
            if (node->get_left() != nullptr)
                node->set_left(remove(node->get_left(), value));
            else
                throw "None Exist Value Error";
        }
        else
        {
            // 삭제할 값이 현재 노드의 값과 동일한 경우
            if (node->get_left() != nullptr)
            {
                if (node->get_right() != nullptr)
                {
                    // 오른쪽 트리에서 가장 작은 값 검색
                    std::shared_ptr<TreeNode> parent = nullptr;
                    std::shared_ptr<TreeNode> head = node->get_right();
                    while (true)
                    {
                        if (head->get_left() != nullptr)
                        {
                            parent = head;
                            head = head->get_left();
                        }
                        else
                            break;
                    }

                    if (parent != nullptr)
                    {
                        if (head->get_right() != nullptr)
                            parent->set_left(head->get_right());
                        else
                            parent->set_left(nullptr);

                        head->set_left(node->get_left());
                        head->set_right(node->get_right());

                        node = head;
                    }
                    else
                    {
                        head->set_left(node->get_left());
                        node = head;
                    }
                }
                else
                    node = node->get_left();
            }
            else
            {
                node = node->get_right();
            }
        }
    }

    return node;
}

void BTree::remove(int value)
{
    Root = remove(Root, value);
}