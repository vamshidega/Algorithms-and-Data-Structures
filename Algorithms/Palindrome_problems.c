Palindrome Questions:

1. Find the longest palindromic sub string in a string. (palindromic subsequence is different)
2. Count all the palindromic sub strings in a series of strings / series of characters


Find Longest Palindromic substring: Dynamic programming aproach.
----------------------------------------------------------------

  #include <iostream>
#include<string>

using namespace std;


std::string LPS(std::string str)
{
    int n = str.length();
    
    int BeginAt = 0;
    int max_len = 1;
    
    bool palindrome[n][n] = {{false}};
    
    //one character palindrome
    
    for(int i = 0; i< n;i++)
    {
        palindrome[i][i]=true;
    }
    
    //two characted palindrome
    for(int i = 0;i<n-1;i++)
    {
        if(str.at(i)==str.at(i+1))
        {
            palindrome[i][i+1] = true;
            BeginAt = i;
            max_len = 2;
        }
        
    }
    
    //three or more character palindrome
    
    for(int cur_length = 3; cur_length <= n; cur_length++)
    {
        
        for(int i =0; i<n-cur_length+1;i++)
        {
            int j = i+cur_length-1;
            
            //first and last character same and from the table previous bottom left is also palindrome
            // means rest of substring is also palindrome
            if(str.at(i)==str.at(j) && palindrome[i+1][j-1])
            {
                palindrome[i][j] = true;
                BeginAt = i;
                max_len = cur_length;
             
            }
        }
    }
    //return str.substr(BeginAt,max_len+1);
    return str.substr(BeginAt,max_len);
}


int main()
{
    
    std::string str = "ababcbacg";
    
    std::cout<<LPS(str); --> OP: abcba
    
    //cout<<"Hello World";

    return 0;
}
  
  







 


