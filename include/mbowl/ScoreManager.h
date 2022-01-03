#include <iostream>

class ScoreManager
{
public:
    int rolls[21];
    int currentRoll;
    int frameScores[11];

public:
    ScoreManager() : currentRoll(0)
    {
        for (int i = 0; i < 21; i++)
        {
            rolls[i] = -1;
        }
        frameScores[0] = 0;
        for (int i = 1; i < 11; i++)
        {
            frameScores[i] = -1;
        }
    }

    void roll(int pins)
    {
        rolls[currentRoll++] = pins;
    }

    void score();

    void printRolls()
    {
        for (int i = 0; i < 21; i++)
        {
            std::cout << rolls[i] << "--";
        }
    }

private:
    bool isBowled(int frameIndex)
    {
        return rolls[frameIndex] != -1;
    }

    bool isStrike(int frameIndex)
    {
        return rolls[frameIndex] == 10;
    }

    bool isCompleteStrike(int frameIndex)
    {
        return isBowled(frameIndex + 1) && isBowled(frameIndex + 2);
    }

    int strikeBonus(int frameIndex)
    {
        return rolls[frameIndex + 1] + rolls[frameIndex + 2];
    }

    bool isSpare(int frameIndex)
    {
        return (rolls[frameIndex] + rolls[frameIndex + 1] == 10);
    }

    bool isCompleteSpare(int frameIndex)
    {
        return isBowled(frameIndex + 2);
    }

    int spareBonus(int frameIndex)
    {
        return rolls[frameIndex + 2];
    }

    bool isCompleteFrame(int frameIndex)
    {
        return rolls[frameIndex + 1] != -1;
    }

    int sumOfPinsInFrame(int frameIndex)
    {
        return rolls[frameIndex] + rolls[frameIndex + 1];
    }
};