#include "unit_test_framework.h"
#include "vector.h"
#include "stack.h"
#include "list.h"
#include "unordered_map.h"
#include "map.h"

// NEIL GOLLAPDUI


TEST(vector_default) {
    vector<int> one;
    ASSERT_TRUE(one.size() == 0);
    ASSERT_TRUE(one.empty());
    one.push_back(-1);
    ASSERT_TRUE(one.size() == 1);
    ASSERT_TRUE(one.front() == -1);
    ASSERT_TRUE(one.back() == -1);
    ASSERT_FALSE(one.empty())
    one.push_front(3);
    one.push_front(2);
    one.push_front(5);
    one.push_front(0);
    one.push_front(1);
    ASSERT_TRUE(one.front() == 1);
    ASSERT_TRUE(one.back() == -1);
    one.push_back(10);
    ASSERT_TRUE(one.back() == 10);
    ASSERT_TRUE(one.size() == 7);
    one.pop_front();
    ASSERT_TRUE(one.size() == 6);
    ASSERT_TRUE(one.front() == 0);
    one.pop_front();
    ASSERT_TRUE(one.front() == 5);
    ASSERT_TRUE(one.size() == 5);
    ASSERT_TRUE(one[0] == 5);
    ASSERT_TRUE(one[1] == 2);
    ASSERT_TRUE(one[4] == 10);
}

TEST(vector_custom_constructor) {
    vector<int> one(30, 3);
    ASSERT_TRUE(one[0] == 3);
    ASSERT_TRUE(one[29] == 3);
    ASSERT_TRUE(one.size() == 30);
    ASSERT_TRUE(one[15] == 3);
    one.push_front(7);
    ASSERT_TRUE(one.size() == 31);
    ASSERT_TRUE(one.front() == 7);
    ASSERT_TRUE(one[0] == 7);
    ASSERT_TRUE(one.back() == 3);
    one.pop_front();
    one.resize(32, -2);
    ASSERT_TRUE(one.size() == 32);
    ASSERT_TRUE(one[29] == 3);
    ASSERT_TRUE(one[30] == -2);
    ASSERT_TRUE(one[31] == -2);
    ASSERT_TRUE(one.back() == -2);
    one.resize(5, 0);
    ASSERT_TRUE(one.size() == 5);
    ASSERT_TRUE(one.front() == 3);
    ASSERT_TRUE(one.back() == 3);
}

TEST(vector_range_based) {
    vector<int> two;
    two.resize(20, 2);
    ASSERT_TRUE(two.size() == 20);
    ASSERT_TRUE(two.back() == 2);
    ASSERT_TRUE(two[19] == 2);
    
    vector<int> one;
    one.reserve(15);
    ASSERT_TRUE(one.empty());
    for (int i = 0; i < 14; ++i) {
        one.push_back(i);
    }
    ASSERT_TRUE(one.size() == 14);
    ASSERT_TRUE(one.back() == 13);
    ASSERT_TRUE(one.front() == 0);
    
    vector<int> three(one.begin(), one.size());
    ASSERT_TRUE(three.size() == 14);
    ASSERT_TRUE(three[0] == 0);
    ASSERT_TRUE(three[13] == 13);
}

TEST(vector_copy_assignment) {
    vector<int> one;
    one.push_back(2);
    one.push_back(3);
    one.push_back(5);
    vector<int> two(one);
    ASSERT_TRUE(two.size() == 3);
    ASSERT_TRUE(two[0] == 2);
    ASSERT_TRUE(two[1] == 3);
    ASSERT_TRUE(two[2] == 5);
    
    two.pop_back();
    two = one;
    ASSERT_TRUE(two[0] == 2);
    ASSERT_TRUE(two[1] == 3);
    ASSERT_TRUE(two[2] == 5);
    two = two;
    ASSERT_TRUE(two[0] == 2);
    ASSERT_TRUE(two[1] == 3);
    ASSERT_TRUE(two[2] == 5);
}

TEST(stack_default) {
    stack<int> one;
    ASSERT_TRUE(one.empty());
    ASSERT_TRUE(one.size() == 0);
    one.push(7);
    ASSERT_TRUE(one.top() == 7);
    one.push(3);
    ASSERT_TRUE(one.top() == 3);
    ASSERT_TRUE(one.size() == 2);
    one.push(5);
    ASSERT_TRUE(one.size() == 3);
    one.pop();
    one.pop();
    ASSERT_TRUE(one.top() == 7);
    one.pop();
    ASSERT_TRUE(one.empty());
}

TEST(list_default) {
    list<int> one;
    ASSERT_TRUE(one.empty());
    one.push_front(3);
    ASSERT_TRUE(one[0] == 3);
    ASSERT_TRUE(one.front() == 3);
    one.push_front(4);
    ASSERT_TRUE(one[0] == 4);
    ASSERT_TRUE(one[1] == 3);
    ASSERT_TRUE(one.size() == 2);
    ASSERT_TRUE(one.find(4));
    ASSERT_TRUE(one.remove(4));
    ASSERT_FALSE(one.remove(4));
    ASSERT_FALSE(one.find(4));
    one.pop_front();
    ASSERT_TRUE(one.size() == 0);
    for (int i = 0; i < 15; ++i) {
        one.push_front(i);
    }
    ASSERT_TRUE(one.size() == 15);
    ASSERT_TRUE(one.remove(7));
    ASSERT_TRUE(one.size() == 14);
    one.clear();
    ASSERT_TRUE(one.empty());
}

TEST(unorderedmap) {
    unordered_map<int, char> map(100);
    map[3] = 'c';
    map[0] = 'a';
    ASSERT_FALSE(map.insert(0, 'a'));
    ASSERT_FALSE(map.erase(2));
    ASSERT_TRUE(map.erase(0));
}

TEST_MAIN()
