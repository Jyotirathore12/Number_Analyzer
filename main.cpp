#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/* ---------- GLOBAL PRECOMPUTATION ---------- */
const int MAXN = 1000000;
vector<bool> isPrime(MAXN + 1, true);

//function declaration

bool even(int n); //to check number is even or odd

bool prime(int n) ; //to check number is prime

bool palindrome(int n) ;  // to check for palindrome numbe

bool perfectNumber(int n); // to check for perfect number

int reverseNumber(int n); // to reverse number 

int sumOfDigits(int n);  // to calculate sum of digits

bool armStrongnum(int n); //too calculate as number is armstrong

vector<int> factorization(int n); //to find factor of a number

vector<int> fibonacciCheck(int n); //to check fabo of a number

int GCD(int a , int b); //greatest common divisor

int LCM(int a , int b) ; //Least common multiple

void analyzeRange(int l, int r);  //analyze the range 

void sieve(); 

//main function
int main(){

  sieve();   //precompute prime once 

  int n , i,num1,num2, low , high;
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
  cout<<" Enter(7) to check if number is armstrong"<<endl;
  cout<<" Enter (8) to find factors of a number"<<endl;
  cout<<" Enter (9) to find fibo series"<<endl;
  cout<<" Enter (10) to find GCD"<<endl;
  cout<<" Enter (11) to find LCM"<<endl;
  cout<<" Enter (12) Analayze between Ranges"<<endl;
  cout<<"Operations to operate"<<endl;

  //menu driven program 
  cin>>i;
  switch(i)
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

  case 7:
     cout <<" Number is  "<< (armStrongnum(n)?"is armstrong" : "not armstrong number")<<endl;
     break;
  
  case 8 :{
     vector<int> f = factorization(n);
     for(int x : f){
      cout<<x<<" ";
     }
     break;
    }

  case 9 :{
    vector<int> fc = fibonacciCheck(n);
    for(int x: fc){
      cout<<x<<" ";
    }
     break;
  }
  
  case 10 :
     cout<<"Enter Two numbers for GDC"<<endl;
     cin>>num1>>num2;
     cout<<"GCD : "<<GCD(num1,num2)<<endl;
     break;
  
  case 11 :
     cout<<"Enter Two numbers for LCM"<<endl;
     cin>>num1>>num2;
     cout<<"LCM : "<<LCM(num1,num2)<<endl;
     break;

  case 12 :
     cout<<"Enter the ranges"<<endl;
     cin>>low>>high;
     if(low > high) swap(low, high);
     analyzeRange(low,high);
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

//sieve function
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXN; j += i)
                isPrime[j] = false;
        }
    }
}


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

  //armstrong number 
bool armStrongnum(int n){
    if(n==0){
      return true;
    }
     //count number of digits 
     int cnt = 0;
     int a = n; //copy the number
     while(n){
      cnt++;
      n/=10;
     }
     n = a;
     //check for armstrong 
     int sum = 0;
    while(n){
     int lastdigit = n%10;
     sum +=(int) pow(lastdigit , cnt);
     n/=10;
    }
    return sum==a ;
}

  //to find factors of a number
vector<int> factorization(int n){
    vector<int> fact ; //to store the factors of an element 
    for(int i=1 ; i<=n ; i++){
     if(n%i == 0){
      fact.push_back(i);
     }
    }
      return fact;
}
  
  //to find fibo series till n 
vector<int> fibonacciCheck(int n){
    vector<int> fibo ;
    int t1 , t2 , sum , cnt;
    t1 = 1;
    t2 = cnt = 1;
    while(cnt<=n){
      fibo.push_back(t1);
      sum=t1+t2;
      t1= t2;
      t2= sum;
      cnt++;
    }
     return fibo;
 }

  //to find gcd of a number
int GCD(int a, int b){
    while (b != 0) {
      int rem = a % b;
      a = b;
      b = rem;
  }
    return a;
}

  //to find lcm of a number
int LCM(int a, int b){
    return (a / GCD(a, b)) * b;
}

void analyzeRange(int l, int r) {
    cout << "\nPrime numbers:\n";
    for (int i = l; i <= r; i++)
        if (isPrime[i]) cout << i << " ";

    cout << "\n\nPalindromes:\n";
    for (int i = l; i <= r; i++)
        if (palindrome(i)) cout << i << " ";

    cout << endl;
}

