#ifndef DRAW_H
#define DRAW_H
#include <vector>
#include <QOpenGLShaderProgram>
#include <math.h>



class Draw
{
    public:
        Draw( QOpenGLShaderProgram *program, int LvertexAttr, int LcolorAttr, int LmodelViewMatrix);
        void addTriangle(std::vector<float> points, std::vector<float> color );
        void addCircle(std::vector<float> point, std::vector<float> color, int radius = 10, unsigned int tessellation = 36);
        void addLine(std::vector<float> points, std::vector<float> color, float width = 1);
        void deleteObject(int index);
        int count();
        float dist(std::vector<float> points);
        float angle(std::vector<float> points);
        void Paint( int index = -1);

   private:

        std::vector< std::vector<float> > vertices;
        std::vector< std::vector<float> > colors;
        std::vector< QMatrix4x4 > transformations;

        QOpenGLShaderProgram *shader_program;

        int vertexAttr;
        int colorAttr;
        int countAttr;
        int modelViewMatrix;




};

#endif // DRAW_H
