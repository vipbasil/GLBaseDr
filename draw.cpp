#include "draw.h"

Draw::Draw(QOpenGLShaderProgram *program, int LvertexAttr, int LcolorAttr):
shader_program(program),
vertexAttr(LvertexAttr),
colorAttr(LcolorAttr)
{
    countAttr = 0;
}

void Draw::addTriangle(std::vector<float> points, std::vector<float> color)
{

}

void Draw::addCircle(std::vector<float> point, std::vector<float> color, int radius, int tessellation)
{

}

void Draw::addLine(std::vector<float> point, std::vector<float> color, int width)
{

}

void Draw::deleteObject(int index)
{

}

