#include<iostream>

using namespace std;


static int round1_key[8],round2_key[8];

void p10(int key[])
{
	int out[10]={3,5,2,7,4,10,1,9,8,6};
	int temp[10];

	for(int i=0;i<10;i++)
		temp[i]=key[i];
	for(int i=0;i<10;i++)
	{
		key[i]=temp[out[i]-1];
	}

}

void p8(int key[])
{
	int out[8]={6,3,7,4,8,5,10,9};
	int temp[10];

	for(int i=0;i<10;i++)
		temp[i]=key[i];

	for(int i=0;i<8;i++)
	{
		key[i]=temp[out[i]-1];
	}

}

void p4(int s0s1[])
{
	int out[4]={2,4,3,1};
	int temp[4];

	for(int i=0;i<4;i++)
		temp[i]=s0s1[i];

	for(int i=0;i<4;i++)
	{
		s0s1[i]=temp[out[i]-1];
	}

}

void left_shift(int left_half[], int right_half[], int shift_count)
{
	int temp1=left_half[0];
	int temp2=right_half[0];

	for(int i=0;i<4;i++)
	{
		left_half[i]=left_half[i+1];
		right_half[i]=right_half[i+1];
	}
	left_half[4]=temp1;
	right_half[4]=temp2;

	if(shift_count==2)
		left_shift(left_half,right_half,1);

}

int* generate_key(int key[],int round)
{
	int left_half[5],right_half[5];
	static int key1[10],key2[8];
	p10(key);
	for(int i=0;i<10;i++)
	{
		if(i<5)
		{
			left_half[i]=key[i];
		}
		else
		{
			right_half[i-5]=key[i];
		}
	}

	left_shift(left_half,right_half,1);

	for(int i=0;i<5;i++)
	{
		key1[i]=left_half[i];
		key1[i+5]=right_half[i];
	}
	if(round==1)
	{
		p8(key1);
		return key1;
	}
	else
	{
		left_shift(left_half,right_half,2);
		for(int i=0;i<5;i++)
		{
			key2[i]=left_half[i];
			key2[i+5]=right_half[i];
		}
		p8(key2);
		return key2;
	}
}


void initial_permutation(int pt[])
{

	int out[8]={2,6,3,1,4,8,5,7};
	int temp[8];

	for(int i=0;i<8;i++)
		temp[i]=pt[i];

	for(int i=0;i<8;i++)
	{
		pt[i]=temp[out[i]-1];
		//cout<<pt[i]<<"\t";
	}
}


void inverse_initial_permutation(int pt[])
{

	int out[8]={2,6,3,1,4,8,5,7};
	int temp[8];

	for(int i=0;i<8;i++)
		temp[i]=pt[i];

	for(int i=0;i<8;i++)
	{
		pt[out[i]-1]=temp[i];
	}
}

int main() {
    int plaintext[8] = {1, 0, 1, 0, 0, 0, 1, 1}; // Replace with your plaintext
    int initial_key[10] = {1, 0, 0, 0, 1, 0, 0, 1, 1, 1}; // Replace with your initial key

    int* round1_key_ptr = generate_key(initial_key, 1);
    for (int i = 0; i < 8; i++) {
        round1_key[i] = round1_key_ptr[i];
    }

    int* round2_key_ptr = generate_key(initial_key, 2);
    for (int i = 0; i < 8; i++) {
        round2_key[i] = round2_key_ptr[i];
    }

    initial_permutation(plaintext);

    // Implement the rest of your encryption/decryption logic here

    return 0;
}
