#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string decimalToBinary(int number){
    int binary = 0,i =0;
    if (number<0)
    {
        number = abs(number);
        while (number > 0)
        {
            int bit = !(number & 1); // to get 1's compliment of number
            binary = (bit * pow(10, i) + binary);
            number= number >> 1;
            i++;
        }
        
        binary += 1;
    }else
    {
        
        while (number>0)
        {
            // int remainder = number % 2;
            // binary = (remainder * pow(10, i) + binary);
            // number /= 2;
            // i++;

            //: or

            int bit = number & 1;
            binary = (bit * pow(10, i) + binary);
        number= number >> 1;
            i++;
        }
     
    }
    
    
     return to_string(binary) ;
}
int binaryToDecimal(int number){
     int decimal = 0;
     int i = 0;
     while (number!=0)
     {
        int digit = number % 10;
        if (digit == 1)
        {
            decimal = decimal + pow(2, i);

        }
        i++;
        number /= 10;
     }
     return decimal;
}
int main()
{

    // cout << decimalToBinary(5);
    cout << binaryToDecimal(10101);
     


     return 0;
}