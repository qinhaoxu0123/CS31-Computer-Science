//
//  PowerballLottery.cpp
//  Project 5
//
//  Created by Qinhao Xu on 2/22/16.
//  Copyright © 2016 Qinhao Xu. All rights reserved.
//

#include "PowerballLottery.h"
#include "RandomNumber.h"
#include "PowerballTicket.h"
#include <iostream>
#include <cassert>

// using RnadonNumber.h to generate random values for each ball.
PowerballLottery::PowerballLottery()
{
    RandomNumber r( 1, 69 );
    mBall1 = r.random();
    mBall2 = r.random();
    while(mBall1==mBall2)
    {
        mBall2 = r.random();
    }
    mBall3 = r.random();
    while(mBall1==mBall3 || mBall2==mBall3)
    {
        mBall3 = r.random();
    }
    mBall4 = r.random();
    while(mBall1==mBall4 || mBall2==mBall4||mBall3==mBall4)
    {
        mBall4 = r.random();
    }
    mBall5 = r.random();
    
    while (mBall1==mBall5 || mBall2==mBall5||mBall3==mBall5||mBall4==mBall5)
    {
        mBall5 = r.random();
    }
    RandomNumber p(1,26);
    mPowerball = p.random();
    
}
PowerballLottery::PowerballLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int powerball)
{
    mBall1= ball1;
    mBall2= ball2;
    mBall3= ball3;
    mBall4= ball4;
    mBall5= ball5;
    mPowerball= powerball;
}

// return the mBall to the each getBall();
int PowerballLottery::getBall1()
{
    return mBall1;
}
int PowerballLottery::getBall2()
{
    return mBall2;
}
int PowerballLottery::getBall3()
{
    return mBall3;
}
int PowerballLottery::getBall4()
{
    return mBall4;
}
int PowerballLottery::getBall5()
{
    return mBall5;
}
int PowerballLottery::getPowerball()
{
    return mPowerball;
}


// int another six balls by giving the new name, and then give the random values
PowerballTicket PowerballLottery::quickPick( )
{
    
    int mBal1, mBal2, mBal3, mBal4, mBal5, mPowerbal;
    RandomNumber r( 1, 69 );
    mBal1 = r.random();
    mBal2 = r.random();
    while(mBal1==mBal2)
    {
        mBal2 = r.random();
    }
    mBal3 = r.random();
    while(mBal1==mBal3 || mBal2==mBal3)
    {
        mBal3 = r.random();
    }
    mBal4 = r.random();
    while(mBal1==mBal4 || mBal2==mBal4||mBal3==mBal4)
    {
        mBal4 = r.random();
    }
    mBal5 = r.random();
    
    while (mBal1==mBal5 || mBal2==mBal5||mBal3==mBal5||mBal4==mBal5)
    {
        mBal5 = r.random();
    }
    RandomNumber p(1,26);
    mPowerbal = p.random();
  // using type temp for PowerballTicket to return the type.
    PowerballTicket temp(mBal1, mBal2, mBal3, mBal4, mBal5, mPowerbal);
    return temp;
   
}
PowerballLottery::WinningPossibility PowerballLottery::checkTicket(PowerballTicket ticket)
{
    // check the first five balls, if they match with the PowerballLottery then implenment by 1.
    WinningPossibility result;
    int numberofmatch=0;
    if(ticket.getBall1()==getBall1()||ticket.getBall1()==getBall2()||ticket.getBall1()==getBall3()||ticket.getBall1()==getBall4()||ticket.getBall1()==getBall5())
    {
        numberofmatch++;
    }
    if(ticket.getBall2()==getBall1()||ticket.getBall2()==getBall2()||ticket.getBall2()==getBall3()||ticket.getBall2()==getBall4()||ticket.getBall2()==getBall5())
    {
        numberofmatch++;
    }
    if(ticket.getBall3()==getBall1()||ticket.getBall3()==getBall2()||ticket.getBall3()==getBall3()||ticket.getBall3()==getBall4()||ticket.getBall3()==getBall5())
    {
        numberofmatch++;
    }
    if(ticket.getBall4()==getBall1()||ticket.getBall4()==getBall2()||ticket.getBall4()==getBall3()||ticket.getBall4()==getBall4()||ticket.getBall5()==getBall5())
    {
        numberofmatch++;
    }
    if(ticket.getBall5()==getBall1()||ticket.getBall5()==getBall2()||ticket.getBall5()==getBall3()||ticket.getBall5()==getBall4()||ticket.getBall5()==getBall5())
    {
        numberofmatch++;
    }
    
    // check the powerball in the ticket with the lottery ticket, and then return the result;
    if(ticket.getPowerball()==getPowerball())
    {
        switch(numberofmatch)
        {
            case 1:
            result= ONEPLUSPOWERBALL;
            break;
            case 2:
            result= TWOPLUSPOWERBALL;
            break;
            case 3:
            result= THREEPLUSPOWERBALL;
            break;
            case 4:
            result= FOURPLUSPOWERBALL;
            break;
            case 5:
            result= FIVEPLUSPOWERBALL;
            break;
            default:
                result= POWERBALL;
            break;
        }
            
    }
    
    else
    {
        
        switch(numberofmatch)
        {
        case 3:
                result= THREE;
                break;
        case 4:
                result= FOUR;
                break;
        case 5:
                result= FIVE;
                break;
        default:
                result=NOTWINNING;
                break;
        
        }
    }
    return result;
}
void PowerballLottery::printWhatHappened(PowerballTicket ticket)
{
    // set the winnningpossibility result = checkTicket(ticket) from the previous function;
    WinningPossibility result = checkTicket(ticket);
    switch(result)
    {
        case ONEPLUSPOWERBALL:
            cout << "You matched one ball plus the powerball.  Congratulations!" << endl;
            break;
        case TWOPLUSPOWERBALL:
            cout << "You matched two balls plus the powerball.  Congratulations!" << endl;
            break;
        case THREEPLUSPOWERBALL:
            cout << "You matched three balls plus the powerball.  Congratulations!" << endl;
            break;
        case FOURPLUSPOWERBALL:
            cout << "You matched four balls plus the powerball.  Congratulations!" << endl;
            break;
        case FIVEPLUSPOWERBALL:
            cout << "You won the jackpot - all balls plus the powerball.  Congratulations!" << endl;
            break;
        case POWERBALL:
            cout << "You matched just the powerball.  Congratulations!" << endl;
            break;
        case THREE:
            cout << "You matched three balls but not the powerball.  Congratulations!" << endl;
            break;
        case FOUR:
            cout << "You matched four balls but not the powerball.  Congratulations!" << endl;
            break;
        case FIVE:
            cout << "You matched five balls but not the powerball.  Congratulations!" << endl;
            break;
        case NOTWINNING:
            cout <<"You didn't win anything.  Please buy another ticket!" << endl;
            break;
            
            
    }
    
}

