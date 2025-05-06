#include "include/Platform.h"


Platform::Platform(Vector2f size, Vector2f pos, Color color)
{
	m_Size = size;
	m_Position = pos;

	m_Shape.setFillColor(color);
	m_Shape.setSize(size);
	m_Shape.setOrigin(m_Size.x / 2.0f, m_Size.y / 2.0f);
	m_Shape.setPosition(m_Position);
}

RectangleShape Platform::getShape()
{
	return m_Shape;
}

Vector2f Platform::getSize()
{
	return m_Size;
}
Vector2f Platform::getPosition()
{
	return m_Position;
}

FloatRect Platform::getRect()
{
	return m_Shape.getGlobalBounds();
}