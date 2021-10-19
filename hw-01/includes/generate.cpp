#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include<iostream>
using namespace std;
  vector<string> generate(unsigned n){
    queue<string> que;
    vector<string> arr;
    que.push("1");
   while(n != 0){
      //pushing the 1 to the front
      string front,zero,one;
      front = que.front();
      //pop the first number
      que.pop();
      arr.push_back(front);
      //everytime a new number enter in a , get put into place
      cout << front << ",";
      
      //adds the numbers to the existing numbers
       zero =(front + "0");
       one= (front + "1");
      //pushes into the vector
      que.push(zero);
      que.push(one);
      n--; 
    }
  return arr;
}

  
   
    
    




  
  
