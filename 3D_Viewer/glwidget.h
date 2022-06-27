#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QMouseEvent>
#include <QObject>
#include <QOpenGLWidget>

class GLWidget : public QOpenGLWidget
{
private:
    QPoint mPos;
    float xRot, yRot;


public:
    ~GLWidget();
    GLWidget(QWidget *parent = nullptr);
    void draw_cube(double a);

    // QOpenGLWidget interface
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event)override;
};

#endif // GLWIDGET_H
