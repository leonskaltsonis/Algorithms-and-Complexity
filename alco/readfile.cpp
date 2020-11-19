#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

void read_data(vector <set <string>> &studs,int exams,int students)
{
    string fn="";
    ifstream is;
    string line;
    is.open(fn);
    if(!is.is_open())
    {
        cerr<<"Error on file naming!!!!"<<endl;
        return;
    }
    while(getline(is,line))
    {
       stringstream ss(line);
       string word;
       set <string> exms;
       while(ss>>word)
       {
           exms.insert(word);
       }
       studs.push_back(exms);
    }
    is.close();
}

vector <string> unique_exams(vector <set<string>> &students)
{
   vector <string> exams;
   for(auto &x:students)
   {
       for(auto &y:x)
       {
           bool found=false;
          for(auto &k:exams)
          {
            if(y==k)
            {
                found=true;
                break;
            }
          }
          if(!found)
          {
              exams.push_back(y);
          }
       }
   }
   return exams;
}

bool is_in(set <string> &aset,const string &exam)
{
    for(auto &x:aset)
    {
        if(x==exam)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector <set <string>> students;
     vector <string> exms=unique_exams(students);
    const int exams=exms.size();
    int board[exams][exams];
    for(int i=0;i<exams;i++)
    {
        for(int j=0;j<exams;j++)
        {
           for(auto &x:students)
           {
               if(is_in(x,exms[i]) && is_in(x,exms[j]))
               {
                   board[i][j]=1;
               }
           }
        }
    }
    int summary=0;
    for(int i=0;i<exams;i++)
    {
        for(int j=0;j<exams;j++)
        {
            if(board[i][j]==1)
            {
                summary++;
            }
        }
    }
    double cv=(double)summary/(exams*exams);
    cout<<"Total exams:"<<exams<<endl;
    cout<<"Cv:"<<cv<<endl;
}