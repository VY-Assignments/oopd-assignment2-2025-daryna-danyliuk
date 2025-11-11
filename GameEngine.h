#pragma once
#include <memory>
#include "ScoreManager.h"
#include "SaveManager.h"
#include "Board.h"
#include "Tetromino.h"
#include "TetrominoFactory.h"
#include "GameState.h"

class GameEngine {
public:
    GameEngine();
    void start();
    void resume();
    void update(float deltaTime);
    void changeState(std::unique_ptr<GameState> newState);
    void moveTetromino(int dx, int dy);
    void rotateTetrominoCW();
    void rotateTetrominoCCW();
    void dropTetromino();
    void lockTetromino();
    void clearFullLines();

    GameState* getCurrentState() const {
        return currentState.get();
    }
    const Board& getBoard() const {
        return board; 
    }
    const Tetromino& getCurrentTetromino() const { 
        return currentTetromino; 
    }
    Board& getBoardRef() { 
        return board; 
    }
    Tetromino& getCurrentTetrominoRef() { 
        return currentTetromino; 
    }
    void setCurrentTetromino(const Tetromino& t) { currentTetromino = t; }
    TetrominoFactory& getFactory() {
        return factory; 
    }

private:
    Board board;
    Tetromino currentTetromino;
    ScoreManager scoreManager;
    SaveManager saveManager;
    TetrominoFactory factory;
    std::unique_ptr<GameState> currentState;
    bool isRunning = false;
};