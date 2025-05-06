#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Platform
{
private:
	RectangleShape m_Shape;
	Vector2f m_Size;
	Vector2f m_Position;
public:
	Platform(Vector2f size, Vector2f pos, Color color = Color::White);
	RectangleShape getShape();
	Vector2f getSize();
	Vector2f getPosition();
};