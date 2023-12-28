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


LinkedNode::LinkedNode(int input_value){
    value = input_value;
    Right = nullptr;
    Left = nullptr;
};


void LinkedNode::set_left(LinkedNode *target){
    if (Left != nullptr){
        LinkedNode *swap = Left;
        Left = target;

        if (target != nullptr)
            target->Left = swap;
    }
    else{
        Left = target;
    }
};


void LinkedNode::set_left_null(){
    Left = nullptr; 
};


void LinkedNode::set_right(LinkedNode *target){
    if (Right != nullptr){
        LinkedNode *swap = Right;
        Right = target;
        
        if (target != nullptr)
            target->Right = swap;
    }
    else{
        Right = target;
    }
};

void LinkedNode::set_right_pass(LinkedNode *target){
    if (Right != nullptr){
        LinkedNode *swap = Right;
        Right = target;

        target->Left = swap->Left;
    }
    else{
        Right = target;
    }
}

void LinkedNode::set_right_null(){
    Right = nullptr; 
};


LinkedNode* LinkedNode::get_left(){
    return Left;
}


LinkedNode* LinkedNode::get_right(){
    return Right;
}


int LinkedNode::get_value(){
    return value;
}


EdgeNode::EdgeNode(){
    RightEdge = nullptr;
    LeftEdge = nullptr;
};


void EdgeNode::append_left(int input_value){
    LinkedNode *new_node = new LinkedNode(input_value);

    if (LeftEdge != nullptr){
        LinkedNode *swap;
        swap = LeftEdge;
        swap->set_left(new_node);

        LeftEdge = new_node;
        new_node->set_right(swap);
    }
    else{
        LeftEdge = new_node;
        RightEdge = new_node;
    }
};


void EdgeNode::append_right(int input_value){
    LinkedNode *new_node = new LinkedNode(input_value);

    if (RightEdge != nullptr){
        LinkedNode *swap;
        swap = RightEdge;
        swap->set_right(new_node);

        RightEdge = new_node;
        new_node->set_left(swap);
    }
    else{
        RightEdge = new_node;
        LeftEdge = new_node;
    }
};


LinkedNode* EdgeNode::pop_left(){
    if (LeftEdge == nullptr)
        throw "Empty List";
    else{
        LinkedNode *right = LeftEdge->get_right();

        if (right != nullptr){
            LinkedNode *tmp = LeftEdge;
            LeftEdge = right;

            LeftEdge->set_left_null(); // 없어진 노드의 주소를 참조하지 못하도록 삭제

            tmp->set_right_null(); // 없어진 노드의 주소를 참조하지 못하도록 삭제

            return tmp;
        }
        else{
            LinkedNode *tmp = LeftEdge;

            RightEdge = nullptr;
            LeftEdge = nullptr;

            return tmp;
        }
    }
};


LinkedNode* EdgeNode::pop_right(){
    if (RightEdge == nullptr){
        throw "Empty List";
    }
    else{
        LinkedNode *left = RightEdge->get_left();

        if (left != nullptr){
            LinkedNode *tmp = RightEdge;
            RightEdge = left;

            RightEdge->set_right_null(); // 없어진 노드의 주소를 참조하지 못하도록 삭제

            tmp->set_left_null(); // 없어진 노드의 주소를 참조하지 못하도록 삭제

            return tmp;
        }
        else{
            LinkedNode *tmp = RightEdge;

            RightEdge = nullptr;
            LeftEdge = nullptr;

            return tmp;
        }
    }
};


LinkedNode EdgeNode::search(int value){
    LinkedNode *cur_node = LeftEdge;
    
    while (true){
        if (cur_node == nullptr)
            throw "Not Exist Value";
        if (cur_node->get_value() == value){
            break;
        }
        else{
            cur_node = cur_node->get_right();
        }
    }

    return *cur_node; // left, right 주소가 있는 것이 맞는지 잘 모르겠음
};


void EdgeNode::remove(int value){
    LinkedNode *cur_node = LeftEdge;

    while (true){
        if (cur_node == nullptr)
            throw "Not Exist Value";
        if (cur_node->get_value() == value){
            break;
        }
        else{
            cur_node = cur_node->get_right();
        }
    }

    if (cur_node->get_left() != nullptr){
        LinkedNode *tmp = cur_node->get_left();

        if (RightEdge == cur_node){
            tmp->set_right(cur_node->get_right());
            RightEdge = cur_node->get_left();
        }
        else{
            tmp->set_right_pass(cur_node->get_right());
        }
    }
    else{
        LeftEdge = cur_node->get_right();
    }
    
    delete cur_node;
}