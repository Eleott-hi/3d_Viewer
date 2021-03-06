#include "glwidget.h"

GLWidget::~GLWidget(){}

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent){}

void GLWidget::draw_cube(double a)
{
    GLdouble  vertex[]= {0,0,0,
        -a,-a, a,   -a,a,a,     a,a,a,      a,-a,a,
        -a,-a, -a,   -a,a,-a,     a,a,-a,      a,-a,-a
    };


    GLuint  facet[]= {
        1,2,3,4,
        5,6,7,8,
        1,2,6,5,
        3,4,8,7,
        2,3,7,6,
        1,5,8,4
    };
    GLdouble test_1[10000] = {0};
    GLuint test_2[10000] = {0};




    for (int k = 0; k < 6; ++k) {
        for (int i = 0; i < 4; ++i) test_1[i] = vertex[facet[k*4+i]];
        glEnableClientState(GL_VERTEX_ARRAY);
            glVertexPointer(3, GL_DOUBLE, 0, &test_1);
            glColor3f(1, 0, 0);
            glDrawArrays(GL_LINE_LOOP, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);
    }

}

void GLWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-1,1,-1,1,1,3);
    glFrustum(-1,1,-1,1,1,3);

}

void GLWidget::paintGL()
{
    glClearColor (0,1,0,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-2);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);
    draw_cube(0.5);

}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
 mPos= event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    xRot = 1/M_PI * (event->pos().y() - mPos.y());
    yRot = 1/M_PI * (event->pos().x() - mPos.x());
    update();
}

