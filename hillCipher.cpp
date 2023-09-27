#include<iostream>
#include<vector>
using namespace std;

class hillCipher{

    int pt;

    vector<vector<int>> v1;

    public:

    void genKey(int key){
        
    }

    void display(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<v1[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};


int main(){
    int s1 = 214;
    int key = 123456789;

    hillCipher h1;

    h1.genKey(key);
    h1.display();    

    return 0;
}