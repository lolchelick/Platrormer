#include <SFML/Graphics.hpp>

using namespace sf;

class Rec
{
private:
	Vector2f m_Size;
	Vector2f m_Position;
	RectangleShape m_Shape;
	Color m_Color;
	float m_Speed;
	float m_Gravity;
	float m_JumpStartSpeed;
	float m_JumpSpeed;
	float m_Bottom;
	bool inJump = false;
public:
	Rec(Vector2f pos, Vector2f size, Color color, float speed, float gravity, float JSS);
	void update(float deltaTime);
	RectangleShape getShape();
};