#pragma once 

using namespace std;

template <typename T>
class vectorClass {

public:
    vectorClass(){}

    // Функция для добавления элемента в последний

    void push_back(T value){

        T* new_region = new T[m_size + 1]; // новая область памяти 
        for (size_t i = 0; i < m_size; ++i) { 
        new_region[i] = m_region[i]; // копирование элементов 
        } 
        new_region[m_size] = value; // добавление нового элемента 
        if (m_size !=0)
        delete [] m_region; // удаление старой области 
        m_region = new_region; // сохранение новой в мембер 
        m_size += 1; // обновление информации о размере 

    }
    void insert(int pos,T value){
        int index =0;
        T* new_region = new T[m_size + 1]; // новая область памяти 
    
        for (size_t i = 0; i <m_size; ++i) { 
            if  (i == pos) new_region[index] = value; // добавление нового элемента
        
            index++;
            new_region[index] = m_region[i]; // копирование элементов 
    } 
     
        delete [] m_region; // удаление старой области 
        m_region = new_region; // сохранение новой в мембер 
        m_size += 1; // обновление информации о размере 
    }

    void insert_medium(T value){
        int index =0;
        int pos = m_size/2;
        T* new_region = new T[m_size + 1]; // новая область памяти 
        
        for (size_t i = 0; i <m_size; ++i) { 
            if  (i == pos) new_region[index] = value; // добавление нового элемента
        
            index++;
            new_region[index] = m_region[i]; // копирование элементов 
        } 
        
        delete [] m_region; // удаление старой области 
        m_region = new_region; // сохранение новой в мембер 
        m_size += 1; // обновление информации о размере 
    }

    vectorClass& operator= (T* new_region)const {
        
    }
    T operator[] (T index) { return m_region[index]; }
     
    int size(){ return m_size; }
 
    void erase(int a){
        T* new_region = new T[m_size - 1];
        int index= 0;
        for (int i = 0; i<=m_size; i++) {
            if (i == a-1 )
                continue;
            
            new_region[index] = m_region[i]; 
            index++;
            }
              
        delete [] m_region; // удаление старой области 
        m_region = new_region; // сохранение новой в мембер 
        m_size -= 1; // обновление информации о размере 
    }
    void pop_begin (){
       T* new_region = new T[m_size - 1];
        int j =0;
        for (int i = 1; i<=m_size; i++, j++) {
            new_region[j] = m_region[i]; 
            }
              
        delete [] m_region; // удаление старой области 
        m_region = new_region; // сохранение новой в мембер 
        m_size -= 1; // обновление информации о размере  
    }

    void pop_back(){
          T* new_region = new T[m_size - 1];

        for (int i = 0; i<m_size; i++) {
            new_region[i] = m_region[i]; 
            }
              
        delete [] m_region; // удаление старой области 
        m_region = new_region; // сохранение новой в мембер 
        m_size -= 1; // обновление информации о размере  
    }
    std::string print(){
        std::string vector;
        for (T i = 0; i < m_size; i++) {
            vector.append(std::to_string(m_region[i]));
          //  cout << m_region[i]<< " ";
        }
        
       // cout << endl;
        return vector;
    }

    int size_(){
        return m_size;
    }

private:
T* m_region ;
int m_size = 0;

};
