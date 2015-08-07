#ifndef BASEGLWIDGET_H
#define BASEGLWIDGET_H
#include "QOpenGLWidget"
#include <QFile>
#include "QOpenGLShaderProgram"
#include <vector>


class BaseGLWidget : public QOpenGLWidget{

    public:
        BaseGLWidget(QWidget * parent = 0);
    private:

        void initializeGL();
        void paintGL();
        void resizeGL(int, int);

        QOpenGLShaderProgram shader_program;
        int vertexAttr;
        int colorAttr;
        int matrixUniform;

};

#endif // BASEGLWIDGET_H
