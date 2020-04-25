#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define Nb 4

int NumberOfRounds=10;

int BitsInKey=4;


unsigned char in[16], out[16], state[4][4],aaaa[4];

unsigned char RoundKey[240];

unsigned char Key[32];
unsigned char box[256] =   {
	0x00 , 0x01 , 0x02 , 0x03 , 0x04 , 0x05 , 0x06 , 0x07 , 0x08 , 0x09 , 0x0a , 0x0b , 0x0c , 0x0d , 0x0e , 0x0f , 
	0x10 , 0x11 , 0x12 , 0x13 , 0x14 , 0x15 , 0x16 , 0x17 , 0x18 , 0x19 , 0x1a , 0x1b , 0x1c , 0x1d , 0x1e , 0x1f , 
	0x20 , 0x21 , 0x22 , 0x23 , 0x24 , 0x25 , 0x26 , 0x27 , 0x28 , 0x29 , 0x2a , 0x2b , 0x2c , 0x2d , 0x2e , 0x2f , 
	0x30 , 0x31 , 0x32 , 0x33 , 0x34 , 0x35 , 0x36 , 0x37 , 0x38 , 0x39 , 0x3a , 0x3b , 0x3c , 0x3d , 0x3e , 0x3f , 
	0x40 , 0x41 , 0x42 , 0x43 , 0x44 , 0x45 , 0x46 , 0x47 , 0x48 , 0x49 , 0x4a , 0x4b , 0x4c , 0x4d , 0x4e , 0x4f , 
	0x50 , 0x51 , 0x52 , 0x53 , 0x54 , 0x55 , 0x56 , 0x57 , 0x58 , 0x59 , 0x5a , 0x5b , 0x5c , 0x5d , 0x5e , 0x5f , 
	0x60 , 0x61 , 0x62 , 0x63 , 0x64 , 0x65 , 0x66 , 0x67 , 0x68 , 0x69 , 0x6a , 0x6b , 0x6c , 0x6d , 0x6e , 0x6f , 
	0x70 , 0x71 , 0x72 , 0x73 , 0x74 , 0x75 , 0x76 , 0x77 , 0x78 , 0x79 , 0x7a , 0x7b , 0x7c , 0x7d , 0x7e , 0x7f , 
	0x80 , 0x81 , 0x82 , 0x83 , 0x84 , 0x85 , 0x86 , 0x87 , 0x88 , 0x89 , 0x8a , 0x8b , 0x8c , 0x8d , 0x8e , 0x8f , 
	0x90 , 0x91 , 0x92 , 0x93 , 0x94 , 0x95 , 0x96 , 0x97 , 0x98 , 0x99 , 0x9a , 0x9b , 0x9c , 0x9d , 0x9e , 0x9f , 
	0xa0 , 0xa1 , 0xa2 , 0xa3 , 0xa4 , 0xa5 , 0xa6 , 0xa7 , 0xa8 , 0xa9 , 0xaa , 0xab , 0xac , 0xad , 0xae , 0xaf , 
	0xb0 , 0xb1 , 0xb2 , 0xb3 , 0xb4 , 0xb5 , 0xb6 , 0xb7 , 0xb8 , 0xb9 , 0xba , 0xbb , 0xbc , 0xbd , 0xbe , 0xbf , 
	0xc0 , 0xc1 , 0xc2 , 0xc3 , 0xc4 , 0xc5 , 0xc6 , 0xc7 , 0xc8 , 0xc9 , 0xca , 0xcb , 0xcc , 0xcd , 0xce , 0xcf , 
	0xd0 , 0xd1 , 0xd2 , 0xd3 , 0xd4 , 0xd5 , 0xd6 , 0xd7 , 0xd8 , 0xd9 , 0xda , 0xdb , 0xdc , 0xdd , 0xde , 0xdf , 
	0xe0 , 0xe1 , 0xe2 , 0xe3 , 0xe4 , 0xe5 , 0xe6 , 0xe7 , 0xe8 , 0xe9 , 0xea , 0xeb , 0xec , 0xed , 0xee , 0xef , 
	0xf0 , 0xf1 , 0xf2 , 0xf3 , 0xf4 , 0xf5 , 0xf6 , 0xf7 , 0xf8 , 0xf9 , 0xfa , 0xfb , 0xfc , 0xfd , 0xfe , 0xff
	 };
