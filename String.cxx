#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class String{
    private:
    int len;
    char* buffer;

    void clean_up()
    {
        if(buffer!=nullptr)
        {
            delete[] buffer;
        }
        len=0;
    }
    public:
    String():len(0),buffer(nullptr){cout<<"default constructor called"<<endl;}//no resource is given to buffer , hence nullptr

    String(const char* data)//we passed constant character 
    {
        cout<<"paramaterized constructor called "<<endl;
        len=strlen(data);
        buffer=new char[len+1];
        memcpy(buffer,data,len+1);
    }

    String(String const &obj)//string s2=s1, here s1 will be coming to obj,while accessing obj we don't  want to accidently change the resource.
                             //& -: pass by reference,if we don;t use &, then copy contructor signature will be called and then it call again call a copy constrcutor and so on..
    {
        
        len=obj.len;
        buffer=new char[len+1];
        memcpy(buffer,obj.buffer,len+1);
         cout<<"copy constructor called  "<<endl;
    }
    String& operator=(String const &obj)
    {
        clean_up();
        len=obj.len;
        buffer= new char[len+1];
        memcpy(buffer,obj.buffer,len+1);
                 cout<<"Copy Assignment called"<<endl;

        return *this;
    }


    String(String &&obj)
    {
        cout<<"move constructor called "<<endl;
        len=obj.len;
        buffer=obj.buffer;
        obj.buffer=nullptr;
        obj.len=0;
         
    }

    String& operator=(String &&obj)
    {
        clean_up();
        len=obj.len;
        buffer=obj.buffer;
        obj.buffer=nullptr;
        obj.len=0;
         cout<<"moved assignment called "<<endl;
        return *this;

    }
    friend ostream& operator<<(ostream& out,String& str);
    friend istream& operator>>(istream& im,String& str);
    ~String()
    {
        clean_up();
        cout<<"Destructor called"<<endl;
    }
   
};

ostream& operator<<(ostream& out,String& str)//String s1="abcd";String s2;s2=s1 -here s2 was calling operator= function and s2 was going as parameter. so if we use cout<<s2=>cout will 
                                             //call << and s2 will be parameter , but we can't do becz cout is c++ library,if we do it as global , cout and s3 will go as parameter 
{
    out<<str.buffer<<endl;
    return out;
}
istream& operator>>(istream& in,String& str)
{
    in>>str.buffer;
    return in;
}
int main()
{ 
    String v;//Default constructor
    String s("sourav");//Parametrized constructor
    String s1=s;//copy constructor
    String s2;//default
    s2=s1;//copy assignment 

    String s3;
    s3="rohan";//move constructor

    String S4=std::move(s3);//move constructor

    String s5="ram";
    s5=std::move(s5);//move assignment
    
}
