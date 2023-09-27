#include <iostream>
#include <string>
using namespace std;

class caesar {
    int key, choice;
    // string plainText = "", cipherText = "";

    public:
    caesar() {
        while(true){
            cout<<"\nSelect your Choice:";
            cout<<"\n1. Encryption";
            cout<<"\n2. Decryption";
            cout<<"\n3. Exit"<<endl<<endl;
            cin>>choice;

            switch(choice){
                case 1:
					cout << "\nEnter your Key: ";
            		cin >> key;
                    encrypt();
                    break;
                case 2:
					cout << "\nEnter your Key: ";
            		cin >> key;
                    decrypt();
                    break;
                case 3:
                    exit(0);
                default:
                    cout<<"\nError";
            }
        }
    }

    void encrypt() {
		string plainText = "", cipherText = "";
        cout << "\nEnter your Message to encrypt: ";
        cin>>plainText;

        for (int i = 0; i < plainText.length(); i++) {
            if (isupper(plainText[i])) {
                cipherText += char(int(plainText[i] + key - 65 + 26) % 26 + 65);
            } else {
                cipherText += char(int(plainText[i] + key - 97 + 26) % 26 + 97);
            }
        }

        cout << "Encrypted Message: " << cipherText << endl;
    }

    void decrypt() {
		string plainText = "", cipherText = "";
        cout << "\nEnter your Message to Decrypt: ";
        cin>>cipherText;

        for (int i = 0; i < cipherText.length(); i++) {
            if (isupper(cipherText[i])) {
                plainText += char(int(cipherText[i] - key - 65 + 26) % 26 + 65);
            } else {
                plainText += char(int(cipherText[i] - key - 97 + 26) % 26 + 97);
            }
        }

        cout << "Decrypted Message: "<< plainText << endl;
    }
};

int main() {
    caesar c1;

    return 0;
}