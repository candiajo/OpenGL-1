#include <windows.h> 
#include <gl/glut.h>
#include "Scene.h"

//Delete console
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

Scene scene;
bool perspective;

//OpenGL initializations
void init(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// Background
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); 
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
}

//Rendering
void render(void)   
{
	glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
	
	scene.Render();

    glutSwapBuffers();					//Swap makes rendering visible
}

//Reshaping handler (required even in fullscreen-only modes)
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Calculate the aspect ratio and set the clipping volume
	gluPerspective(45, (float)w/(float)h, 0.1, 10000.0);
	perspective = true;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//Keyboard handler (normal keys)
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:	
		exit(0);
		break;
	}
}

//Keyboard handler for special keys (like arrow keys and function keys)
void special_keys(int a_keys, int x, int y)
{
	switch (a_keys)
	{
	case GLUT_KEY_F2:
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		if (perspective)
		{
			glOrtho(-5.0f, 5.0f, -5.0f, 5.0f, -100.0f, 100.0f);
		}
		else
		{
			gluPerspective(45, 640.0f / 480.0f, 0.1f, 10000.0f);
		}
		perspective = !perspective;

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		break;

	case GLUT_KEY_F3:
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		break;

	case GLUT_KEY_F4:
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;

	case GLUT_KEY_F5:
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;
	}
}

void GameLoop()
{
	int t1, t2;
	t1 = glutGet(GLUT_ELAPSED_TIME);
	render();
	do
	{
		t2 = glutGet(GLUT_ELAPSED_TIME);
	} 
	while (t2 - t1 < 20);	// 1000/20 = 50 fps
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);							// GLUT initialization
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);	// Display mode (rgb and double buffered)
	
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("My great game!");

	/*glutGameModeString("1024x768:32");
	glutEnterGameMode();*/

	glutSetCursor(GLUT_CURSOR_NONE);				// Make the default cursor disappear
	
	init();											// Initialization
	glutDisplayFunc(render);						// Register the display function
	glutReshapeFunc(reshape);						// Register the Reshape handler
	glutKeyboardFunc(keyboard);						// Register the keyboard handler
	glutSpecialFunc(special_keys);					// Register special keys handler
	glutIdleFunc(GameLoop);
	glutMainLoop();									// Go to GLUT main loop
}
