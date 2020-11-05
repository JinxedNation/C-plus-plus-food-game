#include "FrameTimer.h"

void FrameTimer::Update()
{
	time = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = (float)(time - oldTime) / 1000;
	oldTime = time;
}

FrameTimer::FrameTimer()
{
	time = glutGet(GLUT_ELAPSED_TIME);
	oldTime = time;
	Update();
}