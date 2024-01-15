int merge(vector<int> &a,int l,int r){
  int mid=l+(r-l)/2;
  int left=l;
  int right=mid+1;
  vector<int> temp;
  int count =0;
  while(left<=mid && right<=r){
      if(a[left]<=a[right]){
          temp.push_back(a[left]);
          left++;
      }
      else{
          temp.push_back(a[right]);
          count+=(mid-left+1);
          right++;
      }
  }
  while(left<=mid){
      temp.push_back(a[left]);
      left++;
  }
  while(right<=r){
      temp.push_back(a[right]);
      right++;
  }
  for(int i=l;i<=r;i++){
      a[i]=temp[i-l];
  }
  return count;

}



int mergeSort(vector<int> &a,int l ,int r){
    int count =0;
    if(l==r){
        return count;
    }
    int mid =l+(r-l)/2;
    count+=mergeSort(a,l,mid);
    count+=mergeSort(a, mid+1, r);
    count+=merge(a,l,r);
    return count;
}

int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.

    return mergeSort(a,0,n-1);
}