#include<iostream>
#include"../src/json.hpp"
#include <sys/time.h>

using namespace std;
using json = nlohmann::json; 
int main()
{
  json j = {
    {"id",1},
    {"str",2}
  };
  clock_t start,end;
  start = clock();
  for(int i=0;i<100000;i++)
  {
    string s = j.dump();
    //cout<<j.dump(4)<<endl;
    j =  json::parse(" { \" happy \":true,\" pi \":3.141} ");
    //cout <<j <<endl;
  }
  end = clock();
  double seconds = (double)(end - start)/CLOCKS_PER_SEC;
  fprintf(stderr, "Use time is: %.8f\n", seconds);
  return 0;
}

