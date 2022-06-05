#include <iostream>
#include<vector>
#include <algorithm>
#include<chrono>
#include<iomanip>

using namespace std;


class Sorter
{
    public:

    virtual void Sort(vector<int> List ,int size)  {};
};

//--------------------------------------------------------------------------------------------

class QuickSort :public Sorter
{
    public:


void quicksort( vector <int> List, int first, int last)
{
  if (first < last) {

    int pi = part(List, first, last);
   quicksort(List, first, pi - 1);
   quicksort(List, pi + 1, last);
}}



    void Sort(vector<int> List ,int size)
    {
    quicksort( List,0,size-1);
    }




int part( vector <int> List, int first, int last) {
  int pivot = List[last];

  int i = (first - 1);
  for (int j = first; j < last; j++) {

        if(List[j] > pivot )
            {
                  i++;
                swap(List[i], List[j]);
            }
  }

  swap(List[i + 1], List[last]);

  return (i + 1);
}

};

//--------------------------------------------------------------------------------------------

class SelectionSorter:public Sorter
{
public:

void Sort(vector<int> List, int size) {

    for (int i = 0, j, least; i < size-1; i++) {

       for (j = i+1, least = i; j < size; j++)

		        if (List[j] < List[least])
              least = j;
       swap (List [least], List [i]);
    }
}


};

//--------------------------------------------------------------------------------------------

 class Testbed
 {
    public:
     Testbed()
     {}
     Sorter mySorter;
     vector<int> List;
//-------1--------------------------------------------------------
void GenerateRandomList(int min, int max, int size)
     {

            for(int i=1; i<=size; i++)
            {   int random = min + (rand() % max);
                List.push_back(random);
            }
     }

//-------2----------------------------------------------------------------------------
void GenerateReverseOrderedList(int min, int max, int size)
{
    GenerateRandomList(min,max,size);
    sort(List.begin(), List.end(), greater <>());
}
//------3-----------------------------------------------------------------------------
long long RunOnce(Sorter x , vector<int> List, int size)
{

        auto begin = std::chrono::high_resolution_clock::now();
        x.Sort(List,size);
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        return (time.count());

}


//-----4-----------------------------------------------------------------------------

long long  RunAndAverage(Sorter x, string type,int min, int max, int size, int sets_num)

{
    int total=0,avg=0;


    if(type == "Random")
    {  for(int i=1; i<= sets_num ;i++) {
        GenerateRandomList(min, max, size);
        total+= RunOnce(x, List, size);
    }   }

    if(type == "Reversed")
    {   for(int i=1; i<= sets_num ;i++) {
        GenerateReverseOrderedList(min, max, size);
        total+= RunOnce(x, List, size);
    }   }

avg = (total/ sets_num);
    return avg;
}
//-----5-----------------------------------------------------------------------------
void RunExperient (Sorter x, string type,int min,int max, int min_val,int max_val, int sets_num, int step)
{
   int num=0;//= RunAndAverage( x, type, min ,max, min_val ,sets_num)
   cout <<setw(5)<< "Size "<<setw(10)<<"Avg Time"<<endl;
   for(int i=min_val; i<= max_val ;i+=step)
   {
       num = RunAndAverage( x, type, min ,max, i ,sets_num);
       cout <<setw(5)<< i <<setw(5)<<num<<endl;

   }
}

 };


int main()
{
  Testbed x;
  cout<<endl<<"Quick Sort"<<endl;
 Sorter *m= new QuickSort;
 cout<<endl<<"-------------Reversed------------"<<endl;
   x.RunExperient(*m ,"Reversed" ,1 ,100 ,5000 ,25000,10,5000);
   cout<<endl<<"------------Random--------------"<<endl;
    x.RunExperient(*m ,"Random" ,1 ,100 ,5000 ,25000,10,5000);
cout<<endl<< "Selection Sort "<<endl;
   Sorter *p= new SelectionSorter;
  cout<<endl<<"-------------Reversed------------"<<endl;
   x.RunExperient(*p ,"Reversed" ,1 ,100 ,5000 ,25000,10,5000);
   cout<<endl<<"------------Random--------------"<<endl;
    x.RunExperient(*p ,"Random" ,1 ,100 ,5000 ,25000,10,5000);

  // cout << x.RunOnce(*p ,x.List ,1000);
  // cout<< x.RunAndAverage(*p ,"Reversed" ,1 ,100 ,1000 ,50) <<" Microseconds" ;
  //x.RunExperient(*p ,"Reversed" ,1 ,100 ,500 ,2500,100,500);
}
