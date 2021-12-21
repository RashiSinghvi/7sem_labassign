//rashi singhvi
#include<iostream>
using namespace std;
string encrpt( string text , int key){
	string result= "";
	for(int i =0 ; i < text.length(); i++){
		
		//check uppercase
		if (isupper(text[i])){
			result += char((int(text[i] )+ key -65) % 26 + 65);
		}
		
		//check lowercase
		else
			result += char((int(text[i] )+ key -97) % 26  + 97);
	}
	return result;
}
string decrpt( string cipher, int key){
	string result= "";
	for(int i=0; i< cipher.length(); i++){
		
		//check uppercase
		if(isupper(cipher[i]))
			result += char((int(cipher[i] )- key -65) % 26 + 65);
			
		//check lowercase
		else
			result += char((int(cipher[i] )- key - 97) % 26 + 97);
			
	}
	return result;
}
int main(){
	int key;
	string text;
	cout<<"Enter your text: ";
	cin>>text;
	cout<<"Enter key: ";
	cin>>key;
	string cipher = encrpt(text , key);
	cout<<"Cipher text: "<<cipher<<endl;
	string pt = decrpt(cipher, key);
	cout<<"Plain text: "<<pt<<endl;
	return 0;
}
