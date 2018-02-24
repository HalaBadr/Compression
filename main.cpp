#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    string s,s1;
    int a=0;
    vector<string> v , v1;
    //compression
    getline(cin,s);
    while(s[0] !='0'){
        if(!a){
           v.push_back(s);
           a=1;
           s1=s;
        }
        else{
            int x=0,cnt=0,y;
            y=min(s1.size(),s.size());
            while(y--){
               if(s1[x]==s[x]) cnt++;
                else break;
                x++;
            }
            s1=s;
            if(cnt){
            s="";
            for(int i=cnt;i>0;i/=10){
            s+=(i%10)+'0';}
            reverse(s.begin(),s.end());
            s+=s1.substr(cnt,s1.size());
        }
        v.push_back(s);
    }
    getline(cin,s);
    }
    //decompression
    string n , out , pre = v[0];int x,p=0;
    v1.push_back(pre);
    for(int i=1;i<v.size();i++){
           out=""; n="";x=v[i].size();

          for(int j=0;j<v[i].size();j++){
            if(v[i][j]>='0'&&v[i][j]<='9'){
            n+=v[i][j];
            }
            else{x = j;break;}
          }
          int r = 1;p=0;
          reverse(n.begin(),n.end());
          for(int j = 0 ; j < n.size();j++){
            p+=(n[j]-'0')*r;r*=10;
          }
          out+=pre.substr(0,p);
          out+=v[i].substr(x,v[i].size());
          /*for(int j=0;j<p;j++){
            out+=pre[j];
          }
          for(int j=x;j<v[i].size();j++){
              out+=v[i][j];
          }*/
          pre=out;
          v1.push_back(out);
    }
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<endl;
    }
    return 0;
}
