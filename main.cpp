#include <iostream> 
#include "vector.h"
#include "list.h"
using namespace std;


int main(){

  std ::cout << "Vector" << std::endl;
  vectorClass<int> Vector;

 for (int i = 0; i<10; i++) Vector.push_back(i);
  //Vector.print();

  cout << "Размер " << Vector.size() << std::endl;

  //0, 1, 3, 5, 7, 8, 9 
  Vector.erase(3);
 Vector.erase(5);
Vector.erase(7);
 // Vector.print();

  Vector.insert(0,10);
 // Vector.print();

  Vector.insert_medium(20);
 // Vector.print();

  Vector.push_back(30);
 // Vector.print();

  std ::cout << std::endl << std::endl;

  std ::cout << "List" << std::endl;

  list<int> l;
 
  for (int value = 0; value <10; value++){
    l.push_back(value);
  }
  if(l.is_empty())
    std::cout << "The List is_empty " << std::endl;
  l.print();

  cout << "Размер " << l.size_print() << endl; 
 
  for (int i=2; i<=6; i=i+2 ){
    int val = l[i]->val;
    l.erase(val);
  }
    l.print();

    l.push_frond(10);
    l.print();

    l.insert(20);
    l.print();

    l.push_back(30);
    l.print();
    return 0;

} 