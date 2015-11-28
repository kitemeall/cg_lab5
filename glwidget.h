#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QImage>
#include <QGLWidget>
#include <QOpenGLTexture>
#include <QTimer>
#include <QTableWidget>
class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
     ~GLWidget();
    QOpenGLShaderProgram* program;
    QOpenGLTexture* texture;
    void initializeGL();
    void resizeGL(int,int);
    void paintGL();

signals:

private slots:
    void clickedButton();
private:
    // БАЗОВОЕ //
    // Базовые методы OpenGL

    QTimer timer;

};

#endif // GLWIDGET_H
