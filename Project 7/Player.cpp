//
//  Hand.cpp
//  HandHomework
//
//  Created by Howard Stahl on 4/30/15.
//  Copyright (c) 2015 Howard Stahl. All rights reserved.
//

#include "Player.h"
#include <stdexcept>

// CS 31 Students need to complete this class.
// Please read over the assignment and the TODO comments in the accompanying
// implementation file for further instructions.
namespace cs31
{
    
    Player::Player( )
    {
        // The Player has no Cards in his hand
        myNumberOfCards = 0;
    }
    
    std::ostream& operator <<( std::ostream& outs, const Player & p )
    {
        using namespace std;
        
        for(int i=0; i<=p.cardCount();i++)
        {
            outs<< p.myCards[i]<<endl;
        }
    
        // TODO : print out all the actual cards in the array myCards
        return( outs );
    }
    int Player::cardCount() const
    {
        return(myNumberOfCards);
    }
    
    void Player::acceptCard(Card c)
    {
        if(cardCount( )<12)
        {
            myCards[cardCount()] = c;
            myNumberOfCards++;
        }
        else
        {
          throw std::logic_error( "can't accept card anymore" );
        }
            
        // TODO : as long as there is space in the array myCards, place Card c into myCards
        //        if there is not enough space for another card, throw an exception
    }
    
    Card Player::getCard( int index ) const
    {
        Card c;
        if(index>=0 || index < cardCount())
        {
            c=myCards[index];
        }
        else
        {
            std::logic_error e( "your requested card is invaild" );
            throw(e);
        }
        
        // TODO : return the requested card
        //        if the index is bad, throw an exception
      
        return( c );
    }
    
    int  Player::handcount( ) const
    {
        int total = 0;
        int i;
        for(i=0; i<cardCount();i++)
        {
            total=total+myCards[i].count();
        
        }
        int j=0;
        while(j<=cardCount())
        {
            if(total <= 11 && myCards[j].getFace() == ACE)
            {

                total=total+11 ;
                break;
            }
            j++;
        }
        
        
        // TODO : total up the points in this player's hand
        //        you will need to figure out how to handle Ace's that might be worth 1 or 11
     
        return( total );
    }
    
    
    bool Player::hasBlackJack( ) const
    {
        bool result = false;
        if (myNumberOfCards == 2 && handcount() == 21)
        {
            result = true;
        }
        return( result );
    }
    
}
