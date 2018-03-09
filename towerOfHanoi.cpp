#include<bits/stdc++.h>
#define pb push_back
using namespace std;
class state{
    public:
    vector<int>  first,second,third;  /// tower
    state(){
        first = {3,2,1};
        second= {};
        third = {};
    }
    state(vector<int> _first,vector<int> _second,vector<int> _third) :
                first(_first),second(_second),third(_third){}
    vector<state> generateNextState(){
        vector<state> v;
        state cur(first,second,third);
        state tmp = cur;
        if(tmp.first.size()) {
            tmp.second.push_back(tmp.first.back());
            tmp.first.pop_back();
        }
        v.pb(tmp);
        tmp = cur;
        if(tmp.first.size()) {
            tmp.third.push_back(tmp.first.back());
            tmp.first.pop_back();
        }
        v.pb(tmp);
        tmp = cur;
        if(tmp.second.size()) {
            tmp.first.push_back(tmp.second.back());
            tmp.second.pop_back();
        }
        v.pb(tmp);
        tmp = cur;
        if(tmp.second.size()) {
            tmp.third.push_back(tmp.second.back());
            tmp.second.pop_back();
        }
        v.pb(tmp);
        tmp = cur;
        if(tmp.third.size()) {
            tmp.first.push_back(tmp.third.back());
            tmp.third.pop_back();
        }
        v.pb(tmp);
        tmp = cur;
        if(tmp.third.size()) {
            tmp.second.push_back(tmp.third.back());
            tmp.third.pop_back();
        }
        v.pb(tmp);

        return v;
    }
    bool isIllegalState() {
        state cur(first,second,third);
        for(int i = 1;i<cur.first.size();i++) {
            if(cur.first[i]>cur.first[i-1]) return true;
        }
        for(int i = 1;i<cur.second.size();i++) {
            if(cur.second[i]>cur.second[i-1]) return true;
        }
        for(int i = 1;i<cur.third.size();i++) {
            if(cur.third[i]>cur.third[i-1]) return true;
        }
        return false;
    }
    string toString () {
        string tmp ;
        for(int i = 2;i>=0;i--) if(i<first.size()) tmp+=first[i]+48; else tmp+='0';
        for(int i = 2;i>=0;i--) if(i<second.size()) tmp+=second[i]+48; else tmp+='0';
        for(int i = 2;i>=0;i--) if(i<third.size()) tmp+=third[i]+48; else tmp+='0';
        return tmp;
    }
};
map<string,int> visited;
map<string ,string> path;
void print_path(string tmp) {
    string a,b,c;
    a = tmp.substr(0,3);
    b = tmp.substr(3,3);
    c = tmp.substr(6,3);
    if(a=="000"&&b=="000"&&c=="000") return;
    print_path(path[tmp]);
    for(int i  = 0;i<=2;i++) {
        printf("%c ",a[i]);
        printf("%c ",b[i]);
        printf("%c\n",c[i]);
    }
    printf("************\n");
}
void debug(string tmp) {
    string a,b,c;
    a = tmp.substr(0,3);
    b = tmp.substr(3,3);
    c = tmp.substr(6,3);
    for(int i  = 0;i<=2;i++) {
        printf("%c ",a[i]);
        printf("%c ",b[i]);
        printf("%c\n",c[i]);
    }
    printf("************\n");
}

void bfs(){
    state st;
    vector<int>ed= {3,2,1};
    queue<state> q;
    q.push(st);
    visited[st.toString()] = 1;
    path[st.toString()] = state({},{},{}).toString();
    while(!q.empty()) {

        state cur = q.front();
        if(cur.third==ed||cur.second==ed){
            print_path(cur.toString());
            break;
        }
        q.pop();
        vector<state> gen = cur.generateNextState();
        for(auto next : gen) {
            if(visited.count(next.toString())) continue;
            if(next.isIllegalState()) continue;
            visited[next.toString()] = 1;
            q.push(next);
            path[next.toString()] = cur.toString();
        }

    }
}

int main() {
    bfs();
    return 0;
}
