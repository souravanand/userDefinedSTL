#include<iostream>
#include<list>
using namespace std;

class HashMap{
    private:
    static const int hashgroupsize=10;
    list<pair<int,string>>table[hashgroupsize];

    public:
    bool isEmpty()const;
    int gethash(int key);
    void insert(int key,string val);
    void remove(int key);
    string searchTable(int key);
    void printTable();    
};

string HashMap::searchTable(int key)
{
    int hashkey=gethash(key);
    auto& cell=table[hashkey];

    for(auto it:cell)
    {
        if(it.first==key)
        {
            cout<<"Key "<<key<<" present !!! Value is "<<it.second;
            return it.second;

        }
    }
    string res="No Key found\n";
    cout<<res;
    return res;
}

bool HashMap::isEmpty() const
{
    
    for(int i=0;i<hashgroupsize;i++)
    {
        if(table[i].size()>1)
        {
            return false;
        }
    }
    return true;

}

int HashMap::gethash(int key)
{
    return key %hashgroupsize;
}

void HashMap::insert(int key,string val)
{
    int hashkey=gethash(key);
    auto &temp=table[hashkey];

   for(auto it:temp)
   {
       if(it.first==key)
       {
           cout<<"WARNING!!!! Key "<<key<<" Found ,replacing Old value "<<it.second<<" with "<<val<<endl;
           it.second=val;
           return;
       }
   }
   temp.push_back({key,val});
}

void HashMap::remove(int key)
{
    int hashkey=gethash(key);

    auto& cell=table[hashkey];

    for(auto it=cell.begin();it!=cell.end();it++)
    {
        if(it->first==key)
        {
            cout<<"Erased key"<<key<<endl;
            cell.erase(it);
            return;
        }
        
    }
    cout<<"No key to remove"<<endl;
}

void HashMap::printTable()
{
    for(int i=0;i<hashgroupsize;i++)
    {
        auto& cell=table[i];

        for(auto it:cell)
        {
            cout<<"key "<<it.first<<" value "<<it.second<<endl;
        }
    }
}

int main()
{
    HashMap HT;
     HT.insert(10,"abc");
     HT.insert(22,"ram");
      HT.insert(14,"abc");
     HT.insert(24,"ram");
      HT.insert(16,"abc");
     HT.insert(22,"rrrtgg");
      HT.insert(17,"abc");
     HT.insert(24,"shyam");
    HT.printTable();
    HT.remove(133);
    HT.remove(24);
    HT.printTable();
    HT.searchTable(22);
    HT.searchTable(4444);
}
