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
    ++countAttr;
    std::vector<float> allcolor;
    allcolor.resize(points.size());

    vertices.push_back(points);

    unsigned int i = 0;
    while (i < points.size()){
        allcolor[i + 0] = color[0];
        allcolor[i + 1] = color[1];
        allcolor[i + 2] = color[2];

        i += 3;
    }
    colors.push_back(allcolor);

}

void Draw::addCircle(std::vector<float> point, std::vector<float> color, int radius, int tessellation)
{

}

void Draw::addLine(std::vector<float> points, std::vector<float> color, int width)
{

}

void Draw::deleteObject(int index)
{
    vertices.erase(vertices.begin() + index);
}

void Draw::Paint(int index)
{
    if( index == -1)
        for ( int i = 0; i < vertices.size(); i++)   {

            shader_program->setAttributeArray(vertexAttr, vertices[i].data(), 3);
            shader_program->setAttributeArray(colorAttr, colors[i].data(), 3);

            shader_program->enableAttributeArray(vertexAttr);
            shader_program->enableAttributeArray(colorAttr);

            glDrawArrays(GL_TRIANGLES, 0, 3);

            shader_program->disableAttributeArray(vertexAttr);
            shader_program->disableAttributeArray(colorAttr);

        }


}

