/* Author:		Nick Pederson
 * Date created:	12/10/2016
 * Purpose:		Encode and decode messages using a XOR cipher
 * Error codes:		0: success
 * 			1: ussage messege
 * 			2: error reading files
 * 			3: key is to short for messege
 */
#include<iostream>
#include<cstdio>

using std::endl;
using std::cout;

int main(int argc, char **argv){
   if(argc != 3){ //Displaying ussage messege
      cout <<"Ussage: " <<argv[0] <<" keyFile messegeFile" <<endl;
      return 1;
   }

   FILE *keyPt = fopen(argv[1], "r"), 
	*filePt = fopen(argv[2], "r");
   if(keyPt == NULL){ //checking to see if key file is readable
      cout <<"Error: unable to open " <<argv[1] <<endl;
      return 2;
   }
   if(filePt == NULL){ //checking to see if messege file is readable
      cout <<"Error: unable to open " <<argv[2] <<endl;
      return 2;
   }

   char currentChar,
	currentKey;
   
   //Reads first charector of key and messege files   
   currentChar = fgetc(filePt);
   currentKey = fgetc(keyPt);

   while(!feof(filePt) && !feof(keyPt)){
      if(currentChar == '\n') cout <<endl; //keeps new lines in coded messege and flushes buffer
      else{
	 cout <<(char)~currentChar; //Prints currentChar XOR currentKey
      }

      //Reads next charectors
      currentChar = fgetc(filePt);
      currentKey = fgetc(keyPt);
   }

   //checking for bad key
   if(!feof(filePt) && feof(keyPt)){
      cout <<"\nError: bad key\n";
      return 3;
   }
   return 0;
}
