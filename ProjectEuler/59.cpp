/*bash command prior to this : cat ./cipher1.txt | tr ',' ' ' > ~/dev_cpp/euler/cipher2.txt */
/*program is for decoding an encrypted message*/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#define KEYNO 3
#define START 97
#define END 122
using  namespace std;

int main(){
	string unencrypted;
	int encrypted[2000];
	ifstream reader;
	int temp=0,counter=0,i=0,size=0;//i for unencrypted string iteration
	/*openining the file*/
	reader.open("cipher3.txt",ios::in);
	if(!reader.is_open()){//check syntax
		cout<<"Input operation failed\n";
		exit(1);
	}

	int a=97,b=97,c=97 ;
	i=0;
	while(reader>>temp){
		encrypted[i]=(temp);
		++i;
	}
	size=i;
	for(a=START;a<=END;++a){
		for (b=START;b<=END;++b){
			for(c=START;c<=END;++c){
	//print the line and its ascii value
				i=0;
				counter = 0;
				unencrypted="";
				/*unencrypting by setting possible cobbinations of 3 alphabets*/
				while(i<size){
					counter=counter%KEYNO;
					if(counter==0)
						unencrypted+=(char)(a^encrypted[i]);
					else if(counter==1)
						unencrypted+=(char)(b^encrypted[i]);
					else//counter == 2
						unencrypted+=(char)(c^encrypted[i]);
					++counter;
					++i;
				}
				if((unencrypted.find("the ")!=string::npos) || \
				unencrypted.find("and ")!=string::npos || unencrypted.find("then ")!=string::npos ||\
				(unencrypted.find("but ")!=string::npos) || (unencrypted.find("in ")!=string::npos)\
				|| (unencrypted.find("for ")!=string::npos) || (unencrypted.find("he ")!=string::npos) \
				|| (unencrypted.find("she ")!=string::npos)|| (unencrypted.find("The ")!=string::npos)){
					int sum=0;
					cout<<unencrypted<<endl;
					for(i=0;i<unencrypted.size();++i)
						sum+=(int)unencrypted[i];
					cout<<sum<<endl;
				}
			}
		}
	}
	reader.close();
	return 0;
}

/*tests to be done*/
//syntax , debug , printing various varibles , dry run 
