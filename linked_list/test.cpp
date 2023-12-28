#include <iostream>
#include "linked_list.h"

void check_right_left(LinkedNode, int);

int main(void){

    EdgeNode list = EdgeNode();

    /*
    list가 비어 있을 때 발생할 수 있는 오류
    1. search()가 실행되는 경우
    2. remove()가 실행되는 경우
    3. pop_left()가 실행되는 경우
    4. pop_right()가 실행되는 경우

    case 1, 2는 Not Exist Value 에러를 반환
    case 3, 4는 Empty List 에러를 반환

    */

    // case 1
    try{
        list.search(0);
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
        std::cout << "case 1 passed." << std::endl;
    }

    // case 2
    try{
        list.remove(0);
    }
    catch (const char *e){
        std::cout << e << std::endl;
        std::cout << "case 2 passed." << std::endl;
    }

    // case 3
    try{
        list.pop_left();
    }
    catch (const char *e){
        std::cout << e << std::endl;
        std::cout << "case 3 passed." << std::endl;
    }

    // case 4
    try{
        list.pop_right();
    }
    catch (const char *e){
        std::cout << e << std::endl;
        std::cout << "case 4 passed." << std::endl;
    }

    /*
    append_left, append_right, remove가 혼재된 경우.
    모든 동작이 끝난 후, 리턴 값이 올바른지 확인.

    0 1 2 3 4 5 6 7 8 9 
    ar 0
    al 1
    al 2
    al 3
    ar 4
    ar 5
    remove 6
    remove 5
    ar 7
    al 8
    remove 2
    ar 9 
    */


    list.append_right(0);
    list.append_left(1);
    list.append_left(2);
    list.append_left(3);
    list.append_right(4);
    list.append_right(5);

    try{
        list.remove(6);
        std::cout << "remove 6 error occured." << std::endl;
    }
    catch (const char *e){
        std::cout << e << std::endl;
        std::cout << "remove 6 passed." << std::endl;
    }

    try{
        list.remove(5);
    }
    catch (const char *e){
        std::cout << e << std::endl;
        std::cout << "remove 5 error occured." << std::endl;
    }

    list.append_right(7);
    list.append_left(8);

    try{
        list.remove(2);
    }
    catch (const char *e){
        std::cout << e << std::endl;
        std::cout << "remove 2 error occured." << std::endl;
    }

    list.append_right(9);


    /*
    pop_left와 pop_right가 혼재된 경우

    pl 8
    pr 9
    pl 3
    pl 1
    pr 7
    pr 4
    pr 0

    */
    
    try{
        check_right_left(*list.pop_left(), 8);
        check_right_left(*list.pop_right(), 9);
        check_right_left(*list.pop_left(), 3);
        check_right_left(*list.pop_left(), 1);
        check_right_left(*list.pop_right(), 7);
        check_right_left(*list.pop_right(), 4);
        check_right_left(*list.pop_right(), 0);

        std::cout << "all tests passed." << std::endl;
    }
    catch(const char *e){
        std::cout << e << std::endl;
    }
    

    return 0;
}


void check_right_left(LinkedNode target, int ans){
    if (target.get_value() != ans)
        throw "pop value error.";
    if (target.get_left() != nullptr)
        throw "left value doesn't deleted.";
    if (target.get_right() != nullptr)
        throw "right value doesn't deleted.";
}