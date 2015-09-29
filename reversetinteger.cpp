#include<iostream>
using namespace std;

int reverse(int x) {

   long long tmp=0;

   while(x!=0){
       tmp=tmp*10+x%10;
       x=x/10;
   }

   if(tmp>2147483647||tmp<-2147483647)
    return 0;
   else
    return tmp;

}

int main()
{


}
