/*******************************************************************************************
*
********************************************************************************************/

#include <cmath>
#include <vector>
#include <cstdlib>
#include <string>
#include <map>
#include "raylib.h"

using namespace std;

#define SCREEN_WIDTH  1024
#define SCREEN_HEIGHT 800

#define GETSET(type, field) protected: type field; public: type get_##field() { return field; } void set_##field(type value) { field = value; }

//////////////////////////////////////////////////
// ENTITY CLASS
//////////////////////////////////////////////////
class Entity {
private:
	GETSET(Texture2D, texture)
	GETSET(Vector2, pos)
	GETSET(Vector2, vel)
	GETSET(Vector2, size)
	GETSET(float, rotation)
	GETSET(float, rotation_vel)
	GETSET(float, radius)
	GETSET(bool, visible)
	
	float scale;

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
		size.x = fabs(texture.width * scale);
		size.y = fabs(texture.height* scale);
		radius = size.x * 0.8f;
	}

	virtual void update(float delta_time) {	}

	void draw() {
		Rectangle src = {0, 0, (float)texture.width, (float)texture.height};
		Rectangle dst = {pos.x, pos.y, size.x, size.y};
		Vector2 origin = {size.x/2, size.y/2};

		DrawTexturePro(texture, src, dst, origin, rotation+90, WHITE);
	}

	void screen_wrap() {
		if (pos.x < -size.x/2) {
			pos.x = SCREEN_WIDTH + size.x/2;
		} else
		if (pos.x > SCREEN_WIDTH + size.x/2) {
			pos.x = -size.x/2;
		}
		
		if (pos.y < -size.y/2) {
			pos.y = SCREEN_HEIGHT + size.y/2;
		} else
		if (pos.y > SCREEN_HEIGHT + size.y/2) {
			pos.y = -size.y/2;
		}
	}
};


//////////////////////////////////////////////////
// ASTEROID CLASS
//////////////////////////////////////////////////
class Asteroid : public Entity {
public:
	Asteroid() { }
	Asteroid(Texture2D texture, Vector2 pos, Vector2 vel) : Entity(texture, pos, vel) { };

	void update(float delta_time) override {
		rotation += rotation_vel * delta_time;

		pos.x += vel.x * delta_time;
		pos.y += vel.y * delta_time;

		screen_wrap();
	}
};

//////////////////////////////////////////////////
// PLAYER CLASS
//////////////////////////////////////////////////
class Player : public Entity {
public:
	Player() { }
	Player(Texture2D texture, Vector2 pos, Vector2 vel) : Entity(texture, pos, vel) { };

	void update(float delta_time) override {
		if (IsKeyDown(KEY_W)) {
			vel = {0, -400};
			rotation = 270;
		} else
		if (IsKeyDown(KEY_S)) {
			vel = {0, 400};
			rotation = 90;
		} else
		if (IsKeyDown(KEY_D)) {
			vel = {400, 0};
			rotation = 0;
		} else
		if (IsKeyDown(KEY_A)) {
			vel = {-400, 0};
			rotation = 180;
		}

		pos.x += vel.x * delta_time;
		pos.y += vel.y * delta_time;

		screen_wrap();
	}
};

//////////////////////////////////////////////////
// PLAYER CLASS
//////////////////////////////////////////////////
class Game {
private:
	Player ship;
	vector<Asteroid> asteroids;
	map<string, Texture2D> cache;
	float launch_counter;
	float launch_delay;

public:
	Game() {
		// set up the window
		InitWindow(1024, 800, "Raylib CPP");
		SetTargetFPS(60);
		ToggleFullscreen();

		launch_counter = 0;
		launch_delay = 1;
	}

	Texture2D get_texture_cache(string key) {
		if (cache.count(key) == 0) {
			cache[key] = LoadTexture(key.c_str());
		}
		return cache[key];
	}

	void init_game() {
		ship = Player(get_texture_cache("assets/nave.png"), 
		              {SCREEN_WIDTH/2, SCREEN_HEIGHT/2}, {0,0});
		ship.set_scale(2);
	}

	void launch_asteroid() {
		Texture2D texture = get_texture_cache("assets/asteroid.png");
		Vector2 vel = {(float)(rand() % 601 - 300), (float)(rand() % 601 - 300)};
		Asteroid obj = Asteroid(texture, {SCREEN_WIDTH/2, SCREEN_HEIGHT/2}, vel);
		obj.set_rotation_vel(rand() % 100 - 50);
		asteroids.push_back(obj);
	}
	
	void update_game(float delta_time) {
		ship.update(delta_time);

		launch_counter += delta_time;
		if (launch_counter > launch_delay) {
			launch_counter -= launch_delay;
			launch_asteroid();
			
			launch_delay -= 0.01f;
			if (launch_delay < 0.3f) 
				launch_delay = 0.3f;
		}

		for (Asteroid& e : asteroids) {
			e.update(delta_time);
		}
	}

	void run() {
		init_game();

		// game loop
		while (!WindowShouldClose())
		{
			update_game(GetFrameTime());

			// drawing
			BeginDrawing();
				ClearBackground(BLACK);
				//DrawText("Hello Raylib UTF Game Group", 200,200,20,WHITE);
				
				ship.draw();
				for (Asteroid& e : asteroids) {
					e.draw();
				}

				DrawFPS(SCREEN_WIDTH - 100, 20);
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