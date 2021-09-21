#include "raylib.h"

int main(void) {
	// init
	const int screenW = 500;
	const int screenH = 500;
	int tetrisBoard[10][20];


	InitWindow(screenW, screenH, "Tetris");
	Image blueImg = LoadImage("sprites/blue.png");
	Texture2D blueTexture = LoadTextureFromImage(blueImg);
	UnloadImage(blueImg);
	Image darkblueImg = LoadImage("sprites/darkblue.png");
	Texture2D darkblueTexture = LoadTextureFromImage(darkblueImg);
	UnloadImage(darkblueImg);
	Image greenImg = LoadImage("sprites/green.png");
	Texture2D greenTexture = LoadTextureFromImage(greenImg);
	UnloadImage(greenImg);
	Image orangeImg = LoadImage("sprites/orange.png");
	Texture2D orangeTexture = LoadTextureFromImage(orangeImg);
	UnloadImage(orangeImg);
	Image pinkImg = LoadImage("sprites/pink.png");
	Texture2D pinkTexture = LoadTextureFromImage(pinkImg);
	UnloadImage(pinkImg);
	Image redImg = LoadImage("sprites/red.png");
	Texture2D redTexture = LoadTextureFromImage(redImg);
	UnloadImage(redImg);
	Image yellowImg = LoadImage("sprites/yellow.png");
	Texture2D yellowTexture = LoadTextureFromImage(yellowImg);
	UnloadImage(yellowImg);

	SetTargetFPS(60);

	class Board {
	public:
		Vector2 pos = { (float)100, (float)100 };
		int matrix[24][10] = {{1,0,0,0,0,0,0,0,0,1},
							  {1,0,0,0,0,0,0,0,0,0},
							  {1,0,0,0,0,0,0,0,0,0},
							  {1,0,0,0,0,0,0,0,0,0},
							  {1,0,0,0,0,0,0,0,0,1},
							  {0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,1,0,0,0,0,0,0},
							  {0,0,0,2,0,0,0,0,0,0},
							  {0,0,0,3,0,0,0,0,0,0},
							  {0,0,0,4,0,0,0,0,0,0},
							  {0,0,0,5,0,0,0,0,0,0},
							  {0,0,0,6,0,0,0,0,0,0},
							  {0,0,0,7,0,0,0,0,0,0},
							  {0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,0,0,0,0,0},
							  {1,0,0,0,0,0,0,0,0,1},
		};
	};

	class CurrentTetromino {
	public:
		int tetromino;
		int grid_x, grid_y;
		int rotationState = 1;
	};

	//TODO: all tetrominos :)
	//      set shape int to the colour so: in T set to 6 instead of 1
	class I {
	public:
		int texture = 0;
		bool shape1[4][4] = { {0,0,0,0},
							  {1,1,1,1},
							  {0,0,0,0},
							  {0,0,0,0} };

		bool shape2[4][4] = { {0,0,1,0},
							  {0,0,1,0},
							  {0,0,1,0},
							  {0,0,1,0} };

		bool shape3[4][4] = { {0,0,0,0},
							  {0,0,0,0},
							  {1,1,1,1},
							  {0,0,0,0} };

		bool shape4[4][4] = { {0,1,0,0},
							  {0,1,0,0},
							  {0,1,0,0},
							  {0,1,0,0} };
	};
	class T {
	public:
		int texture = 1;
		bool shape1[3][3] = { {0,1,0},
							  {1,1,1},
							  {0,0,0} };

		bool shape2[3][3] = { {0,1,0},
							  {0,1,1},
							  {0,1,0} };

		bool shape3[3][3] = { {0,0,0},
							  {1,1,1},
							  {0,1,0} };

		bool shape4[3][3] = { {0,1,0},
							  {1,1,0},
							  {0,1,0} };
	};

	T t_piece;
	I i_piece;
	Board board;
	CurrentTetromino tetromino;
	// Main game loop
	while (!WindowShouldClose()) {
		
		// TODO: Handle physics, redraw, input

		/*if (IsKeyDown(KEY_RIGHT)) t.pos.x += 2.0f;
		if (IsKeyDown(KEY_LEFT)) t.pos.x -= 2.0f;
		if (IsKeyDown(KEY_UP)) t.pos.y -= 2.0f;
		if (IsKeyDown(KEY_DOWN)) t.pos.y += 2.0f;
		if (IsKeyDown(KEY_Z)) tetrominoPos.y += 2.0f;
		if (IsKeyDown(KEY_X)) tetrominoPos.y += 2.0f;
		if (IsKeyDown(KEY_C)) tetrominoPos.y += 2.0f;
		if (IsKeyDown(KEY_ENTER)) tetrominoPos.y += 2.0f;*/

		/*switch (tetromino.tetromino)
		{
		case 1:
			DrawTexture(blueTexture, board.pos.x + (float)((i + 1) * 12), board.pos.y + (float)((j + 1) * 12), WHITE);
			break;
		case 2:
			DrawTexture(darkblueTexture, board.pos.x + (float)((i + 1) * 12), board.pos.y + (float)((j + 1) * 12), WHITE);
			break;
		case 3:
			DrawTexture(greenTexture, board.pos.x + (float)((i + 1) * 12), board.pos.y + (float)((j + 1) * 12), WHITE);
			break;
		case 4:
			DrawTexture(orangeTexture, board.pos.x + (float)((i + 1) * 12), board.pos.y + (float)((j + 1) * 12), WHITE);
			break;
		case 5:
			DrawTexture(pinkTexture, board.pos.x + (float)((i + 1) * 12), board.pos.y + (float)((j + 1) * 12), WHITE);
			break;
		case 6:
			DrawTexture(redTexture, board.pos.x + (float)((i + 1) * 12), board.pos.y + (float)((j + 1) * 12), WHITE);
			break;
		case 7:
			DrawTexture(yellowTexture, board.pos.x + (float)((i + 1) * 12), board.pos.y + (float)((j + 1) * 12), WHITE);
			break;
		default:
			break;*/



		BeginDrawing();
			ClearBackground(BLACK);
			for (int i = 0; i < 10; i++)
			{
				//set j to 4 for normal, else 0 for debugging
				for (int j = 0; j < 24; j++)
				{
					switch (board.matrix[j][i])
					{
					case 1:
						DrawTexture(blueTexture, board.pos.x + (float)((i+1)*12), board.pos.y + (float)((j + 1) * 12), WHITE);
						break;
					case 2:
						DrawTexture(darkblueTexture, board.pos.x + (float)((i + 1) * 12), board.pos.y + (float)((j + 1) * 12), WHITE);
						break;
					case 3:
						DrawTexture(greenTexture, board.pos.x + (float)((i + 1) * 12), board.pos.y + (float)((j + 1) * 12), WHITE);
						break;
					case 4:
						DrawTexture(orangeTexture, board.pos.x + (float)((i + 1) * 12), board.pos.y + (float)((j + 1) * 12), WHITE);
						break;
					case 5:
						DrawTexture(pinkTexture, board.pos.x + (float)((i + 1) * 12), board.pos.y + (float)((j + 1) * 12), WHITE);
						break;
					case 6:
						DrawTexture(redTexture, board.pos.x + (float)((i + 1) * 12), board.pos.y + (float)((j + 1) * 12), WHITE);
						break;
					case 7:
						DrawTexture(yellowTexture, board.pos.x + (float)((i + 1) * 12), board.pos.y + (float)((j + 1) * 12), WHITE);
						break;
					default:
						break;
					}
				}
			}
;		EndDrawing();
	}

	CloseWindow();

	return 0;
}