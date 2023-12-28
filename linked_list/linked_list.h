class LinkedNode
{
private:
    int value;
    LinkedNode *Right;
    LinkedNode *Left;

public:
    LinkedNode() = delete;
    LinkedNode(int value);
    void set_left(LinkedNode *target);
    void set_left_null();
    void set_right(LinkedNode *target);
    void set_right_pass(LinkedNode *target);
    void set_right_null();
    LinkedNode *get_left();
    LinkedNode *get_right();
    int get_value();
};


class EdgeNode
{
private:
    LinkedNode* RightEdge;
    LinkedNode* LeftEdge;

public:
    EdgeNode();
    void append_left(int value);
    void append_right(int value);
    LinkedNode *pop_left();
    LinkedNode *pop_right();
    LinkedNode search(int value);
    void remove(int value);
};