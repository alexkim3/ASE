#pragma once
#include "ngl/Mat4.h"
#include "ngl/Vec3.h"
#include <QOpenGLWidget>
#include "Object.h"
#include "Spring.h"

class NGLScene : public QOpenGLWidget
{
    Q_OBJECT

private:
    Object box;
    Spring line;
    ngl::Mat4 m_model;
    ngl::Mat4 m_view;
    ngl::Mat4 m_perspective;

    void loadMatricesToShader();
    void timerEvent(QTimerEvent *event_ = nullptr) override;

public:
    NGLScene(QWidget *_parent );
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int _w, int _h) override;
    ~NGLScene() override;

};