int getSBoxValue(int num)
{
	int sbox[256] =   {
	//0     1    2      3     4    5     6     7      8    9     A      B    C     D     E     F
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76, //0
	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, //1
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15, //2
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75, //3
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84, //4
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf, //5
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8, //6
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2, //7
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73, //8
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb, //9
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79, //A
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08, //B
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a, //C
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e, //D
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf, //E
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 }; //F
	return sbox[num];
}

int Rcon[255] = {
	0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 
	0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 
	0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 
	0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 
	0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 
	0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 
	0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 
	0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 
	0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 
	0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 
	0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 
	0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 
	0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 
	0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 
	0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 
	0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb  };

void ExpandKey()
{
	int i,j;
	unsigned char temp[4],k;
	
	for(i=0;i<BitsInKey;i++)
	{
		RoundKey[i*4]=Key[i*4];
		RoundKey[i*4+1]=Key[i*4+1];
		RoundKey[i*4+2]=Key[i*4+2];
		RoundKey[i*4+3]=Key[i*4+3];
	}

	while (i < (Nb * (NumberOfRounds+1)))
	{
					for(j=0;j<4;j++)
					{
						temp[j]=RoundKey[(i-1) * 4 + j];
					}
					if (i % BitsInKey == 0)
					{
						
						{
							k = temp[0];
							temp[0] = temp[1];
							temp[1] = temp[2];
							temp[2] = temp[3];
							temp[3] = k;
						}

						
						{
							temp[0]=getSBoxValue(temp[0]);
							temp[1]=getSBoxValue(temp[1]);
							temp[2]=getSBoxValue(temp[2]);
							temp[3]=getSBoxValue(temp[3]);
						}

						temp[0] =  temp[0] ^ Rcon[i/BitsInKey];
					}
					else if (BitsInKey > 6 && i % BitsInKey == 4)
					{
						{
							temp[0]=getSBoxValue(temp[0]);
							temp[1]=getSBoxValue(temp[1]);
							temp[2]=getSBoxValue(temp[2]);
							temp[3]=getSBoxValue(temp[3]);
						}
					}
					RoundKey[i*4+0] = RoundKey[(i-BitsInKey)*4+0] ^ temp[0];
					RoundKey[i*4+1] = RoundKey[(i-BitsInKey)*4+1] ^ temp[1];
					RoundKey[i*4+2] = RoundKey[(i-BitsInKey)*4+2] ^ temp[2];
					RoundKey[i*4+3] = RoundKey[(i-BitsInKey)*4+3] ^ temp[3];
					i++;
	}
}
void printt(int round,int i,int j){
	if(RoundKey[round * Nb * 4 + i * Nb + j]==0x00)
		printf("00");
	else if(RoundKey[round * Nb * 4 + i * Nb + j]==0x01)
		printf("01");
	else if(RoundKey[round * Nb * 4 + i * Nb + j]==0x02)
		printf("02");
	else if(RoundKey[round * Nb * 4 + i * Nb + j]==0x03)
		printf("03");
	else if(RoundKey[round * Nb * 4 + i * Nb + j]==0x04)
		printf("04");
	else if(RoundKey[round * Nb * 4 + i * Nb + j]==0x05)
		printf("05");
	else if(RoundKey[round * Nb * 4 + i * Nb + j]==0x06)
		printf("06");
	else if(RoundKey[round * Nb * 4 + i * Nb + j]==0x07)
		printf("07");
	else if(RoundKey[round * Nb * 4 + i * Nb + j]==0x08)
		printf("08");
	else if(RoundKey[round * Nb * 4 + i * Nb + j]==0x09)
		printf("09");
	else if(RoundKey[round * Nb * 4 + i * Nb + j]==0x0A)
		printf("0A");
	else if(RoundKey[round * Nb * 4 + i * Nb + j]==0x0B)
		printf("0B");
	else if(RoundKey[round * Nb * 4 + i * Nb + j]==0x0C)
		printf("0C");
	else if(RoundKey[round * Nb * 4 + i * Nb + j]==0x0D)
		printf("0D");
	else if(RoundKey[round * Nb * 4 + i * Nb + j]==0x0E)
		printf("0E");
	else if(RoundKey[round * Nb * 4 + i * Nb + j]==0x0F)
		printf("0F");
	else
		printf("%X",RoundKey[round * Nb * 4 + i * Nb + j]);
	
}
void AddRoundKey(int round) 
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			state[j][i] ^= RoundKey[round * Nb * 4 + i * Nb + j];
			if(round!=0)
				printt(round,i,j);
		}
		// printf("\n");
	}
	if(round!=0)
		printf("\n");
}

