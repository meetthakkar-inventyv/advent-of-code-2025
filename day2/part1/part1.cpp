#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("input.txt");

    if (!file.is_open()) {
        cout << "Failed to open file\n";
        return 1;
    }
    unsigned long long sum = 0;
    string temp;
    while (getline(file, temp)) {
      int n = temp.length();
      int i = 0;
      for(;i<n;i++){
        if(temp[i] == '-'){
          break;
        }
      }
      string first  =temp.substr(0,i);
      string last = temp.substr(i+1);

      long long min = stoll(first);
      long long max = stoll(last);

      for(long long j=min;j<=max;j++){
        string str = to_string(j);
        if(str.length()%2 != 0){
          continue;
        }
        int mid = (str.length())/2;
        if(str.substr(0,mid) == str.substr(mid)){
          sum += stoll(str);
        }
      }
      
    }
    cout<<sum<<endl;

    file.close();
    return 0;
}
