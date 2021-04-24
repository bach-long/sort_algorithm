#include<bits/stdc++.h>
using namespace std;
void radix_sort(vector<int>& a,long n,int mode=1,int x=10){
    if(mode>n){
        return;
    }
    else{
    vector<vector<int>> s(10);
    for(int i=0;i<a.size();i++){
        s[(a[i]%x)/(x/10)].push_back(a[i]);
    }
    a.clear();
    for(int i=0;i<10;i++){
        for(int j=0;j<s[i].size();j++){
            a.push_back(s[i][j]);
        }
    }
    mode++;
    x*=10;
    radix_sort(a,n,mode,x);
    }
}

int main(){
  vector<int> a={4,6,25,10,9124,1224,23,241,324,351,125,41,14902,124123,444,231,2315,310,1440,19281,19280};
  radix_sort(a,6);
  for(int i=0;i<a.size();i++){
    cout<<a[i]<<" ";
  }
}
