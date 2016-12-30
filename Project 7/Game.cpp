//
//  Game.cpp
//  HandHomework
//
//  Created by Howard Stahl on 12/6/15.
//  Copyright © 2015 Howard Stahl. All rights reserved.
//

#include "Game.h"
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "RandomNumber.h"
#include <string>
#include <iostream>

// CS 31 Students need to complete this class.
// Please read over the assignment and the TODO comments in the accompanying
// implementation file for further instructions.
namespace cs31
{
    
    Game::Game()
    {
        mOutcome=NOOUTCOME;
        mPlayerStood=false;
        // TODO : set the outcome of the game initially
        //        set the player's turn is not yet over
    }
    
    Game::Game( Player player, Player dealer ): Game( )
    {
        mPlayer = player;
        mDealer = dealer;
    }
    
    // did the Player win?
    bool Game::playerWon()
    {
        return( mOutcome == PLAYERWON );
    }
    
    // did the Player lose?
    bool Game::playerLost()
    {
        return( mOutcome == PLAYERLOST );
    }
    
    // did the Player and the Dealer tie?
    bool Game::playerTied( )
    {
        return( mOutcome == TIED );
    }
    
    void Game::deal()
    {
        mDeck.shuffleDeck();
        mPlayer.acceptCard(mDeck.dealCard() );
        mDealer.acceptCard(mDeck.dealCard() );
        
        
        // TODO : shuffle deck
        //        deal two cards to the player and two to the dealer
    }
    
    void Game::playerHits( )
    {

      
            mPlayer.acceptCard(mDeck.dealCard() );
            
        
        // TODO : deal another card to the player
    }
    
    // let the Game know that the Player's turn is over
    void Game::playerStands()
    {
        mPlayerStood = true;
    }
    
    // has the Player's turn ended?
    bool Game::playerStood() const
    {
        return( mPlayerStood );
    }
    
    void Game::dealerHits( )
    {
        if(mDealer.handcount( )<17)
        {
           mDealer.acceptCard(mDeck.dealCard() );
        }
        
        // TODO : deal another card to the dealer
    }
    
    void Game::dealerStands( )
    {
        if(dealerBusted())
        {
            mOutcome=PLAYERWON;
        }
        else if(playerBusted())
        {
            mOutcome=PLAYERLOST;
        }
        else if(mPlayer.handcount()> mDealer.handcount())
        {
            
            mOutcome = PLAYERWON;
        }
        else if (mPlayer.handcount()< mDealer.handcount())
        {
            mOutcome=PLAYERLOST;
        }
        else
        {
            mOutcome=TIED;
        }
    
        
        // TODO : since the game is now over, determine the outcome
        //        store the outcome in the member mOutcome
    }
    
    bool Game::dealerBusted( ) const
    {
        bool result = false;
        if (mDealer.handcount() >21)
        {
            result = true;
        }
        
        // TODO : did the dealer go over 21?
   
        return( result );
    }
    
    bool Game::playerBusted( ) const
    {
         bool result=false;
        if (mPlayer.handcount() >21)
        {
            result=true;
            
        }
        // TODO : did the player go over 21?
     
        return( result );
    }
    
    void Game::dealerPlays()
    {
        // TODO : if the player hasn't busted,
        //        play the dealer's hand by taking cards until the
        //        dealer's cards total 17 or more or the dealer busts
        
        // let the Game know that play has ended
        while(mDealer.handcount()< 17)
        {
            mDealer.acceptCard(mDeck.dealCard());
            
        }
        dealerStands();
    }
    
    bool Game::playerHasBlackJack( ) const
    {
        bool result = false;
        if(mPlayer.hasBlackJack( ))
        {
            result =true;
        }
        // TODO : does the player have blackjack?h
        
        return( result );
    }
    
    bool Game::dealerHasBlackJack( ) const
    {
        bool result = false;
        if (mDealer.hasBlackJack( ))
        {
            result=true;
        }
        // TODO : does the dealer have blackjack?
        
        return( result );
    }
    
    //
    // ALL THE CODE BELOW THIS POINT SHOULD NOT BE CHANGED!
    //
    void Game::display( std::string s , bool allCards )
    {
        // when allCards is true  --> show all dealer cards
        // otherwise just show the one turned up dealer card
        // and then display the passed message at the bottom of the screen, if supplied
        using namespace std;
        int dealerCount = mDealer.handcount();
        int playerCount = mPlayer.handcount();
        cout << "DEALER'S HAND:" << endl;
        if (allCards)
        {
            cout << mDealer << endl;
        }
        else
        {
            cout << mDealer.getCard(0) << endl;
        }
        if (dealerBusted())
        {
            cout << "          --->dealer busted!" << endl;
        }
        else if (allCards)
        {
            cout << "          --->" << dealerCount << endl;
        }
        cout << endl;
        cout << "PLAYER'S HAND:" << endl;
        cout << mPlayer << endl;
        if (playerBusted())
        {
            cout << "          --->player busted!" << endl;
        }
        else if (allCards)
        {
            cout << "          --->" << playerCount << endl;
        }
        
        if (s != "")
            cout << s << endl;
    }
    
    
    
    
}
