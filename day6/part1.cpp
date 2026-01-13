#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int main(){
  freopen("input.txt" , "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string temp;
  vector<vector<string>> matrix;
    while (getline(cin, temp))
    {
        stringstream ss(temp);
        vector<string> row;
        string token;

        while (ss >> token)
        {
            row.push_back(token);
        }
        matrix.push_back(row);
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    long long ans = 0;
    for(int j=0;j<cols;j++){
      string operation = matrix[rows-1][j];
      long long temp = 0;
      long long temp1 = 1;
      // cout<<operation[0]<<endl;
      if(operation[0] == '*'){
        for(int i=0;i<rows-1;i++){
          long long num  = stoll(matrix[i][j]);
          temp1 *= num;
        }
      }
      else{
         for(int i=0;i<rows-1;i++){
          long long num  = stoll(matrix[i][j]);
          temp += num;
        }
      }
      if(temp != 0) ans += temp;
      else if(temp1 != 1) ans += temp1;
    }
    
    cout<<ans<<endl;

}