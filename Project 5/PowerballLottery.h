//
//  PowerballLottery.hpp
//  Project 5
//
//  Created by Qinhao Xu on 2/22/16.
//  Copyright © 2016 Qinhao Xu. All rights reserved.
//

#ifndef PowerballLottery_h
#define PowerballLottery_h

#include "PowerballTicket.h"
#include <iostream>
using namespace std;

class PowerballLottery
{
public:
    enum WinningPossibility {
        POWERBALL,ONEPLUSPOWERBALL,TWOPLUSPOWERBALL,THREE, THREEPLUSPOWERBALL, FOUR, FOURPLUSPOWERBALL,FIVE,FIVEPLUSPOWERBALL, NOTWINNING
    };
    PowerballLottery();
    PowerballLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int powerball);
    int getBall1();
    int getBall2();
    int getBall3();
    int getBall4();
    int getBall5();
    int getPowerball();
    PowerballTicket quickPick();
    WinningPossibility checkTicket(PowerballTicket ticket);
    void printWhatHappened(PowerballTicket ticket);
    
private:
    int mBall1;
    int mBall2;
    int mBall3;
    int mBall4;
    int mBall5;
    int mPowerball;
    
    
};

#endif /* PowerballLottery_hpp */
