#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
while(t--){
    int w,h,n;
    cin>>w>>h>>n;
    vector<int> xi;
    vector<int> yi;
    xi.push_back(0);
    yi.push_back(0);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y; 
        xi.push_back(x);
        yi.push_back(y);
    }
    xi.push_back(w+1);
    yi.push_back(h+1);
    sort(xi.begin(),xi.end());
    sort(yi.begin(),yi.end());
    int mx=0,my=0;
    for(int i=0;i<xi.size()-1;i++){
        mx=max(mx,xi[i+1]-xi[i]-1);
        my=max(my,yi[i+1]-yi[i]-1);

    }
    cout<<mx*my<<endl;

}

}