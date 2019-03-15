#include <stdio.h>
#include <inttypes.h>

//char data[8] = {0,0,0,0,0,0,0,0,};

int a_is_in_b(/*uint64_t*/int a,uint64_t b,int vel_a,int vel_b)
{
	uint64_t mask = (1ULL<<vel_a)-1ULL;
	for (int i = 0; i < vel_b-vel_a+1; ++i)
	{
		//if( ( b & (a<<i) ) == (a<<i) )return 1;

		//if( ( (b & (mask<<i)) ^ (a<<i) ) == 0) return 1;

		//                        vvvvvvvv - nujno mora biti a cast-an v uint64_t
		if( ( (b & (mask<<i)) ^ ((uint64_t)a<<i) ) == 0ULL) return 1;
	}
	return 0;
}

//NAROBE za 5 bitov
//194eadf0
//0000011001010011101010110111110000

//za 5 bitov
//4653adf0
//000001000110010100111010110111110000
//000001000110010100111010110111110000
int main(int argc, char const *argv[])
{
	//char* cifra = data;
	int n=3;
	int velikost = 10;
	uint64_t cifra = 0; //ki jo iscemo in je velikost-bitna

	//printf("%i\n",sizeof(int));
	
	//printf("%i\n", a_is_in_b(0b101010,0b0000000001110000000000001111011111100000,6,40));
	//return 0;
	int count = 0;
	for (cifra = 0/*0b0111110000*//*1ULL<<32*/; cifra < 1ULL<<velikost; cifra++/*cifra += 0b10000000000ULL*/)
	{
		count = 0;
		for (int i = 0; i < 1<<n; ++i)
		{
			if( a_is_in_b(i,cifra,n,velikost) )
			count++;
		}
		if(count==(1<<n))
		{
			printf("%llx\n",cifra );
			//printf("%llx\n",*((unsigned long long*)((char*)&cifra+3)) );
			//if(cifra & 0b) break;
			//break;
		}
		
	}
	
	/*for (int i = 0; i < 1<<velikost; ++i)
	{
		n_is_in_a()
	}*/


	return 0;
}