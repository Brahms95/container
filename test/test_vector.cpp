#include <iostream>
#include "../vector.h"

#include <gtest/gtest.h>
 
//--------------------------------------------------------------------------------------------------------------------
// struct Vector : public testing::Test {
//    public:
 
//     static bool vector_test  ;
 
 
//     static void  SetUpTestSuite() {
   
//  std::vector<int> vector_test;
//     }
 
//     // Per-test-suite tear-down.
//     static void TearDownTestSuite() {
       
//     }
// };
 
//bool Vector::storageLoaded = false;
 
//- вставка элементов в конец
TEST(Vector, Vector_push_back) {
    vectorClass<int> Vector;
    for (int i = 0; i<10; i++) Vector.push_back(i);
 
   ASSERT_EQ ((Vector.size() == 10 ), 1 );
}
/// вставка элементов в начало
TEST(Vector, Vector_insert) {
    vectorClass<int> Vector;
    for (int i = 0; i<10; i++) Vector.push_back(i);

    Vector.insert(0,10);

    ASSERT_EQ ((Vector[0]== 10 && Vector[1]== 0  ), 1 );
}
 
//вставка элементов в середину
TEST(Vector, Insert_level) {

   vectorClass<int> Vector;
    for (int i = 0; i<10; i++) Vector.push_back(i);
    Vector.insert_medium(20);

    ASSERT_EQ ((Vector[5]== 20 ), 1 );
}
 
//удаление элементов из конца
TEST(Vector, Vector_pop_back) {

   vectorClass<int> Vector;
    for (int i = 0; i<10; i++) Vector.push_back(i);
   Vector.pop_back();
 
   ASSERT_EQ ((Vector[8]== 8), 1 );
    
}
 
//удаление элементов из начала 
TEST(Vector, Vector_pop_begin) {

    vectorClass<int> Vector;
    for (int i = 0; i<10; i++) Vector.push_back(i);

    Vector.pop_begin();
 
    ASSERT_EQ ((Vector[0]== 1), 1 );
    
}

//удаление элементов из середины
TEST(Vector, Vector_erase) {

    vectorClass<int> Vector;
    for (int i = 0; i<10; i++) Vector.push_back(i);

    Vector.erase(5);
 
    ASSERT_EQ ((Vector[4]== 5), 1 );
    
}

//размер 
TEST(Vector, Vector_size) {

    vectorClass<int> Vector;
    ASSERT_EQ (Vector.size_(), 0 );
    for (int i = 0; i<10; i++) Vector.push_back(i);

    ASSERT_EQ (Vector.size_(), 10 );
    
}

//PRINT 
TEST(Vector, Vector_print) {

    vectorClass<int> Vector;
    ASSERT_EQ (Vector.size_(), 0 );
    for (int i = 0; i<10; i++) Vector.push_back(i);
    ASSERT_STREQ ( Vector.print().c_str(),  "0123456789");
    Vector.push_back(10);
    ASSERT_STREQ ( Vector.print().c_str(),  "012345678910");
    
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}