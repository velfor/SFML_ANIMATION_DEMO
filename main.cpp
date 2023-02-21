#include "settings.h"
#include <ctime>
#include "explosion.h"

using namespace sf;


int main()
{
	srand(time(nullptr));
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//�������� �������� ����
	
		
	Explosion exp1;
	expInit(exp1, Vector2f(400.f, 400.f));

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		//1 ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}

		//2 ���������� ��������

		

		//3 ��������� ����
		//3.1 ������� ����
		window.clear();
		//3.2 ��������� �������� (� ������!)
		expDraw(window, exp1);
		//3.3 ����� �� �����
		window.display();
	}
	return 0;
}