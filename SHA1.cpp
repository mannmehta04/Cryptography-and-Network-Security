#include<iostream>
#include<iomanip>
#include<string>
#include<cstdint>
#define SHA1_ROTL(bits,word) (((word) << (bits)) | ((word) >> (32 - (bits))))

using namespace std;
const uint32_t K[]={
    0x5A827999,
    0x6ED9EBA1,
    0x8F1BBCDC,
    0xCA62C1D6
};

#define SHA1_CH(x,y,z) (((x)&(y)) ^ (~(x)&(z)))
#define SHA1_PARITY(x,y,z) ((x)^(y)^(z))
#define SHA1_MAJ(x,y,z) (((x)& (y)) ^ ((x)& (z)) ^ ((y) & (z)))

uint32_t H[]={
    0x67452301,
    0xEFCDAB89,
    0x98BADCFE,
    0x10325476,
    0xC32E1F0
};

std::string padMessage(const std::string &message){
    uint64_t m1=message.length()*8;
    std::string paddedMessage = message + static_cast<char>(0x80);

    while((paddedMessage.length()*8)%512 != 448){
        paddedMessage +=static_cast<char>(0x00);
    }
    for(int i=56;i>=0;i-=8){
        paddedMessage+=static_cast<char>((m1 >> i)& 0xFF);
    }
    return paddedMessage;
}
std::string sha1(const std::string &message){
    std::string paddedMessage=padMessage(message);
    int blocks=paddedMessage.length()/64;

    for(int i=0;i<blocks;i++)
    {
        const char *block= paddedMessage.c_str()+i*64;
        uint32_t W[16];
        for(int j=0;j<16;j++)
        {
            W[j]=(block[j*4]<<24) | (block[j*4+1]<<16) | (block[j*4+2]<<8) | block[j*4+3];
        }

        uint32_t A=H[0];
        uint32_t B=H[1];
        uint32_t C=H[2];
        uint32_t D=H[3];
        uint32_t E=H[4];

        for(int round=0;round<80;round++)
        {
            uint32_t temp=SHA1_ROTL(5,A) + SHA1_CH(B,C,D)+ E+ K[round]+W[round/4];
            E=D;
            D=C;
            C=SHA1_ROTL(30,B);
            B=A;
            A=temp;
        }
        H[0]+=A;
        H[1]+=B;
        H[2]+=C;
        H[3]+=D;
        H[4]+=E;

    }
    std::string hashResult;
    for(int i=0;i<5;i++)
    {
        hashResult+= static_cast<char>((H[i]>>24)&0xFF);
        hashResult+= static_cast<char>((H[i]>>16)&0xFF);
        hashResult+= static_cast<char>((H[i]>>8)&0xFF);
        hashResult+= static_cast<char>((H[i])&0xFF);
    }
    return hashResult;
}

int main()
{
    std::string message="tinu";
    std::string hash=sha1(message);

    std::cout<<"Message: "<<message<<std::endl;
    std::cout<<"SHA-1 Hash: ";
    for(char c:hash){
        std::cout<<std::hex<<std::setw(2)<<std::setfill('0')<<static_cast<int>(c);
    }
    std::cout<<std::dec<<std::endl;
    return 0;
}
