#include<bits/stdc++.h>
#define t() long long int t;cin>>t;while(t--)
#define lli long long int
#define mod 1000000007;
using namespace std;

bool isPrime(int n){
    if(n<=1)
        return false;
    
    if(n<=3)
        return true;
        
    if(n%2 ==0 || n%3 ==0)
        return true;
    
    for(int i=5; i*i<=n; i+=6){
        if(n%i == 0)
            return true;
    }
    return false;
}
int getCount(string s1){
    return std::count(s1.begin(), s1.end(), '1');;
}
int main()
{   
    t()
    {
        int n;
        cin>>n;
        string s1, s2, s3;
        cin>>s1>>s2>>s3;
        int c1=getCount(s1);
        int c2 = getCount(s2);
        int c3 = getCount(s3);

        vector<int> cnt;
        if(c1!=0 || c1!=n){
            cnt.push_back(c1);
        }
        if(c2!=0 || c2!=n){
            cnt.push_back(c2);
        }
        if(c3!=0 || c3!=n){
            cnt.push_back(c3);
        }
        int count = 0;
        while(!cnt.empty()||cnt.size()>=2){
            sort(cnt.begin(), cnt.end(),greater<int>());
            int sz = cnt.size();
            int gap = n-cnt[0];
            if(gap>=cnt[n-1]){
                cnt[0]+=cnt[n-1];
                count+=cnt[n-1];
                cnt.pop_back();
            }else{
                count+=gap;
                cnt[n-1]-=gap;
                cnt.erase(cnt.begin());
            }
        }

        cout<<cnt.size()<<" ";
        if(cnt.empty()){
            cout<<0;
        }
        else if(cnt[0]!=0 && cnt[0]!=n){
            if(count==0){
                cout<<-1;
            }else{
                cout<<count;
            }
            
        }else{
            cout<<-1;
        }
        cout<<endl;
    }
    return 0;
}