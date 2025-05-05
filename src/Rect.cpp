#include "include/Rect.h"



Rec::Rec(Vector2f pos, Vector2f size, Color color, float speed, float gravity, float JSS)
{
	m_Size = size;
	m_Shape.setSize(size);
	m_Shape.setFillColor(color);
	m_Position = pos;
	m_Shape.setOrigin(m_Size.x / 2.0f, m_Size.y / 2.0f);

	m_Speed = speed;
	m_Gravity = gravity;
	m_JumpStartSpeed = JSS;
	m_Bottom = m_Position.y;

	m_Shape.setPosition(m_Position);
}

RectangleShape Rec::getShape()
{
	return m_Shape;
}

void Rec::update(float deltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_Position.x -= m_Speed * deltaTime;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		m_Position.x += m_Speed * deltaTime;
	}

	m_Shape.setPosition(m_Position);
}