#include "initShaders.h"
#include "vec.h"
#include <cstdlib>

using namespace std;
//global variable for changing shapes
int change=0;

GLuint vaoID, vboID;

//Draw Triangle
void triangle(void){
	glClear(GL_COLOR_BUFFER_BIT); //clears the screen
	fprintf(stderr,"Making Triangle\n"); //debug
	//vertecies for triangle
	GLfloat vertices[] = {0.5f,-0.5f,0.0f,
                         0.0f,0.5f,0.0f,
                        -0.5f,-0.5f,0.0f};

	glGenVertexArrays(1,&vaoID); //generates and binds vertex array objects
	glBindVertexArray(vaoID);
	
	glGenBuffers(1,&vboID); //generates, binds, and allocates vertex buffer objects
	glBindBuffer(GL_ARRAY_BUFFER,vboID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	ShaderInfo shaders[]={ //assigns shaders
  { GL_VERTEX_SHADER , "vertexshader.glsl"} ,
  { GL_FRAGMENT_SHADER , "fragmentshader.glsl"},
  { GL_NONE , NULL} 
  };

	initShaders(shaders); //initializes shaders


  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*) 0);

  glDrawArrays(GL_TRIANGLES, 0, 3); //draws the triangle based on the verticies
	glFlush();
}
//Draw Square
void square(void){
	glClear(GL_COLOR_BUFFER_BIT);
	fprintf(stderr,"Making Square\n");
	GLfloat vertices[] = {0.5f,-0.5f,0.0f,
                        0.5f,0.5f,0.0f,
                        -0.5f,0.5f,0.0f,
												-0.5f,-0.5f,0.0f
												};

	glGenVertexArrays(1,&vaoID);
	glBindVertexArray(vaoID);
	
	glGenBuffers(1,&vboID);
	glBindBuffer(GL_ARRAY_BUFFER,vboID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	ShaderInfo shaders[]={
  { GL_VERTEX_SHADER , "vertexshader.glsl"} ,
  { GL_FRAGMENT_SHADER , "fragmentshader.glsl"},
  { GL_NONE , NULL} 
  };

	initShaders(shaders);


  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*) 0);

  glDrawArrays(GL_QUADS, 0, 4);
	glFlush();
}
//Draw Trap
void trap(void){
	glClear(GL_COLOR_BUFFER_BIT);
	fprintf(stderr,"Making Trap\n");
	GLfloat vertices[] = {0.5f,-0.5f,0.0f,
                        1.0f,0.5f,0.0f,
                        0.0f,0.5f,0.0f,
												-0.5f,-0.5f,0.0f
												};

	glGenVertexArrays(1,&vaoID);
	glBindVertexArray(vaoID);
	
	glGenBuffers(1,&vboID);
	glBindBuffer(GL_ARRAY_BUFFER,vboID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	ShaderInfo shaders[]={
  { GL_VERTEX_SHADER , "vertexshader.glsl"} ,
  { GL_FRAGMENT_SHADER , "fragmentshader.glsl"},
  { GL_NONE , NULL} 
  };

	initShaders(shaders);


  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*) 0);

  glDrawArrays(GL_QUADS, 0, 4);
	glFlush();
}

void drawshape(){ //based on how many clicks, changes the shape
	if(change%3 == 0){
		glutDisplayFunc(triangle);
		glutPostRedisplay();
	}
	else if(change%3 == 1){
		glutDisplayFunc(square);
		glutPostRedisplay();
	}
	else if(change%3 == 2){
		glutDisplayFunc(trap);
		glutPostRedisplay();
	}
}

void mousepress(int button, int state, int x, int y){
  if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN) //right click exit
    exit(0);
  else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){ //left click change shape
		change++;
		drawshape();
	}	
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutCreateWindow("Some Shapes"); //creates window

	//initilize glew
	glewExperimental=GL_TRUE;
	if(glewInit()){
		fprintf(stderr,"unable to initialize GLEW");
		exit(EXIT_FAILURE);
	}
	
  //version of opengl
	glutInitContextVersion(4, 3);
  glutInitContextProfile(GLUT_CORE_PROFILE|GLUT_COMPATIBILITY_PROFILE);
 
  const GLubyte* version=glGetString(GL_SHADING_LANGUAGE_VERSION);
  fprintf(stderr,"Opengl glsl version %s\n", version);

  version=glGetString(GL_VERSION);
  fprintf(stderr,"Opengl version %s\n", version);
	
  glutDisplayFunc(drawshape); //tells what to display
  glutMouseFunc(mousepress); //mouse click functions
  glutMainLoop(); //never ending loop to show picture
	return 0;
}
	
	
	



