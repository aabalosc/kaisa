#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
  ifstream fin("dict.txt");
  string word;
  set<string> dictset;
  while(fin>>word)
   {
    dictset.insert(word);
   }

  cout<<"Please enter your message,then press \"Ctrl+D\" \n";
  vector<string> message;

  while(cin >> word)
  {
   message.push_back(word);
  }

  for(int i=0;i<26;i++)
  {
   int match=0;
   cout<<"i="<<i<<endl;
   for(int j=0;j<message.size();j++)
    {
      word=message[j];
      for(int k=0;k<word.size();k++)
       {
         word[k]=word[k]|0x20;
         if(word[k]/(97+i))
         {
          word[k]=word[k]-i;
         }
         else
         {
          word[k]=word[k]-i+26;
         }           
        }
      cout<<"find:"<<dictset.count(word)<<endl;
      if(dictset.find(word)!=dictset.end())
       {
        match++; 
        message[j]=word;
       }
    }
    cout<<"message size: "<<message.size()<<endl;
    cout<<"match: "<<match<<endl;
    double percent=(double)match/message.size()*100;
    cout<<"percent: "<<percent<<endl;
    cout<<endl;
    if( percent>= 80)
      {
        cout<<"Message is\n";
        ostream_iterator<string,char> out(cout,"  ");
        copy(message.begin(),message.end(),out);
        cout<<endl;
        return 0;
      }
   }
 cout<<"cann't explain the message"<<endl;
 return 0;
}
   
