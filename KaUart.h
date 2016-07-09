//*******1*********2*********3*********4*********4*********5*********6*********7*********8
#include "Arduino.h"
/* ir.h */
#ifndef KAUART_H
#define KAUART_H

#define MAX_BUF 5

class KaUart{
  public:
    KaUart(int debug);
    void begin(int rate);
    int get();
    int Debug;
    String Buf[MAX_BUF];
  private:
};

#endif
