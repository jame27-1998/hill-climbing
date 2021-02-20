#include<iostream>
#include<vector>
#include<unordered_map>
#include <bits/stdc++.h>

using namespace std;



int getNum(vector<int>& v)
{
    int n = v.size();

    srand(time(NULL));
    int index = rand() % n;
    int num = v[index];
    swap(v[index], v[n - 1]);
    v.pop_back();
 
    return num;
}

int random(int min,int max) {
   static bool first = true;
   if(first) 
   {  
      srand(time(NULL));
      first = false;
   }
   return min+rand()%((max+1)-min);
}



int main()
{
    

    vector<vector<int>>graph{{0,2,3,3,6},{2,0,4,5,3},{3,4,0,7,3},{3,5,7,0,3},{6,3,3,3,0}};
    cout<<"\n";
    cout<<" for the following graph \n";
    cout<<"\n";

    for(int i=0;i<graph.size();i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;

    }
    cout<<endl;


    int n=graph[1].size();
    vector<int>initial(n);
    vector<int>solution;

    for(int i=0;i<n;i++)
        initial[i]=i+1;

    while(initial.size()) {
        int num=getNum(initial);
        solution.push_back(num);
    }    

    solution.push_back(solution[0]);

    int pathcost=0;
    cout<<"initial path:";

    for(int i=0;i<solution.size();i++)
    {
        cout<<solution[i]<<" ";

    }

    for(int i=0,j=1;j<solution.size();i++,j++)
    {
        pathcost=pathcost+graph[solution[i]-1][solution[j]-1];
    }
    cout<<endl;
    cout<<"path cost: ";
    cout<<pathcost<<endl;

    int threshhold=30;

    vector<int> sol_copy=solution;
    int current_pathcost=0;
    bool flag=false;

    

    while(threshhold>0)
    {
        int totalneighbours=graph.size()-1;

        while(totalneighbours>0)
        {
            
            int neighbour=random(1,4);
            int temp=sol_copy[0];
            sol_copy[0]=sol_copy[neighbour];
            sol_copy[neighbour]=temp;

            sol_copy[sol_copy.size()-1]=sol_copy[0];
            current_pathcost=0;
            for(int i=0,j=1;j<solution.size();i++,j++)
            {
            current_pathcost=current_pathcost+graph[sol_copy[i]-1][sol_copy[j]-1];
            }

            if(current_pathcost<pathcost)
            {
                
            solution=sol_copy;
            pathcost=current_pathcost;
            break;
            }

            totalneighbours--;
            

            if(totalneighbours==0)
            {
                 flag=true;
            }
        }

        if(flag==true)
        {
            break;
        }
        

        threshhold--;
    }
    cout<<"\n";

    cout<<"obtained path : ";

    for(int i=0;i<solution.size();i++)
    {
        cout<<solution[i]<<" ";

    }
    cout<<endl;
    cout<<"path cost: "<<pathcost;



    return 0;
}
