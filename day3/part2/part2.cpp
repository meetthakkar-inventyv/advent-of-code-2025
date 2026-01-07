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
    long long maxi = 0;
    long long latest = 0;
    int latestIndex = -1;
    int cnt = 12;
    while(cnt){
      latest = 0;
      for(int j = latestIndex+1;j<=n-cnt;j++){
        if(numbers[j] > latest){
          latest = numbers[j];
          latestIndex = j;
        }
      }
      if(maxi == 0){
        maxi = latest;
        // cout<<latest<<" ";
      }
      else{
        maxi = maxi*10 + latest;
        // cout<<latest<<" ";
      }
      cnt -= 1;
    }
    // cout<<maxi<<endl;
    sum += maxi;
    
  }
  cout<<sum<<endl;
  return 0;
  }
