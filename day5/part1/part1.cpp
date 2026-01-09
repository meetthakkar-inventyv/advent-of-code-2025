  #include<iostream>
  #include<string>
  #include<vector>
  #include <algorithm>
  using namespace std;

  int main(){
    freopen("input.txt", "r", stdin);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string temp;
    vector<string>ranges;
    vector<long long>inputs;
    int flag = 0;
    while(getline(cin,temp)){
      if(temp.empty()) {
        flag=1;
        continue;
      }
      if(flag==0)
        ranges.push_back(temp);
      else
        inputs.push_back(stoll(temp));
    }
    cout<<ranges.size()<<" "<<inputs.size()<<endl;
    sort(ranges.begin(),ranges.end());
    long long count = 0;
    int n = inputs.size();
    int m = ranges.size();
    for(int i=0;i<n;i++){
      int flag = 0;
      for(int j=0;j<m;j++){
        size_t dash = ranges[j].find('-');
        long long start = stoll(ranges[j].substr(0, dash));
        long long end   = stoll(ranges[j].substr(dash + 1));
        if(inputs[i]>=start && inputs[i]<=end){
          flag = 1;
          break;
        }
      }
      if(flag==1)
        count++;
    }
    cout<<count<<endl;
    return 0;

  }
