//
//  main.cpp
//  Project 5
//
//  Created by Qinhao Xu on 2/22/16.
//  Copyright © 2016 Qinhao Xu. All rights reserved.
//
#include "PowerballTicket.h"
#include "RandomNumber.h"
#include <iostream>

//initialzie the mBall vaule;
PowerballTicket::PowerballTicket()
{
    mBall1=0;
    mBall2=0;
    mBall3=0;
    mBall4=0;
    mBall5=0;
    mPowerball=0;
}

// set mBALL equals to the value inside the constructor.
PowerballTicket::PowerballTicket(int ball1, int ball2, int ball3, int ball4, int ball5, int powerball)
{
    mBall1= ball1;
    mBall2= ball2;
    mBall3= ball3;
    mBall4= ball4;
    mBall5= ball5;
    mPowerball= powerball;
}

// return the mBalls.
int PowerballTicket::getBall1()
{
    return mBall1;
}
int PowerballTicket::getBall2()
{
    return mBall2;
}
int PowerballTicket::getBall3()
{
    return mBall3;
}
int PowerballTicket::getBall4()
{
    return mBall4;
}
int PowerballTicket::getBall5()
{
    return mBall5;
}
int PowerballTicket::getPowerball()
{
    return mPowerball;
}

