//
//  Header.h
//  Project 5
//
//  Created by Qinhao Xu on 2/22/16.
//  Copyright © 2016 Qinhao Xu. All rights reserved.
//

#ifndef PowerballTicket_h
#define PowerballTicket_h
#include <iostream>
using namespace std;

class PowerballTicket
{
    public:
    PowerballTicket();
    PowerballTicket(int ball1, int ball2, int ball3, int ball4, int ball5, int powerball);
    int getBall1();
    int getBall2();
    int getBall3();
    int getBall4();
    int getBall5();
    int getPowerball();
    
    private:
    int mBall1;
    int mBall2;
    int mBall3;
    int mBall4;
    int mBall5;
    int mPowerball;

};


#endif /* Header_h */
