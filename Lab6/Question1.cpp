#include<bits/stdc++.h>
#define here cout<<"Here"<<endl 
using namespace std;
vector<int> v(15,INT_MAX);


class HashTable{
    public:
    int Key;
    HashTable(int key){
        this->Key = key;
        v.clear();
        v.resize(Key,INT_MAX);
    }

    bool check(int n){
        int key = Key;
        int k = n%key;
        if(v[k]==n){
            return true;
        }
        else{
            int tempK = k;
            while(v[++k]!=INT_MAX){
                if(k==key) k=0;
                if(k==tempK) return false;
                if(v[k]==n) return true;
            }
            return false;
        }

        return false;
    }

    void insert(int n){
        bool flag = false;
        int k = n%Key;
        if(v[k]==INT_MAX){
            v[k]=n;
        }
        else{
            int tempK = k;
            while(v[++k]!=INT_MAX){
                if(k==Key) k=0;
                if(k==tempK){
                    flag = true;
                    cout<<"Hash Table is Full";
                    break;
                }
            }
            if(!flag) v[k] = n;
        }
        if(flag){
            cout<<"Hash Table is  Full"<<endl;
            return;
        }        
    }
    
};



int main(){
   
    HashTable obj1(17);
    obj1.insert(133);
    obj1.insert(88);
    obj1.insert(92);
    obj1.insert(221);
    obj1.insert(174);
    if(obj1.check(133)) cout<<133<<" is present."<<endl;
    else cout<<"133 is not Found"<<endl;
    if(obj1.check(100)) cout<<100<<" is present."<<endl;
    else cout<<"100 is not Found"<<endl;
    if(obj1.check(174)) cout<<174<<" is present."<<endl;
    else cout<<"174 is not Found"<<endl;

    HashTable obj2(37);
    obj2.insert(133);
    obj2.insert(88);
    obj2.insert(92);
    obj2.insert(221);
    obj2.insert(174);
    if(obj2.check(133)) cout<<133<<" is present."<<endl;
    else cout<<"133 is not Found"<<endl;
    if(obj2.check(100)) cout<<100<<" is present."<<endl;
    else cout<<"100 is not Found"<<endl;
    if(obj2.check(174)) cout<<174<<" is present."<<endl;
    else cout<<"174 is not Found"<<endl;

    return 0;
}
