#include <iostream>
#include <utility>
#include "../linked_list/linked_list.h"

void quick_sort(LinkedNode *, LinkedNode *);

int main()
{

    // case 1
    EdgeNode linked_list = EdgeNode();

    int vals[] = {5, 3, 8, 4, 9, 1, 6, 2, 7};

    // init linked_list
    for (int val : vals)
        linked_list.append_right(val);

    quick_sort(&linked_list.get_LeftEdge(), &linked_list.get_RightEdge());

    for (int i = 0; i < 9; i++)
        std::cout << linked_list.pop_left()->get_value() << ' ';

    std::cout << std::endl;


    // case 2
    EdgeNode linked_list2 = EdgeNode();

    int vals2[] = {5, 3, 7, 6, 2, 1, 4};

    // init linked_list
    for (int val : vals2)
        linked_list2.append_right(val);

    quick_sort(&linked_list2.get_LeftEdge(), &linked_list2.get_RightEdge());

    for (int i = 0; i < 7; i++)
        std::cout << linked_list2.pop_left()->get_value() << ' ';

    std::cout << std::endl;

    return 0;
}

void quick_sort(LinkedNode *l, LinkedNode *r)
{
    // quick sort
    if (l->get_value() != r->get_value()){

        LinkedNode *pivot = l;
        LinkedNode *high = r;
        LinkedNode *low = l->get_right();

        while (true){
            // low 와 high가 다른 경우
            if (low->get_value() != high->get_value()){
                if (high->get_value() < low->get_value()){
                    int tmp = high->get_value();
                    high->set_value(low->get_value());
                    low->set_value(tmp);

                    high = high->get_left();
                }
                else
                    low = low->get_right();
            }
            // low와 high가 같은 경우
            else{
                /*
                    해당 구현에서는 high와 low가 동일한 시점에
                    pivot과 high를 교환
                    따라서 반드시 가장 왼쪽이 있는 pivot보다 
                    high가 작다는 보장을 할 수 없음 
                */
                if (pivot->get_value() > high->get_value())
                {
                    int tmp = pivot->get_value();
                    pivot->set_value(high->get_value());
                    high->set_value(tmp);
                }
                
                break;
            }
        }
        
        // high가 l 혹은 r과 동일한 경우을 방지
        if (high->get_value() != l->get_value())
            quick_sort(l, high->get_left());
        if (high->get_value() != r->get_value())
            quick_sort(high->get_right(), r);
    }
    else
        return;
    
}