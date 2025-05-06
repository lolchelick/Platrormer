#include "include/Rect.h"



Rec::Rec(Vector2f pos, Vector2f size, Color color, float speed, float gravity, float JSS, std::vector<Platform> platforms)
{
	m_Size = size;
	m_Shape.setSize(size);
	m_Shape.setFillColor(color);
	m_Position = pos;
	m_Shape.setOrigin(m_Size.x / 2.0f, m_Size.y / 2.0f);

	m_Speed = speed;
	m_Gravity = gravity;
	m_JumpStartSpeed = JSS;
	m_JumpSpeed = m_JumpStartSpeed;
	m_Bottom = m_Position.y;
	StartPosY = m_Bottom;
	m_FallSpeed = FALL_SPEED;

	m_Platforms = platforms;
	m_OnPlatform = false;
	inFall = false;

	m_Shape.setPosition(m_Position);
}

RectangleShape Rec::getShape()
{
	return m_Shape;
}

FloatRect Rec::getRect()
{
	return m_Shape.getGlobalBounds();
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

	if (!inJump)
	{
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			inJump = true;
			up = true;
			m_OnPlatform = false;
			inFall = false;
		}
	}

	if (inJump)
	{
		m_JumpSpeed -= m_Gravity;
		m_Position.y -= m_JumpSpeed * deltaTime;
		m_OnPlatform = false;
		if (m_JumpSpeed < 0)
		{
			up = false;
			inFall = true;
		}
	}


	if (inFall)
	{
		m_Bottom = StartPosY;
		m_OnPlatform = false;
		m_FallSpeed += FREE_FALL_CONST;
		m_Position.y += m_FallSpeed * deltaTime;
	}

	for (int i = 0; i < m_Platforms.size(); i++)
	{

		if (m_OnPlatform)
		{
			if (!this->getRect().intersects(m_Platforms.at(i).getRect()))
			{
				m_OnPlatform = false;
				inFall = true;
			}
		}
		if ((m_Position.y + m_Size.y / 2.0f > m_Platforms.at(i).getPosition().y - m_Platforms.at(i).getSize().y / 2.0f) &&
			this->getRect().intersects(m_Platforms.at(i).getRect()) && !up && !m_OnPlatform)
		{
			m_Bottom = m_Platforms.at(i).getPosition().y - (m_Size.y / 2.0f + m_Platforms.at(i).getSize().y / 2.0f);
			m_OnPlatform = true;
			inFall = false;
		}
	}



	if (m_Position.y >= m_Bottom)
	{
		m_Position.y = m_Bottom;
		m_JumpSpeed = m_JumpStartSpeed;
		inJump = false;
		m_FallSpeed = FALL_SPEED;
	}


	m_Shape.setPosition(m_Position);
}