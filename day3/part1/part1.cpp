#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long sum = 0;
  string temp;
  while(getline(cin,temp)){

    int n= temp.length();
    vector<int>numbers;
    for(int i=0;i<temp.length();i++){
      numbers.push_back(stoi(temp.substr(i,1)));
    }
    int maxi = -1;
    int maxIndex = n-1;
    for(int i=0;i<n-1;i++){
      if(numbers[i] > maxi){
        maxi = numbers[i];
        maxIndex = i;
      }
    } 
    int maxi2 =-1;
    for(int j=maxIndex+1; j<n;j++){
      if(numbers[j]>maxi2){
        maxi2 = numbers[j];
      }
    }
    int ans = (maxi*10)+maxi2;
    sum+=ans;
  }
  cout<<sum<<endl;
  return 0;
  }
