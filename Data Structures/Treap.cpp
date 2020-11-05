// source: https://codeforces.com/gym/100488/submission/17870110    
#include <bits/stdc++.h>
#include <tr1/unordered_map>
typedef long long ll;
typedef unsigned long long ull;
#define clr(ma) memset(ma,-1,sizeof ma)
#define inf 1000000001ll
#define vi vector<int>
#define pi pair<ll,int>
#define T2 pair<pi ,pi >
#define mk make_pair
#define getBit(m,i) ((m&(1<<i))==(1<<i))
#define setBit(m,i) (m|(1<<i))
#define setBit2(m,i) (m|(1ull<<i))
#define cont(i,ma) ((ma.find(i))!=(ma.end()))
#define in(i) scanf("%d",&i)
#define in2(i,j) scanf("%d%d",&i,&j)
#define in3(i,j,k) scanf("%d%d%d",&i,&j,&k)
#define in4(i,j,k,l) scanf("%d%d%d%d",&i,&j,&k,&l)
#define il(i) scanf("%I64d",&i)
#define itr map<ll,ll>::iterator
#define itr2 map<ll,map<ll,ll> >::iterator
#define id(k) scanf("%9lf",&k)
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define clean(vis)  memset(vis,0,sizeof vis)
using namespace std;
typedef struct node{
    int prior,size;
    bool rev=false;
    char val;//value stored in the array
    struct node *l,*r;
}node;
typedef node* pnode;
int sz(pnode t){
   // cout<<"d5lsz"<<" "<<t<<endl;

    int k= t?t->size:0;
    //cout<<"5rgsz"<<endl;
    return k;
}
void upd_sz(pnode t){

    //cout<<"5lssize3"<<t<<endl;
    if(t)t->size=sz(t->l)+1+sz(t->r);
    //cout<<"5lssize"<<endl;
}
void lazy(pnode t){
    if (t && t->rev) {
        t->rev = 0;
        swap (t->l, t->r);
        if (t->l)  t->l->rev ^= 1;
        if (t->r)  t->r->rev ^= 1;
    }
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0){
    if(!t)return void(l=r=NULL);
    lazy(t);
    int curr_pos = add + sz(t->l);
    if(curr_pos<=pos)//element at pos goes to left subtree(l)
        split(t->r,t->r,r,pos,curr_pos+1),l=t;
    else
        split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);
}
void merge(pnode &t,pnode l,pnode r){//l->leftarray,r->rightarray,t->resulting array
    //cout<<"kk"<<r<<endl;
    lazy(l);lazy(r);
   // cout<<"kk2"<<endl;
    if(!l || !r) t = l?l:r;
    else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
    else    merge(r->l,l,r->l),t=r;
    //cout<<"kk3"<<t<<endl;
    upd_sz(t);
}
void print(pnode t){
    if (!t)return ;
    cout<<t->val;
    print(t->l);
    print(t->r);
}
void reverse (pnode  &t, int l, int  r) {
//    print(t);
//    cout<<endl;
//    cout<<l<<" "<<r<<endl;
    pnode L,mid,R;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);//note: r-l!!
    t->rev=1;
//    print(t);
//    cout<<endl;
    merge(mid,L,t);
    merge(t,mid,R);


}
pnode init(char val){
    pnode ret = new node();
    ret->prior=rand();ret->size=1;
    ret->val=val;
    ret->rev=0;
    //cout<<ret<<endl;
   // cout<<val<<endl;
    return ret;
}
char range_query(pnode &t,int l,int r){//[l,r]
//    print(t);
//    cout<<endl;
//    cout<<l<<" "<<r<<endl;
    pnode L,mid,R;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);//note: r-l!!
    char ans = t->val;
//    print(t);
//    cout<<endl;
    merge(mid,L,t);
    merge(t,mid,R);
    return ans;
}
void insert(pnode  &t,char val){
    //cout<<val<<endl;
    merge(t,t,init(val));
    //cout<<"5lsmerge"<<endl;
}
int n,l,r;
string s ;
int main(){
    cin>>n>>l>>r;
    l--;r--;
    cin>>s;
    //cout<<s<<endl;
    pnode root=NULL;
    for (int i=0;i<n;i++){
        insert(root,s[i]);
        //cout<<"5ls"<<endl;
    }
    int m;
    cin>>m;
    char t1 ;char t2;char t3;
    while (m--){
    cin>>t1;
        if (t1=='S'){
         cin>>t2>>t3;
            if (t2=='L'){
                if (t3=='L')l--;
                else l++;
            }
            else{
                if (t3=='L')r--;
                else r++;
            }
        }
        else if (t1=='Q'){
             cin>>t2;
            int d;
            if (t2=='L')d=l;
            else d=r;
           // cout<<d<<" "<<sz(root)<<endl;
            cout<<range_query(root,d,d);

        }
        else{
            reverse(root,l,r);
        }
    }

}
