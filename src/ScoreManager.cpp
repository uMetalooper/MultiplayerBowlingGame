#include "ScoreManager.h"

void ScoreManager::score()
{
    int frameIndex = 0;
    for (int frame = 1; frame < 11; frame++)
    {
        if (!isBowled(frameIndex))
        {
            break;
        }
        else if (isStrike(frameIndex))
        {
            if (isCompleteStrike(frameIndex))
                frameScores[frame] = frameScores[frame - 1] + 10 + strikeBonus(frameIndex);
            else
                continue;
            frameIndex++;
        }
        else if (isSpare(frameIndex))
        {
            if (isCompleteSpare(frameIndex))
                frameScores[frame] = frameScores[frame - 1] + 10 + spareBonus(frameIndex);
            else
                continue;
            frameIndex += 2;
        }
        else if (isCompleteFrame(frameIndex))
        {
            frameScores[frame] = frameScores[frame - 1] + sumOfPinsInFrame(frameIndex);
            frameIndex += 2;
        }
    }
}