class Solution {
public:
long long getRes(vector<int>& nums,int si,int ei,int minK,int maxK){     
        vector<int> mink,maxk;  
        for(int i =si;i<=ei;i++){
            if(nums[i]== minK)mink.push_back(i);
            if(nums[i]== maxK)maxk.push_back(i); }
        
       long long res = 0;
       for(int i =si;i<=ei;i++){  
        auto a = lower_bound(mink.begin(),mink.end(),i);
        auto b = lower_bound(maxk.begin(),maxk.end(),i);
        
        if(a==mink.end()||b == maxk.end() )continue;
        int x = *(a) ;
        int y = *(b);
        int v = max(x,y);
        res+= (ei-v+1); }
        return res;  
    }
    
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int l = -1,r = -1;
        long long ans = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]<=maxK && nums[i]>= minK){
                  if(l == -1)l = i; 
                     r = i;  }
            else{   
                if(l!=-1)
                ans+= getRes(nums,l,r,minK,maxK);
                l = -1,r = -1;
            if(nums[i]<=maxK && nums[i]>= minK){
                  if(l == -1)l = i; 
                      r = i;
            }   }   }
        
        if(l!= -1)
            ans += getRes(nums,l,r,minK,maxK);
        return ans;        
    }
        
    
};