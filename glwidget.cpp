#include "glwidget.h"
#include <GL/glu.h>
#include <GL/glut.h>
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
    vShader.compileSourceFile("../Lab5Shader/Shader/vshader.glsl");
    qDebug() << "Compile vertex shader log:"<<vShader.log();
    program->addShader(&vShader);
    program->link();

    QOpenGLShader fshader(QOpenGLShader::Fragment);
    fshader.compileSourceFile("../Lab5Shader/Shader/fshader.glsl");
    qDebug() << "Compile fragment shader log:"<<fshader.log();
    program->addShader(&fshader);
    program->link();


    program->bind();

}

void GLWidget::resizeGL(int w,int h)
{

 glViewport(0, 0,w, h);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT
            | GL_DEPTH_BUFFER_BIT);


    program->setUniformValue("lightPos", 0.0, 0.0, 0.0);

    program->setUniformValue("mdiffuse", 0.6, 0.6, 0.6);
    program->setUniformValue("mambient", 0.2, 0.2, 0.2);
    program->setUniformValue("mspecular", 1.0, 1.0, 1.0);

    program->setUniformValue("ldiffuse", 0.6, 0.6, 0.6);
    program->setUniformValue("lambient", 0.2, 0.2, 0.2);
    program->setUniformValue("lspecular", 1.0, 1.0, 1.0);

    program->setUniformValue(program->uniformLocation("shininess"), (float)20.0);

    //qDebug() << program->uniformLocation("shininess");



    glutSolidTorus(2, 5, 20, 30);
    glRotatef(1.0, 1, 1, 1);
}
void GLWidget::clickedButton(){

    glTranslatef(0.0, 3,  0);

}

