#pragma once

#include <SFML/Graphics.hpp>
#include "Platform.h"
#include <vector>

using namespace sf;

class Rec
{
private:
	Vector2f m_Size;
	Vector2f m_Position;
	RectangleShape m_Shape;
	float m_Speed;
	float m_Gravity;
	float m_JumpStartSpeed;
	float m_JumpSpeed;
	float m_Bottom;
	bool inJump = false;
	bool up = false;
	bool m_OnPlatform;
	float StartPosY;
	std::vector<Platform> m_Platforms;
public:
	Rec(Vector2f pos, Vector2f size, Color color, float speed, float gravity, float JSS, std::vector<Platform> platforms);
	void update(float deltaTime);
	RectangleShape getShape();
};