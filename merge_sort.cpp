#include<bits/stdc++.h>
using namespace std;
vector<int> mix(vector<int> s1,vector<int> s2){
    vector<int> result;
    int i=0;
    int j=0;
    while(i<s1.size()&&j<s2.size()){
        if(s1[i]<s2[j]){
            result.push_back(s1[i]);
            i++;
        }
        else if(s1[i]>=s2[j]){
            result.push_back(s2[j]);
            j++;
        }
    }
    if(j<s2.size()){
        for(int k=j;k<s2.size();k++)
            result.push_back(s2[k]);

    }
    if(i<s1.size()){
        for(int k=i;k<s1.size();k++)
            result.push_back(s1[k]);

    }
    return result;
}

vector<int> merge_sort(vector<int> a,int L, int R){
    if(L==R){
        vector<int> s;
        s.push_back(a[L]);
        return s;
    }
    vector<int> save1;
    vector<int> save2;
    save1=merge_sort(a,L,(R+L)/2);
    save2=merge_sort(a,(R+L)/2+1,R);
    vector<int> result=mix(save1,save2);
    return result;
}

int main(){
  vector<int> a;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  vector<int> result=merge_sort(a,0,a.size()-1);
  for(int i=0;i<result.size();i++){
    cout<<result[i]<<" ";
  }

}
