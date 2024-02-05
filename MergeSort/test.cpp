#include "merge_sort.h"

int main(void)
{

    // test case 1
    // even nums
    std::vector<int> case1 = {7, 3, 2, 16, 24, 4, 11, 9};
    std::vector<int> sorted = merge_sort(case1);

    for (std::vector<int>::iterator itr = sorted.begin(); itr != sorted.end(); ++itr)
        std::cout << *itr << ' ';
    std::cout << std::endl
              << "End case 1 : even case" << std::endl;

    // test case 2
    // odd nums
    std::vector<int> case2 = {38, 27, 43, 3, 9, 82, 10};
    sorted = merge_sort(case2);

    for (std::vector<int>::iterator itr = sorted.begin(); itr != sorted.end(); ++itr)
        std::cout << *itr << ' ';
    std::cout << std::endl
              << "End case 2 : odd case" << std::endl;

    // test case 3
    // even nums
    std::vector<int> case3;
    for (int i = 100; i > 0; i--)
        case3.push_back(i);

    sorted = merge_sort(case3);

    for (std::vector<int>::iterator itr = sorted.begin(); itr != sorted.end(); ++itr)
        std::cout << *itr << ' ';
    std::cout << std::endl
              << "End case 3 : even case" << std::endl;

    // test case 4
    // odd nums
    std::vector<int> case4;
    for (int i = 99; i > 0; i--)
        case4.push_back(i);

    sorted = merge_sort(case4);

    for (std::vector<int>::iterator itr = sorted.begin(); itr != sorted.end(); ++itr)
        std::cout << *itr << ' ';
    std::cout << std::endl
              << "End case 4 : odd case" << std::endl;

    // test case 5
    // random
    // even nums

    // random 정의
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dis(0, 99);

    std::vector<int> case5;
    for (int i = 100; i > 0; i--)
        case5.push_back(dis(gen));

    sorted = merge_sort(case5);

    for (std::vector<int>::iterator itr = sorted.begin(); itr != sorted.end(); ++itr)
        std::cout << *itr << ' ';
    std::cout << std::endl
              << "End case 5 : even with random" << std::endl;

    // test case 6
    // random
    // odd nums

    std::vector<int> case6;
    for (int i = 99; i > 0; i--)
        case6.push_back(dis(gen));

    sorted = merge_sort(case6);

    for (std::vector<int>::iterator itr = sorted.begin(); itr != sorted.end(); ++itr)
        std::cout << *itr << ' ';
    std::cout << std::endl
              << "End case 6 : odd with random" << std::endl;

    return 0;
}