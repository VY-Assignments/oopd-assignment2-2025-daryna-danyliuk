#pragma once

class ScoreManager {
private:
    int score = 0;
    int linesCleared = 0;

public:
    void addLines(int count) {
        switch (count) {
        case 1: score
            += 100;
            break;
        case 2:
            score += 300;
            break;
        case 3:
            score += 500;
            break;
        case 4:
            score += 800;
            break;
        default: break;
        }
        linesCleared += count;
    }

    int getScore() const {
        return score;
    }
    int getLinesCleared() const {
        return linesCleared;
    }
    void reset() {
        score = 0;
        linesCleared = 0;
    }
};