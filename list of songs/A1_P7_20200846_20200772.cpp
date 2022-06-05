#include<iostream>
#include<vector>

#include<bits/stdc++.h>
using namespace std;


bool isbigger( string a,  string b){

  	transform(b.begin(), b.end(), b.begin(), ::tolower);
  	transform(a.begin(), a.end(), a.begin(), ::tolower);
    if(a == "untitled")
        return true;
    else if (b== "untitled")
        return false;
    else{

    int l = min(a.size(),b.size());
    for(int i = 0; i < l; i++){
        if( a[i] > b[i]) return false; // To compare two words in alpha order with the priority for "Untitled"
        if( b[i] > a[i]) return true;
    }
    if ( a.size() > l) return false;
    return true;
}}


void BiasedSort(vector <string> &List, int n)
{
    int i, j;
    string tmp;
    for (i = 1; i < n; i++)
    {
        tmp = List[i];                              //Insertion sort using Isbigger function that compares in alphabetical order
        j = i-1;
        while (j >= 0 && (isbigger(tmp,List[j])))
        {
            List[j+1] = List[j];
            j--;
        }
        List[j+1] = tmp;
    }
}

int main()
{
 vector <string> musicList={"HeartBeats", "DieForMe", "NeedToKnow" ,"Woman" ,"Untitled"};
 string song;
 cout<<"Please Enter your songs : (enter 0 to Exit) "<<endl;
 cin >> song;
    while(song != "0")
    {
        musicList.push_back(song);
        cin >> song;
    }

    BiasedSort(musicList,musicList.size());

for(int i = 0; i < musicList.size(); i++) {
    cout << musicList[i] << endl;
}


}
