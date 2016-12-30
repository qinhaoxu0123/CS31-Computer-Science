//
//  main.cpp
//  Project 4
//
//  Created by Qinhao Xu on 2/12/16.
//  Copyright © 2016 Qinhao Xu. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int locateMinimum( const string array[], int n)
{
    int result=0;
    string minimum= array[0];
    if(n<=0) return -1;
    
    for(int i=0; i < n; i++)
    {
        if(minimum > array[i])
        {
            minimum += array[i];
            result = i;
        }
        
    }
   return result;

}



int findLastOccurrence( const string arrayi[], int n, string target)
{
    int result=0;
    if(n<=0) return -1;
    
    for(int i=0; i < n; i++)
    {
        if(target == arrayi[i])
        {
            result=i;
        }
        
    }
    
    return result;
    
}
int flipAround(string arrayh[],int n )
{
    int i=0;
    int j= n-1;
    int res =0;
    while(i< j)
    {
        string tmp = arrayh [i];
        arrayh[i]= arrayh [j];
        arrayh[j]= tmp;
        ++i;
        --j;
        res++;
    }
    return res;
    
}


bool hasNoDuplicates( const string arrayk[ ], int n )
{
    if(n<=0) return false;
    for(int i=0; i<n ; i++)
        {
        for (int j = i+1 ; j<n ;j++)
            {
        if(arrayk[i]==arrayk[j])return false;
            }
        }
    return true;
    
}
bool hasNoDuplicates( const string arrayk[ ], int n );

void unionWithNoDuplicates( const string array1[ ], int n1, const string array2[ ], int n2, string resultingString[ ], int& resultingSize  )
{
    
    bool isduplicates = false;
    
    int finalcount =0;
    for(int i=0; i<n1 ; i++)
    {
        for (int j = 0 ; j<finalcount ;j++)
        {
            if(array1[i]!=resultingString[j])
            {
                continue;
            }
            else
            {
                isduplicates= true;
            }
        
        }
        if(isduplicates==false)
        {
        resultingString[finalcount]=array1[i];
        finalcount++;
        }
        isduplicates=false;
    }

    for(int i=0; i<n2 ; i++)
    {
        for (int j = 0 ; j<finalcount ;j++)
        {
            if(array2[i]!=resultingString[j])
            {
                continue;
            }
            else
            {
                isduplicates= true;
            }
            
        }
        if(isduplicates==false)
        {
            resultingString[finalcount]=array2[i];
            finalcount++;
        }
        isduplicates=false;
    }
  
    resultingSize = finalcount;
    
}



int shiftRight( string arrayp[], int n, int amount, string placeholderToFillEmpties )
{
    if(n<=0) return -1;
    int i=0;
    int j=0;
    int result =0;
    string arrayk[100];
    while(i<amount)
    {
        string tmp = arrayp [i];
        arrayp[i]= placeholderToFillEmpties;
        arrayk[i]= tmp;
        ++i;
    }
    while(amount<n)
    {
        string tmp = arrayp[amount];
        arrayp[amount]=arrayk[j];
        arrayk[j]= tmp;
        j++;
        amount++;
    }
    result= n-amount;
    return result;
}

bool isInIncreasingOrder( const string arrays[ ], int  n)
{
    if(n <=0) return false;
    for (int i=0; i< n-1; i++)
    {
        if(arrays[i]> arrays[i+1]) return false;
            
    }
    return true;
}




