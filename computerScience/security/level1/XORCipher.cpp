/* Author:		Nick Pederson
 * Date created:	12/10/2016
 * Purpose:		Encode and decode messages using a XOR cipher
 * Error codes:		0: success
 * 			1: ussage messege
 * 			2: error reading files
 */
#include<iostream>
#include<cstdio>

using std::endl;
using std::cout;

int main(int argc, char **argv){
   if(argc != 2){ //Displaying ussage messege
      cout <<"Ussage: " <<argv[0] <<" messegeFile" <<endl;
      return 1;
   }

   FILE *filePt = fopen(argv[1], "r");
   if(filePt == NULL){ //checking to see if messege file is readable
      cout <<"Error: unable to open " <<argv[1] <<endl;
      return 2;
   }

   char currentChar;
   
   //Reads first charector of key and messege files   
   currentChar = fgetc(filePt);

   while(!feof(filePt)){
      if(currentChar == '\n') cout <<endl; //keeps new lines in coded messege and flushes buffer
      else{
	 cout <<(char)~currentChar; //Prints currentChar XOR currentKey
      }

      //Reads next charectors
      currentChar = fgetc(filePt);
   }
   return 0;
}
