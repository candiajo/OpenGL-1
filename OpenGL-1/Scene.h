#pragma once

class Scene
{
public:
	Scene();
	virtual ~Scene(){};

	void Render();

private:
	float angle;
};