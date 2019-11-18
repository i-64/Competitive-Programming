#include <bits/stdc++.h>
using namespace std;

struct point{
  int x,y;
  bool covered=false;
};

point wleft,wright,p1,p2;
point b1left,b1right,b2left,b2right;

void inpwhite(){
  cin>>wleft.x>>wleft.y;
  cin>>wright.x>>wright.y;
  p1.x=wleft.x;
  p1.y=wright.y;
  p2.x=wright.x;
  p2.y=wleft.y;
}

void inpb1(){
  cin>>b1left.x>>b1left.y;
  cin>>b1right.x>>b1right.y;
}

void inpb2(){
  cin>>b2left.x>>b2left.y;
  cin>>b2right.x>>b2right.y;
}

void checkinside1(point &p){
  if(p.x<=b1right.x&&p.x>=b1left.x&&p.y>=b1left.y&&p.y<=b1right.y)
    p.covered=true;
}

void checkinside2(point &p){
  if(p.x<=b2right.x && p.x>=b2left.x && p.y>=b2left.y && p.y<=b2right.y)
    p.covered=true;
}

void pp(point p){
  cout<<p.x<<" "<<p.y<<endl;
}

bool checkall(){
  // cout<<p1.covered<<" "<<p2.covered<<" "<<wleft.covered<<" "<<wright.covered<<endl;
  return (p1.covered && p2.covered && wleft.covered && wright.covered);
}

bool oneleft(){
  if(b1left.x<b2left.x)
    return true;
  return false;
}

bool onetop(){
  if(b1right.y>b2right.y)
    return true;
  return false;
}

int main() {
  bool flag1=false,flag2=false;
  inpwhite();
  inpb1();
  inpb2();
  checkinside1(p1);
  checkinside1(p2);
  checkinside1(wleft);
  checkinside1(wright);
  checkinside2(p1);
  checkinside2(p2);
  checkinside2(wleft);
  checkinside2(wright);
  if(oneleft()){if(b1right.x>=b2left.x)flag1=true;}
  else{if(b2right.x>=b1left.x)flag1=true;}
  if(onetop()){if(b1left.y<=b2right.y)flag2=true;}
  else{if(b2left.y<=b1right.y)flag2=true;}
  bool flag=flag1||flag2;
  if(checkall()&&flag)
    cout<<"NO"<<endl;
  else
    cout<<"YES"<<endl;
  return 0;
}
