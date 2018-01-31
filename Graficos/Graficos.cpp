// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include <iostream>
using namespace std;

GLfloat red, green, blue;
GLfloat angulo = 0.0f;

void actualizar() { 
	//Aqu� esta bien para cambiar los valores
	//De las variables de mi programa!

	if (angulo < 360) {
		angulo += 0.01;
	}
	else {
		angulo = 0.0f;
	}

}

void dibujar() {
	glPushMatrix();

	glTranslatef(0.2f, -0.2f, 0.0f);
	//glRotatef(45.0f, 1.0f, 0.0f, 0.0f); //Afecta eje x
	//glRotatef(angulo, 0.0f, 1.0f, 0.0f); //Afecta eje y
	glRotatef(angulo, 0.0f, 0.0f, 1.0f); //Afecta eje z
	glScalef(0.2f, 0.2f, 0.2f);

	glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -0.5f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, -0.5f, 0.0f);

	glEnd();//Finaliza la rutina
	glPopMatrix();

}


int main()
{
	//Declaraci�n de ventana
	GLFWwindow *window;
	//Propiedades de la ventana
	GLfloat ancho = 1024;
	GLfloat alto = 768;

	//Inicializaci�n de GLFW
	if (!glfwInit()) {
		//Si no se inici� bien, terminar la ejecuci�n
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana
	window = glfwCreateWindow(ancho, alto, "Graficos", NULL, NULL);
	//Verficar si se cre� bien la ventana
	if (!window) {
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Termina ejecuci�n
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno
	glewExperimental = true;
	//Inicializar GLEW
	GLenum glewError = glewInit();
	//Verificar que GLEW se inicializ� bien
	if (glewError != GLEW_OK) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}



	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL: " << version << endl;


	red = green = blue = 0.0f;

	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window)) {
		//Establecer el area de render (viewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla
		glClearColor(red, green, blue, 1);
		//Limpiar la pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//rutina de dibujo
		actualizar();
		dibujar();

		//Intercambio de buffers
		glfwSwapBuffers(window);
		//Buscar se�ales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

