#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow win(VideoMode(1920, 1080), "Platformer", Style::Fullscreen);

	while (win.isOpen())
	{
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

		win.clear();
		win.display();
	}

	return 0;
}