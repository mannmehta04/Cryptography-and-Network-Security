#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
class Playfair{
	public:
		string genrateKeys(string yKey){
			string  atoz,userKey;
			for(char c='a';c<='z';c++){
				atoz+=c;
			} 
			for(auto c:yKey){
				if(userKey.back() !=  c)
					userKey += c;
			}	
			for(auto c:userKey){
				atoz.erase(remove(atoz.begin(), atoz.end(), c), atoz.end());
			}
			atoz.erase(remove(atoz.begin(), atoz.end(), 'j'), atoz.end());
			return userKey+atoz;
		}
		vector<vector<char>> displayTable(string newKeys){
			cout<<"Key Table"<<endl;
			vector<vector<char>> vc(5);
			for(int i=0;i<5;i++){
				for(int j=0;j<5;j++){
					vc[i].push_back(newKeys[(i*5)+j]);
					cout<<vc[i][j]<<" ";
				}	
				cout<<endl;
			}
			return vc;
		}
		string plainText(string text){
			string textSet;
			for(auto c:text){
				if(textSet.back() != c)
					textSet += c;
				else {
					textSet += 'x';
					textSet += c;
				}		
			}
			cout<<endl<<"Plain Text: "<<"  ";
			if(textSet.size()%2!=0)
				textSet += 'x';
			cout<<textSet<<endl;
			return textSet;
		}
		string cipherText(string text,string keyRef,vector<vector<char>> vc,int d){
			string temp;
			for(int i=0;i<text.size();i+=2){
				if(keyRef.find(text[i+1])%5 == keyRef.find(text[i])%5){
					temp+=vc[((keyRef.find(text[i])/5)+d)%5][keyRef.find(text[i+1])%5];
					temp+=vc[((keyRef.find(text[i+1])/5)+d)%5][keyRef.find(text[i])%5];
				}
				else if(keyRef.find(text[i])/5 == keyRef.find(text[i+1])/5){
					temp+=vc[keyRef.find(text[i])/5][(keyRef.find(text[i])+d)%5];
					temp+=vc[keyRef.find(text[i+1])/5][(keyRef.find(text[i]+d)+1)%5];
				}
				else{
					temp+=vc[keyRef.find(text[i])/5][keyRef.find(text[i+1])%5];
					temp+=vc[keyRef.find(text[i+1])/5][keyRef.find(text[i])%5];
				}
			}
			return temp;
		}
};
int main(){
	Playfair pf;
	
	string keyRef = pf.genrateKeys("monarchy"),cText,pText;
	
	vector<vector<char>> vc = pf.displayTable(keyRef);
	
	cText= pf.cipherText(pf.plainText("instruments"),keyRef,vc,1); //1: Encrypt -1: decrypt
	cout<<endl<<"Cipher Text : "<<cText;
	
	pText = pf.cipherText(cText,keyRef,vc,-1);
	cout<<endl<<"Plain Text : "<<pText;		
}
