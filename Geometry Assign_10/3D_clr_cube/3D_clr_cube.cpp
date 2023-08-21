
/*
Error    LNK2019    unresolved external symbol __imp_glutInitWindowPosition referenced in function main
Error    LNK2019    unresolved external symbol __imp_glutInitWindowSize referenced in function main
Error    LNK2019    unresolved external symbol __imp_glutInitDisplayMode referenced in function main
Error    LNK2019    unresolved external symbol __imp_glutMainLoop referenced in function main
Error    LNK2019    unresolved external symbol __imp_glutSwapBuffers referenced in function "void __cdecl Draw(void)" (?Draw@@YAXXZ)
Error    LNK2019    unresolved external symbol __imp_glutDisplayFunc referenced in function main
Error    LNK2019    unresolved external symbol __imp___glutInitWithExit referenced in function glutInit_ATEXIT_HACK
Error    LNK2019    unresolved external symbol __imp___glutCreateWindowWithExit referenced in function glutCreateWindow_ATEXIT_HACK
Error    LNK1120    8 unresolved externals
solution---------> change Debug-x86
#include <iostream>
#include <Windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/GLU.h>
#include<gl/GL.h>
using namespace std;
GLfloat Cx = 0, Cy = 0, Cz = 3;
void MyInit() {
glClearColor(0, 0, 0, 0);//BACKGROUND COLOR ->BLACK
glColor3f(0, 1, 0);//RGB->drawing color
glEnable(GL_DEPTH_TEST);//enabling depth testing
}
void Square(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[]) {
	glBegin(GL_POLYGON);
		glVertex3fv(A);
		glVertex3fv(B);
		glVertex3fv(C);
		glVertex3fv(D);
	glEnd();
}
void Cube(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], GLfloat V5[], GLfloat V6[], GLfloat V7[] ) {

	//SET COLOR
	glColor3f(1, 0, 0);//red
	Square(V0, V1, V2, V3);

	glColor3f(0, 1, 0);//green
	Square(V4, V5, V6, V7);

	glColor3f(0, 0, 1);//blue
	Square(V0, V4, V7, V3);

	glColor3f(1, 1, 0);//red+green
	Square(V1, V5, V6, V2);

	glColor3f(1, 0, 1);//red+blue
	Square(V3, V2, V6, V7);

	glColor3f(0, 1, 1);//green+blue
	Square(V0, V1, V5, V4);
}
void Draw()
{
	GLfloat V[8][3] = {
		//for front side
		{-0.5,0.5,0.5},
		{0.5,0.5,0.5},
		{0.5,-0.5,0.5},
		{-0.5,-0.5,0.5},

		//for back side
		{-0.5,0.5,-0.5},
		{0.5,0.5,-0.5},
		{0.5,-0.5,-0.5},
		{-0.5,-0.5,-0.5}
	};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//gluLookAt(2, 5, 4,0,0,0,0,1,0); //moving camera
	gluLookAt(Cx, Cy, Cz,0,0,0,0,1,0); //moving camera

	 Cube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);
	glutSwapBuffers();
}
void Key(unsigned char ch, int x, int y) {
	switch (ch) 
	{
		case 'x' : Cx = Cx - 0.5;  break;
		case 'X': Cx = Cx + 0.5;  break;

		case 'y': Cy = Cy - 0.5;  break;
		case 'Y': Cy = Cy + 0.5;  break;

		case 'z': Cz = Cz - 0.5;  break;
		case 'Z': Cz = Cz + 0.5;  break;
	}
	glutPostRedisplay();
}
int main(int argC,char *argV[])
{
	glutInit(&argC, argV);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 150);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("color cube");
	MyInit();
	glutDisplayFunc(Draw);
	glutKeyboardFunc(Key);
	glutMainLoop();

	return 0;
}
*/


#include <iostream>
#include <Windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/GLU.h>
#include<gl/GL.h>
//This are necessary openGL AND GLUT LIBRARIES
GLfloat rotationAngle = 0.0f; // Variable to store the rotation angle to store rotation angle of cube
void MyInit() {
	glClearColor(0, 0, 0, 0);//BACKGROUND COLOR ->BLACK
	//glClearColor(0.0, 0.0, 1.0, 0.0);//dark blue
	glColor3f(1, 1, 0);//RGB->drawing color
	glEnable(GL_DEPTH_TEST);//enabling BACK SIDE VISUALIZATION
}
//This function MyInit is used to initialize OpenGL settings. It sets the clear color 
//(background color) to black, the current drawing color to green, and
//enables depth testing to handle the depth information of objects in the scene.
void Face(GLfloat faceA[], GLfloat faceB[], GLfloat faceC[], GLfloat faceD[]) {
	glBegin(GL_POLYGON);  //draw polygon or square
	glVertex3fv(faceA);
	glVertex3fv(faceB);
	glVertex3fv(faceC);
	glVertex3fv(faceD);
	glEnd();
}

