vector<int> res;
vector<vector<int> > v;
void dfs(int s,int lv)
{
    res[s]=min(res[s],lv);
    for(auto x:v[s])
    {
        if(res[x]>(lv+1))
        {
            dfs(x,lv+1);
        }
    }
}
vector<int> solve(vector<int>& nums) 
{
    res.clear();
    v.clear(); 
   int n=nums.size();
   res.assign(n,INT_MAX);
   v.resize(n);
   
   for(int i=0;i<n;i++)
   {
       int l=i-nums[i];
       int r=i+nums[i];
       if(l>=0)
       {
            if((nums[l]&1)==(nums[i]&1))
            {
              v[l].push_back(i);
            }else  res[i]=1;
       }
       if(r<n)
       {
            if((nums[r]&1)==(nums[i]&1))
            {
              v[r].push_back(i);
            }else  res[i]=1; 
       }
   }
   
   for(int i=0;i<n;i++)
   {
    //    cout<<res[i]<<" ";
       if(res[i]==1)
       {
           dfs(i,1);
       }
   }
//    cout<<endl;
   for(int i=0;i<n;i++)
   {
       if(res[i]==INT_MAX)
           res[i]=-1;
   }
   return res;


}
