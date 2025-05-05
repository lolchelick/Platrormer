#include <SFML/Graphics.hpp>

#include "include/Rect.h"

using namespace sf;

int main()
{
	RenderWindow win(VideoMode(1920, 1080), "Platformer", Style::Fullscreen);

	Rec r(Vector2f(150, 950), Vector2f(100.0f, 150.0f), Color::Red, 500.0f, 0.09807f, 50.0f);

	Clock clock;
	float deltaTime;

	while (win.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		Event ev;
		while (win.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
			{
				win.close();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			win.close();
		}

		r.update(deltaTime);

		win.clear();
		win.draw(r.getShape());
		win.display();
	}

	return 0;
}