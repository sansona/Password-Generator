/*-----------------------------------------------------------------------------
credit to http://www.zedwood.com/article/cpp-sha256-function for sha256
implementation 

simple script to generate secure password from keywords. Useful for those
who want a password that's not susceptible to dictionary attack, don't trust
password managers, and/or prefer to memorize several short strings instead
of a password

C++ implementation
Usage: ./pw_generator hello entire world
-----------------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include "sha256.h"

using namespace std;

int main(int argc, char *argv[])
{
  //user should change these
  const int pw_len = 16;
  const string SALT = "cumin";
  const char SPEC_CHAR_1 = '!';
  const char SPEC_CHAR_2 = '@';
  const int CHAR_POS = 7;
  assert(CHAR_POS < pw_len/2);

  if (argc == 1)
  {
    cout << "Usage: ./pw_generator [keyword1] [keyword2] [keyword3]..." <<endl;
  }
  else if (argc < 4)
  {
    cout << "Minimum 2 keywords" << endl;
  }
  else
  {
    cout << "argc: " << argc << endl;

    //initialize array of args
    string input [argc];
    for (int i=1; i < argc; i++)
    {
      input[i - 1] = argv[i];
    }
    input[argc] = SALT; //add salt
    string sorted_arg_str; 
    sort(input, input+(argc - 1));

    //joins sorted arg array into string
    for (int i=0; i <= argc; i++)
    {
      sorted_arg_str += input[i];
    }

    //hash sorted arg, take substring of set length
    string hash_obj = sha256(sorted_arg_str);
    string shortened_hash = hash_obj.substr(0, pw_len);

    shortened_hash[CHAR_POS] = SPEC_CHAR_1;
    shortened_hash[CHAR_POS * 2] = SPEC_CHAR_2; 

    string front_hash = shortened_hash.substr(0, pw_len/2);
    string back_hash = shortened_hash.substr(pw_len/2, pw_len);

    //capitalizes first half of shortened hash ojb
    transform(front_hash.begin(), front_hash.end(), front_hash.begin(), 
      ::toupper);

    string final_hash = front_hash + back_hash;
    cout << final_hash << endl;

  }

  return 0;

}