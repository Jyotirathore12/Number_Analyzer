#include<iostream>
using namespace std;

//function declaration

bool even(int n); //to check number is even or odd

bool prime(int n) ; //to check number is prime

bool palindrome(int n) ;  // to check for palindrome numbe

bool perfectNumber(int n); // to check for perfect number

int reverseNumber(int n); // to reverse number 

int sumOfDigits(int n);  // to calculate sum of digits

//main function
int main(){
  int n , i;
  cout <<"Enter a number"<<endl;
  cin>>n;

  if(n<0){
    cout<<"Enter a positive number"<<endl;
    return 0;
  }

  cout<<" Enter (1) for checking for even"<<endl; 
  cout<<" Enter (2) for checking for prime"<<endl;
  cout<<" Enter (3) for checking for palindrome"<<endl;
  cout<<" Enter (4) for checking for perfect number"<<endl;
  cout<<" Enter (5) to reverse number"<<endl;
  cout<<" Enter (6) to sum the digits"<<endl;
  cout<<" Enter (0) to exit the program"<<endl;
  cout<<"Operations to operate"<<endl;
  //menu driven program 
  cin>>i;
  switch (i)
  {
  case 1:
    /* code */
    cout <<" Number is  " << (even(n) ? "even" : "odd") <<endl;
    break;
  case 2:
    cout<< "Number is " <<(prime(n)? "prime" : "not prime")<<endl;
     break;
  case 3:
     cout << "Number is  " <<(palindrome(n)? "palindrome" : "not palindrome")<<endl;
     break;
  case 4:
     cout <<"Number is  " <<(perfectNumber(n)? "perfect number" : "not perfect number")<<endl;
     break;
  case 5 :
     cout<<" Reversed number is  "<< reverseNumber(n)<<endl;
     break;
  case 6 :
     cout <<" Sum of number is  "<<sumOfDigits(n)<<endl;
     break;
  case 0 : 
     cout<<"Program exit"<<endl;
      break;
  default:
     cout <<"Invalid Input"<<endl;
    break;
  }
  cout<<"Program worked successfully"<<endl;

}

//function definitions 
 //even function 
bool even(int n){
  return n%2==0;
}
 
//palindrome function
bool palindrome(int n){
    int original = n, rev = 0;

    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    return original == rev;
  }
 
//prime number 
 bool prime(int n){
     if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
 } 

 //perfect number 
 bool perfectNumber(int n){
    if (n <= 1) return false;

    int sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i)
                sum += n / i;
        }
    }
    return sum == n;  
 }

 //reverse a number
 int reverseNumber(int n){
     int reverse= 0;
     while(n){
       reverse = reverse*10 + n%10;
       n/=10;
     }
     return reverse;
 }

 //sumOfDigits
int sumOfDigits(int n){
  int sums = 0 ;
  while(n){
    sums = sums+n%10;
    n/=10;
  }
  return sums; 
}
