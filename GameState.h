#pragma once

class GameState {
private:
public:
	virtual void update(oa deltaTime);
	virtual bool isGameOver();
	virtual void spawnNewTetromino();

};

