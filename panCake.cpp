#include<bits/stdc++.h>
using namespace std;
class state{
    public:
    vector<int> v;
    state() {}
    state(vector<int> x) {
        v = x;
    }
    void print() {
        cout<<"*******"<<endl;
        for(int i = 0;i<v.size();i++) {
            cout<<v[i];
        }
        cout<<endl;
    }

    vector<state>  generateNextState() {
        vector<state>all;
        int x = 0;
        for(int i = v.size()-2;i>=0;i--) {
            vector<int>tmp;
            tmp =v;
            reverse(tmp.begin()+i,tmp.end());
            all.push_back(tmp);

        }

        return all;

    }
    string toString() {
        string s;
        for(int i = 0;i<v.size();i++) s+=(v[i]+48);
        return s;
    }


};

int h1 (state cur) { /// not good
    int sz = cur.v.size();
    int c = 0;
    for(int i=0;i<cur.v.size();i++) {
        if(cur.v[i]!=sz) c++;
        sz--;
    }
    return c;
}
int h2(state cur) { /// not good
    int c = 0;
    for(int i=0;i<cur.v.size()-1;i++) {
        if(abs(cur.v[i+1]-cur.v[i])>1) c++;
    }
    if(c==0&&cur.v[0]==1&&cur.v.size()>1) return 1;
    return c;

}
int h3(state cur) { /// works good
    int sz = cur.v.size();
    int c = 0;
    for(int i=0;i<cur.v.size();i++) {
        if(cur.v[i]!=sz) {
            for(int j = i+1;j<cur.v.size();j++) {
                if(cur.v[j] == sz) {
                    return min(j-i,(int)cur.v.size()-j);
                }
            }
        }
        sz--;
    }
    return 0;


}
int heu(state cur ) {
    return h3(cur);
}
map<string,int> visited;
map<string ,string > par;
struct info {
    state v;
    int f;
    int g;
    info(state _v , int _f,int _g) {
        v = _v;
        f = _f;
        g= _g;
    }
    bool operator<(const info& other) const {
        return f>other.f;
    }
};
void print(string cur) {
    if(cur=="0") return ;
    print(par[cur]);
    cout<<cur<<endl;
}
void aStar(state cur) {

    priority_queue<info> pq;
    int g= 0;
    int h = heu(cur);
    int f = h+g;
    pq.push(info(cur,h,g));
    visited[cur.toString()] = 1;
    par[cur.toString()] = "0";
    int ggg = 1;
    while(!pq.empty()) {
        info tmp = pq.top();
        pq.pop();
        if(heu(tmp.v)==0) {
            print(tmp.v.toString());
            break;
        }
        vector<state> next = tmp.v.generateNextState();
        for(int i = 0; i<next.size();i++) {
            if(visited.count(next[i].toString())) continue;
            g = tmp.g+1;
            h = heu(next[i]);
            f = g+h;
            visited[next[i].toString()] = 1;
            pq.push(info(next[i],h,g));
            par[next[i].toString()] = tmp.v.toString();

        }


    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    vector<int> input;
    for(int i = 0;i<n;i++) {
        int a;
        cin>>a;
        input.push_back(a);
    }
    state st(input);
    aStar(st);

    // st.print();
//    vector<state> next = st.generateNextState();
//    for(int  i = 0;i<next.size();i++) {
//        cout<<next[i].toString()<<endl;
//    }
//    cout<<heu(st)<<endl;



    return 0;
}
