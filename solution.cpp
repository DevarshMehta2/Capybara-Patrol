#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cfloat> // Added to fix DBL_MAX error
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
using namespace std;
// Main concept of this question is to think inverse recursion.It is very rare used concept
//In this we would create two recursion function and call it indirectly.
//first we define two variable .'b' which is conunt of cases when bob win.And total which describes total number of cases.

int b = 0;
int total = 0;


/////////////////////////////////Function//////////////////////////////

//we wil take sum and turn as parametre.It will be updated after every recursive call.
void funcb(int turn ,int sum);//we will write code for this afterwards


void funca(int turn , int sum){

    //////absurd cases////// 

    if(sum < 0){return;}//This are cases when bob took more number of blocks than it is present since is not possible no excluding

    ////////BASE CASE////

    if(sum == 0){b++;total++;}//In this case Alice lost  as last block is took by bob
    //Now we write all three cases 
    funcb(turn+1,sum - 1);//case when A takes 1 block
    if(turn != 1){funcb(turn+1,sum - turn);}//case when A takes x  blocks
    if(!(int)turn/2){ funcb(turn+1,sum - (int)turn/2);}//case when A takes x/2 blocks}
    funcb(turn +1,sum - 2*turn);//case when A takes 2*x blocks
    return;
}

void funcb(int turn , int sum){
        //////absurd cases////// 

        if(sum < 0){return;}//This are cases when bob took more number of blocks than it is present since is not possible no excluding

        ////////BASE CASE////
    
        
        if(sum == 0){total++;}//In this case bob lost  as last block is took by alice
        //Now we write all three cases 
        funca(turn+1,sum - 1);//case when bob takes 1 block
        if(turn != 1){funca(turn+1,sum - turn);}//case when bob takes x  blocks}
        if(!(int)turn/2){ funca(turn+1,sum - (int)turn/2);}//case when bob takes x/2 blocks}
        funca(turn +1,sum - 2*turn);//case when bob takes 2*x blocks
        return;
}



//Defining main function
int main(){
    int N;
    cin>>N;
    funca(1,N);//since alice is starting we have to first execute funca function
    double probablity = 1 - (float)b/total;
    cout<<probablity<<endl;
}
