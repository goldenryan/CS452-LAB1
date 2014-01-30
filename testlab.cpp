#include "initShaders.h"
#include "vec.h"
#include <cstdlib>

using namespace std;

int change=0;

GLuint vaoID, vboID;

//Draw Functions
void triangle(void){
	glClear(GL_COLOR_BUFFER_BIT);
	fprintf(stderr,"Making Triangle\n");
	GLfloat vertices[] = {0.5f,-0.5f,0.0f,
                         0.0f,0.5f,0.0f,
                        -0.5f,-0.5f,0.0f};

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

  glDrawArrays(GL_TRIANGLES, 0, 3);
	glFlush();
}

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

void drawshape(){
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
  if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    exit(0);
  else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		change++;
		drawshape();
	}	
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutCreateWindow("Some Shapes");

	
	glewExperimental=GL_TRUE;
	if(glewInit()){
		fprintf(stderr,"unable to initialize GLEW");
		exit(EXIT_FAILURE);
	}
	
	glutInitContextVersion(4, 3);
  glutInitContextProfile(GLUT_CORE_PROFILE|GLUT_COMPATIBILITY_PROFILE);
 
  const GLubyte* version=glGetString(GL_SHADING_LANGUAGE_VERSION);
  fprintf(stderr,"Opengl glsl version %s\n", version);

  version=glGetString(GL_VERSION);
  fprintf(stderr,"Opengl version %s\n", version);
	
  glutDisplayFunc(drawshape);
  glutMouseFunc(mousepress);
  glutMainLoop();
	return 0;
}
	
	
	