void SubBytes()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			state[i][j] = getSBoxValue(state[i][j]);

		}
	}
}

void ShiftRowLeft()
{
	unsigned char temp;

	temp=state[1][0];
	state[1][0]=state[1][1];
	state[1][1]=state[1][2];
	state[1][2]=state[1][3];
	state[1][3]=temp;

	temp=state[2][0];
	state[2][0]=state[2][2];
	state[2][2]=temp;

	temp=state[2][1];
	state[2][1]=state[2][3];
	state[2][3]=temp;

	temp=state[3][0];
	state[3][0]=state[3][3];
	state[3][3]=state[3][2];
	state[3][2]=state[3][1];
	state[3][1]=temp;
}

#define xtime(X)   ((X<<1) ^ (((X>>7) & 1) * 0x1b))

void MixColumns()
{
	int i;
	unsigned char Tmp,Tm,t;
	for(i=0;i<4;i++)
	{	
		t=state[0][i];
		Tmp = state[0][i] ^ state[1][i] ^ state[2][i] ^ state[3][i] ;
		Tm = state[0][i] ^ state[1][i] ; Tm = xtime(Tm); state[0][i] ^= Tm ^ Tmp ;
		Tm = state[1][i] ^ state[2][i] ; Tm = xtime(Tm); state[1][i] ^= Tm ^ Tmp ;
		Tm = state[2][i] ^ state[3][i] ; Tm = xtime(Tm); state[2][i] ^= Tm ^ Tmp ;
		Tm = state[3][i] ^ t ; Tm = xtime(Tm); state[3][i] ^= Tm ^ Tmp ;
	}
}

void EncryptAES()
{
	int i,j,round=0;

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			state[j][i] = in[i*4 + j];
		}
	}

	AddRoundKey(0); 
	
	for(round=1;round<NumberOfRounds;round++)
	{
		SubBytes();
		ShiftRowLeft();
		MixColumns();
		AddRoundKey(round);
	}
	
	SubBytes();
	ShiftRowLeft();
	AddRoundKey(NumberOfRounds);


	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			out[i*4+j]=state[j][i];
		}
	}
}
int getValue(char c1){
	if(c1=='1')
		return 1;
	else if(c1=='0')
		return 0;
	else if(c1=='2')
		return 2;
	else if(c1=='3')
		return 3;
	else if(c1=='4')
		return 4;
	else if(c1=='5')
		return 5;
	else if(c1=='6')
		return 6;
	else if(c1=='7')
		return 7;
	else if(c1=='8')
		return 8;
	else if(c1=='9')
		return 9;
	else if(c1=='A')
		return 10;
	else if(c1=='B')
		return 11;
	else if(c1=='C')
		return 12;
	else if(c1=='D')
		return 13;
	else if(c1=='E')
		return 14;
	else if(c1=='F')
		return 15;
	else
		return -1;
}


int main()
{

	cin.sync(); 
	string plaintext,key;
	cin>>plaintext;
	cin>>key;
	for(int i=0;i<16;i++){
		char c1,c2,c3,c4;
		c1=plaintext[2*i];
		c2=plaintext[(2*i)+1];
		c3=key[2*i];
		c4=key[(2*i)+1];
		int pt=16*getValue(c1)+getValue(c2);
		in[i]=box[pt];
		int k=16*getValue(c3)+getValue(c4);
		Key[i]=box[k];
		
	}
	ExpandKey();

	EncryptAES();

	for(int i=0;i<BitsInKey*4;i++)
	{
		printf("%02X",out[i]);
	}
	return 0;
}