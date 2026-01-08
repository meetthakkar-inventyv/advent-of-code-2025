#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string temp;
  vector<string>vec;
  while(getline(cin,temp)){
    vec.push_back(temp);
  }
  int rows = vec.size();
  int cols = vec[0].size();
  int ans = 0;
  cout<<rows<<" "<<cols<<endl;
  for(int i = 0;i<rows;i++){
    for(int j=0;j<cols;j++){
      int count = 0;
      
      if(vec[i][j] == '@'){
        if(i-1>=0 && vec[i-1][j] == '@') count++;
        if(i+1 < rows &&vec[i+1][j] == '@') count++;
        if(j-1 >= 0 && vec[i][j-1] == '@') count++;
        if(j+1 < cols && vec[i][j+1] == '@') count++;
        if(i+1 <rows && j+1 < cols && vec[i+1][j+1] == '@') count++;
        if(i+1 < rows && j-1 >=0 && vec[i+1][j-1] == '@') count++;
        if(i-1>=0 && j+1 < cols && vec[i-1][j+1] == '@') count++;
        if(i-1>=0 && j-1>=0 && vec[i-1][j-1] == '@') count++;

        if(count < 4){
          ans++;
        }
      }
      
      
    }
  }
  cout<<ans<<endl;
  return 0;
}
