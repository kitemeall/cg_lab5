#include "glwidget.h"
#include <GL/glu.h>
#include <QDebug>
GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    program=new QOpenGLShaderProgram();
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(20);
}
GLWidget::~GLWidget()
{
    delete program;
}

void GLWidget::initializeGL()
{
    glClearColor(0,0,0,1);
        glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(70,640.0/480.0,1,1000);
        glMatrixMode(GL_MODELVIEW);
        glEnable(GL_DEPTH_TEST);
     glTranslatef(0.0, 0.0,  -20.0);



    QOpenGLShader vShader(QOpenGLShader::Vertex);
    vShader.compileSourceFile(":/Shader/vshader.glsl");
    qDebug() << "Compile vertex shader log:"<<vShader.log();
    program->addShader(&vShader);
    program->link();

    QOpenGLShader fshader(QOpenGLShader::Fragment);
    fshader.compileSourceFile(":/Shader/fshader.glsl");
    qDebug() << "Compile fragment shader log:"<<fshader.log();
    program->addShader(&fshader);
    program->link();


    program->bind();






    program->setUniformValue(program->uniformLocation("shininess"), (float)20.0);

}

void GLWidget::resizeGL(int w,int h)
{

 glViewport(0, 0,w, h);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT
            | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
            glNormal3f(0.0,0.0,1.0);
            glColor3f(0.2, 0.5, 0.6);
            glVertex3f(-10,5,0);	//gl_Vertex
            glVertex3f(-10,-5,0);
            glVertex3f(10,-5,0);
            glVertex3f(10,5,0);
        glEnd();

        glRotatef(1, 0, 1, 0);
}
void GLWidget::clickedButton(){


}

