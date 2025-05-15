# Explanation and Recursive Approach for The Last of Us Problem

In this question since we are told to calculate probability, it is clear that we have to compute all possible cases, and have to check the result. Since Alice and Bob get chance alternatively, recursion is the only best option to do so. Now since here are two points of attention (Alice and Bob) we have to create two recursive functions. Now since chances candidates get is alternate it is clear that we have to connect both functions by calling other recursive function instead of original one. This is the main concept of indirect recursion. So this would create cycle in which alternate recursive calls will be there and it will be analogous to Alice and Bob getting alternative chances.

## FUNCB

```cpp
void funcb(int turn , int sum){
        //////absurd cases////// 

        if(sum < 0){return;}//These are cases when bob took more number of blocks than it is present since is not possible no excluding

        ////////BASE CASE////

        if(sum == 0){total++;}//In this case bob lost as last block is took by alice
        //Now we write all three cases 
        funca(turn+1,sum - 1);//case when bob takes 1 block
        if(turn != 1){funca(turn+1,sum - turn);}//case when bob takes x  blocks}
        if(!(int)turn/2){ funca(turn+1,sum - (int)turn/2);}//case when bob takes x/2 blocks}
        funca(turn +1,sum - 2*turn);//case when bob takes 2*x blocks
        return;
}
```

In this recursive, we first write base case that limits the recursive calls i.e when all blocks will be taken. In that base cases we increase number of total possible outcome. If last block is taken by bob we also increase odd against alice. Thus calculating unfavorable cases. After that we write three recursive calls. Now since it is Alice's turn, we will call funca, and will decrease sum by 1/ turn etc, assuming that bob had taken that number of blocks and increase its turn by 1. Now there can be case in which blocks remaining are less than blocks taken, so this case have to be removed. So in beginning of program we removed those cases. Similarly create funca, and execute those functions.

## TIME COMPLEXITY  
O(4^N)

## SPACE COMPLEXITY  
O(N)
