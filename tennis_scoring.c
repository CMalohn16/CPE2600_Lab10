/**
 * @file tennis_scoring.c
 * @author Charlie Malohn
 * @class CPE 2600 - 121
 * @date 11/12/2026
 * @brief Important functions for playing signal tennis
 */

#include "tennis_scoring.h"

/**
 * @brief Updates the score like a tennis game and prints it out
 * @param myPoint True if THIS process receives the points, False if it missed
 */
bool update_score(bool myPoint)
{
    static int myScore = 0;
    static int opposingScore = 0;
    static bool myAdvantage = false;
    static bool opposingAdvantage = false;

    bool myWin = false;
    bool opposingWin = false;
    int awardedPoints = 15;

    //Determines scoring including wins and advantages
    if (myPoint)
    {
        if (myScore == 30)
        {
            awardedPoints = 10;
        }
        else if (myScore == 40)
        {
            awardedPoints = 0;
            if (opposingScore == 40)
            {
                if (opposingAdvantage)
                {
                    opposingAdvantage = false;
                }
                else
                {
                    if (myAdvantage)
                    {
                        myWin = true;
                    }
                    else
                    {
                        myAdvantage = true;
                    }
                }
            }
            else
            {
                myWin = true;
            }
        }
        myScore += awardedPoints;
    }
    else
    {
        if (opposingScore == 30)
        {
            awardedPoints = 10;
        }
        else if (opposingScore == 40)
        {
            awardedPoints = 0;
            if (myScore == 40)
            {
                if (myAdvantage)
                {
                    myAdvantage = false;
                }
                else
                {
                    if (opposingAdvantage)
                    {
                        opposingWin = true;
                    }
                    else
                    {
                        opposingAdvantage = true;
                    }
                }
            }
            else
            {
                opposingWin = true;
            }
        }
        opposingScore += awardedPoints;
    }
    printf("-----\nScore\n  Me: %d\n  Opponent: %d\n-----\n", myScore, opposingScore);
    //Exit on win so the next ball is never served
    if (myWin)
    {
        printf("Winner\n");
        exit(0);
    }
    else if (opposingWin)
    {
        printf("Better luck next time\n");
        exit(0);
    }
    else
    {
        if (myAdvantage)
        {
            printf("Advantage\n");
        }
        else if (myScore == 40 && opposingScore == 40 && !opposingAdvantage)
        {
            printf("Deuce\n");
        }
        else
        {
            printf("\n");
        }
    }
}

/**
 * Serves the ball
 * @param id PID to serve to
 */
void serve(int id)
{
    union sigval sigValue;
    sigValue.sival_int = 1;
    printf("Serve\n");
    sigqueue(id, BALL, sigValue);
}