//This function Face is used to draw a face of the cube. It takes four vertices (faceA, faceB, faceC, faceD) as input and uses glBegin(GL_POLYGON) and
//glEnd() to delineate the face as a polygon. The glVertex3fv function is used to specify each vertex's position.
void Cube(GLfloat Vertice1[], GLfloat Vertice2[], GLfloat Vertice3[], GLfloat Vertice4[], 
	GLfloat Vertice5[], GLfloat Vertice6[], GLfloat Vertice7[], GLfloat Vertice8[]) {
	glColor3f(1, 0, 0);//RED
	Face(Vertice1, Vertice2, Vertice3, Vertice4);

	glColor3f(0, 1, 0);//GREEN
	Face(Vertice5, Vertice6, Vertice7, Vertice8);

	glColor3f(0, 0, 1);//BLUE
	Face(Vertice1, Vertice4, Vertice8, Vertice5);

	glColor3f(1, 0.5, 0);//ORANGE
	//glColor3f(1, 0, 1);//red+blue
	Face(Vertice2, Vertice3, Vertice7, Vertice6);

	glColor3f(1, 0, 1);//MAGNETA
	Face(Vertice1, Vertice2, Vertice6, Vertice5);

	glColor3f(1, 1, 1);//WHITE
	//glColor3f(1, 0, 1);//purple
	Face(Vertice4, Vertice3, Vertice7, Vertice8);
}
//This function Cube is used to draw the complete cube. It takes eight vertices as input (representing the eight corners of the cube) and
//calls the Face function six times to draw each face of the cube with different colors.
void DrawRectangleArray() {
	GLfloat Vertices[8][3] = {  //2d ARRAY named as vertices with size 8 rows(vertices) and 3 coloms (coordinate x,y,z)
	{-0.5, 0.5, 0.5},//vertex0
	{0.5, 0.5, 0.5},
	{0.5, -0.5, 0.5},
	{-0.5, -0.5, 0.5},
	{-0.5, 0.5, -0.5},
	{0.5, 0.5, -0.5},
	{0.5, -0.5, -0.5},
	{-0.5, -0.5, -0.5},//vertex7
	};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(rotationAngle, 1.0f, 0.0f, 0.0f); // Apply rotation around the (1, 1, 1) axis
	glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
	Cube(
		Vertices[0], Vertices[1], Vertices[2], Vertices[3],
		Vertices[4], Vertices[5], Vertices[6], Vertices[7]
	);
	glutSwapBuffers();
}
//This function DrawRectangleArray is the display function. It clears the color buffer and depth buffer,
//loads the identity matrix for the current matrix (modelview matrix), and applies a rotation transformation using glRotatef based on the rotationAngle variable.
// Then, it calls the Cube function with the predefined Vertices array to draw the cube. 
//Finally, glutSwapBuffers swaps the back and front buffers to display the rendered scene.

void Update(int value) {
	rotationAngle += 1.0f; // Increase the rotation angle
	if (rotationAngle > 360.0f) {
		rotationAngle -= 360.0f;
	}
	glutPostRedisplay(); // Mark the current window as needing to be redisplayed
	glutTimerFunc(16, Update, 0); // Call the update function again after 16 milliseconds
}
//This function Update is the update function that is repeatedly called using glutTimerFunc. 
//It increases the rotationAngle by 1.0 and wraps it around to keep it within the range of 0 to 360 degrees. 
//Then, it calls glutPostRedisplay to mark the current window as needing to be redisplayed. 
//Finally, it schedules the Update function to be called again after 16 milliseconds (approximately 60 frames per second) using glutTimerFunc.
int main(int argC, char* argV[]) {
	glutInit(&argC, argV);//initialize glut library
	glutInitWindowSize(400, 400);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Cube Rotation");
	MyInit();
	glutDisplayFunc(DrawRectangleArray);
	glutTimerFunc(0, Update, 0); // Start the update function immediately
	glutMainLoop();//handle events and render the scene
	return 0;
}
//The main function initializes GLUT and creates a window with the specified size and display mode. 
//It sets the window title to "Cube Rotation" and calls MyInit to initialize OpenGL settings. 
//It sets the display function to DrawRectangleArray and starts the update function (Update) immediately using glutTimerFunc. 
//Finally, it enters the GLUT main loop to handle events and continuously render the scene.