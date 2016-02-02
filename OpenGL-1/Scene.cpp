#include "Scene.h"
#include <gl/glut.h>

Scene::Scene()
{
	angle = 0.0f;
}

void Scene::Render()
{
	glTranslatef(0.0f, 0.0f, -10.0f);

	glPushMatrix();
		glRotatef(angle, 1.0f, 0.0f, 0.0f);
		glBegin(GL_TRIANGLES); 
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(3.0f, 1.0f, 0.0f);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(2.0f, -1.0f, 0.0f);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(4.0f, -1.0f, 0.0f);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(2.0f * angle, 0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glColor3f(1.0f, 1.0f, 0.0f);
			glVertex3f(-1.0f, 1.0f, 0.0f);
			glVertex3f(1.0f, 1.0f, 0.0f);
			glVertex3f(1.0f, -1.0f, 0.0f);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-1.0f, -1.0f, 0.0f);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, 0.0f, (angle / 100.0f));
		glBegin(GL_QUAD_STRIP);
			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3f(-2.0f, 0.0f, 0.0f);
			glColor3f(1.0f, 1.0f, 0.0f);
			glVertex3f(-2.0f, -1.0f, 0.0f);
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex3f(-3.0f, 0.0f, 0.0f);
			glColor3f(0.5f, 0.5f, 0.5f);
			glVertex3f(-3.0f, -1.0f, 0.0f);
			glColor3f(0.5f, 1.5f, 0.5f);
			glVertex3f(-4.0f, 0.5f, 0.0f);
			glColor3f(1.5f, 0.5f, 0.5f);
			glVertex3f(-4.0f, -1.5f, 0.0f);
		glEnd();
	glPopMatrix();

	angle += 0.5f;
}