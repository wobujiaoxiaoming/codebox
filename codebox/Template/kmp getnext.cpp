﻿ ////char ss[]="abaabcaba";
     //        -100112012         
//char ss[]="abaabcabaabda";
 //         -1001120123450
//char ss[]="abaabcac";
 //         -10011201
//char ss[]="aaaab";
 //         -10123   
void get_next(){
  int n=strlen(ss);
  num[0]=-1;
  num[1]=0;
  int j=0;
  for(int i=2;i<=n;i++){
    while(j>0&&ss[i-1]!=ss[j])//寻找前一个字符的相等后缀。
      j=num[j];
    if(ss[i-1]==ss[j]){//找到后,加1表示[前一个字符相等，后一个字符构成第二次比较方式]
      j++;
    }//else 基本都是0
 num[i]=j;
  }
}