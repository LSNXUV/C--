
#include <iostream>
using namespace std;

bool Anagram(string s1,string s2)
{
    if(s1.size()!=s2.size())
        return false;
    int count1[26]={0};
    int count2[26]={0};
    for(int i=0;i<(int)s1.size();i++)
    {
        count1[s1[i]-'a']+=1;
    }
    for(int j=0;j<(int)s2.size();j++)
    {
        count2[s2[j]-'a']+=1;
    }
    for(int idx=0;idx<26;idx++)
    {
        if(count1[idx]!=count2[idx])
        {
            return false;
        }
    }
    return true;
}


int main(){
    string s1,s2;
    cin>>s1>>s2;

    if(Anagram(s1,s2))
    {
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

    system("pause");
    return 0;
}
