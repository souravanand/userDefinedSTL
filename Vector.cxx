#include<iostream>
using namespace std;

template<typename T>
class Vector{

    private:
    T *array;
    int current_size;
    int total_capacity;

    public:
    Vector():array(new T[1]),current_size(0),total_capacity(1){}
    typedef T* Iterator;
    void push_back(T data);
    void pop_back();
    void print();
    int getSize();
    int getCapacity();
    Iterator begin();
    Iterator end();
    T& operator[](int);
    
};

template<typename T>
void Vector<T>::push_back(T data)
{
    if(current_size==total_capacity)
    {
        T* temp = new T[2*total_capacity];
        for(int i=0;i<current_size;i++)
        {
            temp[i]=array[i];
        }
        delete[] array;
        total_capacity = 2*total_capacity;
        array=temp;
    }
    array[current_size++]=data;
}

template<typename T>
void Vector<T>::pop_back()
{
    current_size--;
}

template<typename T>
void Vector<T>::print()
{
    for(int i=0;i<current_size;i++)
    {
        cout<<array[i]<<" ";
    }
}

template<typename T>
int Vector<T>::getCapacity()
{
    return total_capacity;
}

template<typename T>
int Vector<T>::getSize()
{
    return current_size;
}

template<typename T>

T& Vector<T>::operator[](int index)
{
    return array[index];
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::begin()
{
    return array;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::end()
{
    return array+current_size;
}

int main()
{
    Vector <int>v;
    for(int i=10;i<=20;i++)
    {
        v.push_back(i);
    }

    v.print();
    
    cout<<"total Capacity "<<v.getCapacity()<<endl;
    cout<<"Total Size "<<v.getSize()<<endl;

    v.pop_back();
    v.pop_back();
    v.print();
    Vector<string>v1;
    v1.push_back("ram");
    v1.push_back("sam");
    v1.push_back("tam");
    v1.push_back("zam");
    
    for(auto it =v1.begin();it!=v1.end();it++)
    {
        cout<<*it<<endl;
    }

    cout<<v[2]<<endl;
   
}
