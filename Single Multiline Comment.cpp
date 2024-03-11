#include <bits/stdc++.h>
using namespace std;
int main()

{
    string s;
    fstream outt("output.txt",ios:: out);
    outt.close();
    fstream read("input.txt",ios:: in);
    ofstream out("output.txt");
    int multiline =0;
    while (getline (read, s))
    {
        int l = s.size(),newline=0,slash=0,f=0;
            for(int i =0; i<l; i++)
            {
                if(s[i]=='"')
                {
                    if(f==1)
                        f=0;
                    else
                        f=1;
                    out.put(s[i]);
                    continue;
                }
                if(s[i] == '/' && i+1<l && s[i+1]=='/' && f== 0 )
                {
                    slash =2;
                    continue;
                }
                if(s[i] == '/' && i+1<l && s[i+1]=='*' && f== 0 && multiline ==0)
                {
                    multiline=1;
                    continue;
                }
                if(multiline && s[i] == '*' && i+1<l && s[i+1]=='/' )
                {
                    multiline=0;
                    i+=1;
                    continue;
                }
                if(multiline)
                    continue;
                if(slash != 2)
                {
                    newline=1;
                    out.put(s[i]);
                }
            }
        if(newline || l == 0)
            out.put('\n');
    }
    read.close();
    out.close();

}

