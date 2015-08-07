#ifndef DRAW_H
#define DRAW_H
#include <vector>
#include <QOpenGLShaderProgram>


class Draw
{
    public:
        Draw( QOpenGLShaderProgram *program, int LvertexAttr, int LcolorAttr);
        void addTriangle(std::vector<float> points, std::vector<float> color );
        void addCircle(std::vector<float> point, std::vector<float> color, int radius = 10, int tessellation = 36);
        void addLine(std::vector<float> point, std::vector<float> color, int width = 1);
        void deleteObject(int index);
        int count();

   private:
        std::vector< std::vector<float>> vertices;
        std::vector< std::vector<float>> colors;
        QOpenGLShaderProgram *shader_program;
        int vertexAttr;
        int colorAttr;
        int countAttr;


};

#endif // DRAW_H
