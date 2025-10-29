for(int i=0;i<t;i++){
    while(j<t && arr[j]<dep[i]){
      count++;
      j++;
      maxi = max(maxi, count);
    }
    count--;
    
  }