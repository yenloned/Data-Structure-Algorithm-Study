/**
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise. 
 */
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    //two pointer solution; Time complexity in O(n); Space complexity in O(1)
    int l = 0;
    int r = s.length()-1;

    while(l<r){
        //In this solution, we need to use isalnum to ignore all special characters
        if(!isalnum(s[l])){
            l++;
        }else if(!isalnum(s[r])){
            r--;
        }else if(tolower(s[l])!=tolower(s[r])){
            return false;
        }else{
            l++; r--;
        }
    }
    return true;
}

int main(){
    cout << "Enter the checking string:" << endl;
    string s;
    getline(cin, s);
    bool result = isPalindrome(s);

    if(result){
        cout << "It is a Palindrome.";
    }else{
        cout << "It is not a Palindrome.";
    }

}