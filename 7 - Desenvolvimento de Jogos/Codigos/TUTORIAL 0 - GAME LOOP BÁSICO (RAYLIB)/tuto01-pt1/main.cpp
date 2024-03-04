/*******************************************************************************************
* Basic 2D game with raylib.
* 
* To build: 
*		Ctrl + Shift + B
* To run: 
* 		$ ./main
* 
********************************************************************************************/

#include <cmath>
#include "raylib.h"

#define SCREEN_WIDTH  1024
#define SCREEN_HEIGHT 800

////////////////////////////////////////////////////////////////////////
// ENTITY CLASS
////////////////////////////////////////////////////////////////////////

class Entity {
private:
	Texture2D texture;
	Vector2 pos;
	Vector2 vel;
	Vector2 size;
	float scale;
	float rotation;

public:
	Entity() {}

	Entity(Texture2D texture, Vector2 pos, Vector2 vel) {
		this->texture = texture;
		this->pos = pos;
		this->vel = vel;
		this->size.x = texture.width;
		this->size.y = texture.height;
		this->scale = 1.0f;
		this->rotation = 0.0f;
	}	

	void set_scale(float scale) {
		this->scale = scale;
		this->size.x = abs(this->texture.width * scale);
		this->size.y = abs(this->texture.height* scale);
	}

	void update() {
		if (IsKeyDown(KEY_W))
			set_scale(scale + 0.1f);
		else 
		if (IsKeyDown(KEY_S))
			set_scale(scale - 0.1f);

		if (IsKeyDown(KEY_D))
			rotation += 0.1f;
		else 
		if (IsKeyDown(KEY_A))
			rotation -= 0.1f;
	}

	void draw() {
		Rectangle src = {0, 0, (float)texture.width, (float)texture.height};
		Rectangle dst = {pos.x, pos.y, size.x, size.y};
		Vector2 origin = {size.x/2, size.y/2};

		DrawTexturePro(texture, src, dst, origin, rotation+90, WHITE);
	}
};

////////////////////////////////////////////////////////////////////////
// GAME CLASS
////////////////////////////////////////////////////////////////////////

class Game {
private:
	Entity ship;

public:
	Game() {
		// set up the window
		InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Basic Game");
	}

	void init_game() {
		ship = Entity(LoadTexture("assets/nave.png"), {SCREEN_WIDTH/2, SCREEN_HEIGHT/2}, {10,10});
		ship.set_scale(2);
	}

	void run() {
		init_game();

		// game loop
		while (!WindowShouldClose())
		{
			ship.update();

			// drawing
			BeginDrawing();
				ClearBackground(BLACK);
				//DrawText("Hello Raylib UTF Game Group", 200,200,20,WHITE);
				ship.draw();
			
			EndDrawing();
		}

		// cleanup
		CloseWindow();
	}
};

int main () {
	Game game;
	game.run();

	return 0;
}