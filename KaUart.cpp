//*******1*********2*********3*********4*********4*********5*********6*********7*********8
#include "KaUart.h"

KaUart::KaUart(int debug){
  Debug=debug;
}

void KaUart::begin(int rate){
  Serial.begin(rate);
  if(Debug){Serial.println("Ready");}
}

//##### get
//##### 読み込み待ち合わせ
int KaUart::get(){
  unsigned int i, j; char x; String d, y; bool b;
  
  j=0;
  if(Serial.available()){
    for(i=0; i<MAX_BUF; i++){Buf[i]="";}
    d=Serial.readStringUntil(0x0d);
    if(Debug){Serial.print("B:"); Serial.println(d);}
    for(i=0; i<d.length(); i++){
      x=d.charAt(i);
      if(x==47){j++;}
      else{
        if(j<MAX_BUF){Buf[j].concat(x);}else{return j;}
      }
    }
    return j;
  }else{
    return 0;
  }
}

