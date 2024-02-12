/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].

Copyright 2009–2024 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <cstring>
#include <iostream>
using namespace std;

   char* itob(int i) {
      static char bits[31] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
      int bits_index = 30;
      while ( i > 0 ) {
         bits[bits_index--] = (i & 1) + '0';
         i = ( i >> 1);
      }
      return bits;
   }

int solution(int N) {
    // Implement your solution here
     char * binaryResult;
     int i,j,k;
     int maxGap=0;
     int count=0;
     int gapCount[10];
     for (i=0; i<10;i++) gapCount[i]=0;

     binaryResult=itob(N);
     //cout<<binaryResult<<endl;;
     i=0;
     j=0;
     while(i<strlen(binaryResult))
     {
         if (binaryResult[i] =='1')
            {
                for (j=i+1;j<strlen(binaryResult);j++)
                {
                    if (binaryResult[j]=='0') gapCount[count]++;
                    else
                    {
                        //cout<<gapCount[count]<<endl;
                        count++;
                        break;
                    }

                }
                i=j;
            }
        else
            i++;


     }

     for (k=0;k<count;k++)
     {
         if (gapCount[k]>maxGap) maxGap=gapCount[k];
     }

    return maxGap;
}


int main()
{
    int maxGap=solution(32);
    cout<<"maxGap="<<maxGap<<endl;
    return 0;
}
