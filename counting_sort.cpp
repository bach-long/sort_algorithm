#include<bits/stdc++.h>
using namespace std;
vector<long> counting_sort(vector<long> a,int n){
  vector<long> b(n+1);
  for(int i=0;i<a.size();i++){
    b[a[i]]++;
  }
  for(int i=1;i<b.size();i++){
    b[i]=b[i-1]+b[i];
  }
  for(int i=b.size()-1;i>=1;i--){
    b[i]=b[i-1];
  }
  b[0]=0;
  vector<long> result(a.size());
  for(int i=0;i<a.size();i++){
    result[b[a[i]]]=a[i];
    b[a[i]]++;
  }
  return result;
}
int main(){
  vector<long> a={123,124,12,43,90,100,87,79,106,1003,1,5,141251,987,871,2713,12314,100,20036};
  long maximum=a[0];
  for(int i=0;i<a.size();i++){
    if(maximum<a[i])
        maximum=a[i];
  }
  vector<long> result=counting_sort(a,maximum);
  for(int i=0;i<result.size();i++){
    cout<<result[i]<<" ";
  }
}
