#include<bits/stdc++.h>
using namespace std;
int position(vector<int>& a,int l,int r){
    int index=l;
    for(int i=l;i<r;i++){
        if(a[i]<=a[r]){
            swap(a[index],a[i]);
            index++;
        }
    }
    swap(a[r],a[index]);
    return index;
}

void quick_sort(vector<int>& a,int L, int R){
    if(L>=R){
        return;
    }
    else{
    int b=position(a,L,R);
    quick_sort(a,L,b-1);
    quick_sort(a,b+1,R);
    }


}

int main(){
   vector<int> a;
   int x;
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
    cin>>x;
    a.push_back(x);
   }
   quick_sort(a,0,a.size()-1);
   for(int i=0;i<a.size();i++){
    cout<<a[i]<<" ";
   }
}
