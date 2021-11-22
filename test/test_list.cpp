#include <iostream>
#include "../list.h"

#include <gtest/gtest.h>
 
//- вставка элементов в конец
TEST(Vector, Vector_push_back) {
    list<int> list;
    ASSERT_EQ ((list.size_() == 0 ), 1 );

    for (int i = 0; i<10; i++) list.push_back(i);
    ASSERT_EQ ((list.size_() == 10 ), 1 );
}

/// вставка элементов в начало
TEST(Vector, Vector_push_frond) {
    list<int> list;
    for (int i = 0; i<10; i++) list.push_back(i);

    list.push_frond(10);
    ASSERT_EQ ((list[0]->val== 10 &&  list[1]->val== 0), 1 );
  
}
 
//вставка элементов в середину
TEST(Vector, Insert_level) {

   list<int> list;
    for (int i = 0; i<10; i++) list.push_back(i);
    list.insert(20);

    ASSERT_EQ ((list[5]->val== 20 ), 1 );
}
 
//удаление элементов из конца
TEST(Vector, Vector_pop_back) {

    list<int> list;
    for (int i = 0; i<10; i++) list.push_back(i);
    list.remove_last();
   
    list.remove_last();
  
    list.remove_last();
    ASSERT_EQ ((list[6]->val== 6 && list.size_() == 7), 1 );
    
}
 
//удаление элементов из начала 
TEST(Vector, Vector_pop_begin) {

    list<int> list;
    for (int i = 0; i<10; i++) list.push_back(i);

    list.remove_first();
 
    ASSERT_EQ (((list[0]->val == 1)&& (list[1]->val == 2)&& list.size_() == 9), 1 );
    
}

//удаление элементов из середины
TEST(Vector, Vector_erase) {

    list<int> list;
    for (int i = 0; i<10; i++) list.push_back(i);

    list.insert(20);

    ASSERT_EQ ((list[5]->val == 20), 1 );
    
}

//размер 
TEST(Vector, Vector_size) {

    list<int> list;
    ASSERT_EQ (list.size_(), 0 );
    for (int i = 0; i<10; i++) list.push_back(i);

    ASSERT_EQ (list.size_(), 10 );
    
}

//PRINT 
TEST(Vector, Vector_print) {

    list<int> list;
    ASSERT_EQ (list.size_(), 0 );
    ASSERT_STREQ ( list.print().c_str(), "");
    for (int i = 0; i<10; i++) list.push_back(i);
    ASSERT_STREQ ( list.print().c_str(),  "0123456789");
    list.push_back(10);
     ASSERT_STREQ ( list.print().c_str(),  "012345678910");
    
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}