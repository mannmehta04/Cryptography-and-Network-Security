#include<iostream>
#include<math.h>
using namespace std;

class railFence{
    string text, ans;
    int depth;

    public:

    railFence(){
        depth=0;
        text="";
    }

    railFence(int depth, string text){
        this->depth = depth;
        this->text = text;
    }

    void railFenceAlgo(int method){

        if(method){     // 1: encrypt 0: decrypt
            for(int i=0; i<text.length();i+=2){
                ans.push_back(text[i]);
            }
            for(int j=1;j<text.length();j+=2){
                ans.push_back(text[j]);
            }
        }

        else{
            int textLength = text.length();
			string plainText(textLength, ' ');

			int cycleLength = 2 * depth - 2;
			int index = 0;

			for (int row = 0; row < depth; ++row) {
				int step1 = cycleLength - 2 * row;
				int step2 = 2 * row;

				int i = row;
				bool isStep1 = true;

				while (i < textLength) {
					plainText[i] = text[index++];
					if (step1 > 0 && step2 > 0) {
						if (isStep1) i += step1;
						else i += step2;
						isStep1 = !isStep1;
					} else if (step1 > 0) {
						i += step1;
					} else {
						i += step2;
					}
				}
			}
			ans=plainText;
        }
    }

    void display(){
        cout<<"Plain Text: "<<text<<endl;
        cout<<"Cipher Text: "<<ans;
    }
};

int main(){

    railFence r1(2, "hello");
    r1.railFenceAlgo(1);

    // railFence r1(2, "hloel");
    // r1.railFenceAlgo(0);
    
    r1.display();

    return 0;
}