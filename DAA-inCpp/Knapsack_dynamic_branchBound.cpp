#include<bits/stdc++.h>
using namespace std;


class Item
{
public:
    float weight;
    int value;
};


class Node
{
public:
    int level, profit, bound;
    float weight;
};


bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}


int bound(Node u, int n, int W, vector<Item>arr)
{
    
    if (u.weight >= W)
        return 0;


    int profit_bound = u.profit;

  
    int j = u.level + 1;
    int totweight = u.weight;

   
    while ((j < n) && (totweight + arr[j].weight <= W))
    {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }

    if (j < n)
        profit_bound += (W - totweight) * arr[j].value /
                                        arr[j].weight;

    return profit_bound;
}

int knapsack(int W, vector<Item>arr, int n)
{
  
    sort(arr.begin(), arr.end(), cmp);

 
    queue<Node> Q;
    Node u, v;


    u.level = -1;
    u.profit = u.weight = 0;
    Q.push(u);

    
    int maxProfit = 0;
    while (!Q.empty())
    {
        
        u = Q.front();
        Q.pop();

        if (u.level == -1)
            v.level = 0;

        if (u.level == n-1)
            continue;

        v.level = u.level + 1;

    
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        
        v.bound = bound(v, n, W, arr);

        if (v.bound > maxProfit)
            Q.push(v);

        
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
    }

    return maxProfit;
}





int mem_kp(vector<int>w,vector<int>prices,vector<vector<int>>&m,int i, int W){
    if(i==w.size()) return 0;

    if(m[i][W]!=-1) return m[i][W];

    if(w[i]<=W){
        int take = prices[i] + mem_kp(w,prices,m,i+1,W-w[i]);
        int nottake = mem_kp(w,prices,m,i+1,W);
        return m[i][W] = max(take,nottake);
    }
    else{
        return m[i][W] = mem_kp(w,prices,m,i+1,W);
    }

    
}

int dynamic_kp(vector<int>w,vector<int>prices,int W){

    int n=w.size();
    int m=W;

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){

            if(i==0 || j==0) dp[i][j]=0;


            else if(w[i-1]<=j){
                int take = prices[i-1] + dp[i-1][j-w[i-1]];
                int nottake = dp[i-1][j];
                dp[i][j] = max(take,nottake);
            }

            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][m];

    
}

int main(){

  vector<int>profit = { 60, 100, 120 };
  vector<int>weight = { 10, 20, 30 };
  vector<Item>arr;
  int W = 50;

  for(int  i=0;i<profit.size();i++){
    Item *it=new Item();
    it->value=profit[i];
    it->weight=weight[i];
    arr.push_back(*it);
  }

  
  vector<vector<int>>m(weight.size(),vector<int>(W+1,-1));
  cout << "Maximum profit (by Memoization (DP)) is " << mem_kp(weight,profit,m,0,W)<<endl;
  cout << "Maximum profit (by Tabulation (DP)) is: " << dynamic_kp(weight,profit,W)<<endl;
  cout << "Maximum profit (by Branch & Bound) is: " << knapsack(W,arr,weight.size());

  return 0;
}