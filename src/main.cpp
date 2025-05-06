#include <SFML/Graphics.hpp>'
#include <vector>

#include "include/Rect.h"
#include "include/Platform.h"

using namespace sf;

int main()
{
	RenderWindow win(VideoMode(1920, 1080), "Platformer", Style::Fullscreen);


	std::vector<Platform> vecPlatform;
	vecPlatform.push_back(Platform(Vector2f(200, 50), Vector2f(300, 450), Color::White));
	vecPlatform.push_back(Platform(Vector2f(200, 50), Vector2f(500, 750), Color::White));

	Rec r(Vector2f(150, 950), Vector2f(100.0f, 150.0f), Color::Red, 500.0f, 0.9807f, 1300.0f, vecPlatform);

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
		for (int i = 0; i < vecPlatform.size(); i++)
		{
			win.draw(vecPlatform.at(i).getShape());
		}
		win.draw(r.getShape());
		win.display();
	}

	return 0;
}