/* Author:  Nick Pederson
 * Created: 11/18/2016
 * Purpose: This code is evidence that I meet the c++ level 1 requirment for the mastery challenge.
 *          It demonstrates the use of:
 *          	* Public, protected, and private variables
 *          	* Constructors
 *          	* Inheritance
 *          	* Class pointers
 */
#include<iostream>

using std::cout;
using std::endl;

//The parent class
class parent{
   private:
      int A;
   protected:
      int B;

      //Prints all of the variables in parent class
      void printVar(){
	 cout <<"a = " <<A
	      <<"\nb = " <<B
	      <<"\nc = " <<C <<endl;
      }
   public:
      int C;

      //Parent constructor
      parent(int a, int b, int c){
	 A = a;
	 B = b;
	 C = c;
      }

      //Getters and setters for all of the variables
      void varA(int val) { A = val; }
      int varA() { return A; }
      void varB(int val) { B = val; }
      int varB() { return B; }
      void varC(int val) { C = val; } //not needed to get variable since C is public
      int varC() { return C; } //not needed to set variable since C is public
};

class child:parent{
   private:
   protected:
   public:
      //Child constructor
      child(int a, int b, int c) : parent(a, b, c){
	 //Prints out parent variables
	 cout <<"Before child changes variables:\n";
	 printVar();
      }

      //Prints out parent variables after changing protected variable B to input
      void changeProtected(int b){
	 cout <<"Child changes protected variable (b) to " <<b <<":\n";
	 B = b; //assigning B
	 printVar(); //printing variables
      }

      //Prints out parent variables after changing private variable A to input
      void changePrivate(int a){
	 cout <<"Child changes private variable (a) to " <<a <<":\n";
	 varA(a); //using setter for A
	 printVar(); //printing variables
      }
};

int main(){
   child *classpt; //creating class pointer
   classpt = new child(1, 2, 3); //initializing class pointer

   classpt->changeProtected(-1); //changing protected variable
   classpt->changePrivate(-1); //changing private variable

   return 0;
}
