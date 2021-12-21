//rashi singhvi
#include<stdio.h>


long long int power(long long int a, long long int b, long long int p){
	if(b==1)
		return a;
	else
		return( ((long long int) pow(a,b)) % p);
}
int main(){
	long long int P, G, a, b, xa, xb, ka, kb;
	P= 23;
	G= 9;
	printf("P: %lld\n ",P);
	printf("G: %lld\n ",G);
	//input private keys for both alice and bob
	//a=4
	//b=3
	printf("Enter value of a: ");
	scanf(" %lld",&a);
	printf("Enter value of b: ");
	scanf(" %lld",&b);
	printf("a: %lld\n ",a);
	printf("b: %lld\n ",b);
	
	//public values for exchanging
	xa= power(G,a,P);
	xb= power(G,b,P);
	printf("xa: %lld\n ",xa);
	printf("xb: %lld\n ",xb);
	
	//secret key after key exchange
	ka= power(xb,a,P);
	kb= power(xa,b,P);
	
	printf("ka: %lld\n ",ka);
	printf("kb: %lld\n ",kb);
	
	return 0;
}
