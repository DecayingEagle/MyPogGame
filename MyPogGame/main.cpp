#include "raylib.h"

int main(void) {
	// init
	const int screenW = 500;
	const int screenH = 500;

	InitWindow(screenW, screenH, "gmae!!!!");
	SetTargetFPS(60);

	// Main game loop
	while (!WindowShouldClose()) {
		// TODO: Handle physics, redraw

		BeginDrawing();
			ClearBackground(BLACK);
			DrawText("tis will tetris", 0, 0, 20, GREEN);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}