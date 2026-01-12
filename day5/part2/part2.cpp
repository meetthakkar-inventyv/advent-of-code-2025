  #include<iostream>
  #include<string>
  #include<vector>
  #include <algorithm>
  using namespace std;

  //Using merge interval concept
  int main(){
    freopen("input.txt", "r", stdin);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string temp;
    vector<string>ranges;
    while(getline(cin,temp)){
      if(temp.empty()) break;
      ranges.push_back(temp);
    }
    cout<<ranges.size()<<endl;
    
    int m = ranges.size();
    vector<pair<long long,long long>>merge;
    vector<pair<long long,long long>>temp1;

    for(int j=0;j<m;j++){
      size_t dash = ranges[j].find('-');
      long long start = stoll(ranges[j].substr(0, dash));
      long long end   = stoll(ranges[j].substr(dash + 1));
      temp1.push_back({start,end});
     
    }
    sort(temp1.begin(),temp1.end());
    long long ans = 0;
    for(int i=0;i<temp1.size();i++){
      long long start = temp1[i].first;
      long long end = temp1[i].second;
      if(merge.empty() || merge.back().second<start){
        merge.push_back({start,end});
      }
      else{
        merge.back().second = max(merge.back().second,end);
      }
    }
    for(int k=0;k<merge.size();k++){
      ans+=merge[k].second-merge[k].first +1;
    }
    cout<<ans<<endl;
    return 0;

  }
