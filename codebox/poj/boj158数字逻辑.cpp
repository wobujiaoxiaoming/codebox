#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
using namespace std;
struct node{
	int a;
	int b;
	string ss;
};
int num[30];
int isgot;
void output(int i,vector<struct node> v,int n){
	if(!isgot){
		if(i>n){
			int allfor=1;
			for(vector<struct node>::iterator itr=v.begin();itr!=v.end();itr++){
				if(itr->ss=="and"){
					if((num[itr->a]&&num[itr->b])!=1){
						allfor=0;
						break;
					}
				}
				else if(itr->ss=="or"){
					if((num[itr->a]||num[itr->b])!=1){
						allfor=0;
						break;
					}
				}
				else if(itr->ss=="xor"){
					if((num[itr->a]^num[itr->b])!=1){
						allfor=0;
						break;
					}
				}
			}
			if(allfor){
				isgot=1;
				int first =0;
				for(int j=1;j<=n;j++){
					if(first){
						cout<<" ";
					}
					if(num[j]==1){
						cout<<"on";
					}
					else
						cout<<"off";
					first=1;
				}
				cout<<endl;
			}
			return;
		}
		for(int j=0;j<2;j++){
			num[i]=j;
			output(i+1,v,n);
		}
	}
}
int main(){
  //	freopen("data","r",stdin);
	int n,m;
	while(1){
		cin>>n>>m;
		if(n==0&&m==0)
			break;
		vector<struct node> v;
		isgot=0;
		while(m--){
			struct node n;
			cin>>n.a>>n.ss>>n.b;
			v.push_back(n);
		}
		memset(num,sizeof(int),30);
		output(1,v,n);
		if(!isgot)
			cout<<"No solution"<<endl;
	}
	//freopen("CON","r",stdin);
	//system("pause");
	return 1;
}
