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

void Draw::addLine(std::vector<float> points, std::vector<float> color, float width)
{
    float line_long = dist(points);
    float alpha = angle(points);
    std::vector<float> local_vertices;
    local_vertices.resize(18);

    //creating points for the first triangle
    local_vertices[0] = 0.0f;
    local_vertices[1] = 0.0f;
    local_vertices[2] = 0.0f;

    local_vertices[3] = line_long;
    local_vertices[4] = 0.0f;
    local_vertices[5] = 0.0f;

    local_vertices[3] = 0.0f;
    local_vertices[4] = width;
    local_vertices[5] = 0.0f;

    //creating points for the second triangle
    local_vertices[0] = line_long;
    local_vertices[1] = width;
    local_vertices[2] = 0.0f;

    local_vertices[3] = line_long;
    local_vertices[4] = 0.0f;
    local_vertices[5] = 0.0f;

    local_vertices[3] = 0.0f;
    local_vertices[4] = width;
    local_vertices[5] = 0.0f;

   glRotatef(alpha, );


}

void Draw::deleteObject(int index)
{
    vertices.erase(vertices.begin() + index);
}

float Draw::dist(std::vector<float> points)
{
    //this function return the distance between two points
    return sqrt(powl(points[0] - points[3], 2) + powl(points[1] - points[4], 2) + powl(points[2] - points[5], 2));
}

float Draw::angle(std::vector<float> points)
{
    //this function return the angle of a vector between two points
    return atan2(points[4] - points[1], points[3] - points[0]);
}

void Draw::Paint(int index)
{
    if( index == -1)
        for (unsigned  int i = 0; i < vertices.size(); i++)   {

            shader_program->setAttributeArray(vertexAttr, vertices[i].data(), 3);
            shader_program->setAttributeArray(colorAttr, colors[i].data(), 3);

            shader_program->enableAttributeArray(vertexAttr);
            shader_program->enableAttributeArray(colorAttr);

            glDrawArrays(GL_TRIANGLES, 0, 3);

            shader_program->disableAttributeArray(vertexAttr);
            shader_program->disableAttributeArray(colorAttr);

        }


}

