#include "baseglwidget.h"

BaseGLWidget::BaseGLWidget(QWidget *parent):QOpenGLWidget(parent){

}

void BaseGLWidget::initializeGL(){

    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);

    //shaders link
    QOpenGLShader vShader(QOpenGLShader::Vertex);
    vShader.compileSourceFile(":/files/Shaders/vShader.glsl");


    QOpenGLShader fShader(QOpenGLShader::Fragment);
    fShader.compileSourceFile(":/files/Shaders/fShader.glsl");

    shader_program.addShader(&vShader);
    shader_program.addShader(&fShader);

    if(!shader_program.link()){
        qWarning("Can't link the shader program");
    }

    vertexAttr = shader_program.attributeLocation("vertexAttr");
    colorAttr = shader_program.attributeLocation("colorAttr");
    matrixUniform = shader_program.uniformLocation("matrix");

}

void BaseGLWidget::paintGL(){


    if(!shader_program.bind())
        return;

    //translate the camera away
    QMatrix4x4 matrix;
    matrix.ortho( -2.0f, 2.0f, -2.0f, 2.0f, 2.0f, -2.0f);
    matrix.translate(0.0f, 0.0f, 1.0f);

    shader_program.setUniformValue(matrixUniform, matrix);

    //draw a triangle as example

    std::vector<float> vertices;
    std::vector<float> colors;

    vertices.resize(9);
    colors.resize(9);

    vertices[0] = 0.0f;
    vertices[1] = 1.0f;
    vertices[2] = 0.0f;

    vertices[3] = 1.0f;
    vertices[4] = 0.0f;
    vertices[5] = 0.0f;

    vertices[6] = -1.0f;
    vertices[7] = 0.0f;
    vertices[8] = 0.0f;

    colors[0] = 0.0f;
    colors[1] = 1.0f;
    colors[2] = 0.0f;

    colors[3] = 1.0f;
    colors[4] = 0.0f;
    colors[5] = 0.0f;

    colors[6] = 0.0f;
    colors[7] = 0.0f;
    colors[8] = 1.0f;

    shader_program.setAttributeArray(vertexAttr, vertices.data(), 3);
    shader_program.setAttributeArray(colorAttr, colors.data(), 3);

    shader_program.enableAttributeArray(vertexAttr);
    shader_program.enableAttributeArray(colorAttr);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    shader_program.disableAttributeArray(vertexAttr);
    shader_program.disableAttributeArray(colorAttr);

    //release the  binded shader program
    shader_program.release();


}

void BaseGLWidget::resizeGL(int width, int height){
    glViewport(0, 0, width, height);

}

