all:
	g++ main.cpp Bird.cpp Obstacle.cpp Parallax.cpp UISound.cpp -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-window -o Game