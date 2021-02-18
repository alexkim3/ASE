#include "NGLScene.h"
#include <ngl/NGLInit.h>
#include <ngl/ShaderLib.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/VAOFactory.h>

NGLScene::NGLScene(QWidget *_parent ) : QOpenGLWidget( _parent ), box()
{
    setFocus();
    this->resize(_parent->size());
    //m_position = 0.0f;
}

NGLScene::~NGLScene()
{
  std::cout << "Shutting down NGL, removing VAO's and Shaders\n";
}


void NGLScene::resizeGL( int _w, int _h )
{
    m_perspective=ngl::perspective( 90.0f, static_cast<float>( _w ) / _h, 0.05f, 200.0f );
    glViewport( 0, 0, _w, _h );
}

void NGLScene::initializeGL()
{
    ngl::NGLInit::initialize();
    glClearColor( 1.0f, 0.894f, 0.882f, 1.0f );
    glEnable( GL_DEPTH_TEST );
    glEnable( GL_MULTISAMPLE );
    glBlendFunc(GL_BLEND_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    ngl::Vec3 eye = {0.f, 0.f, 90.f};
    ngl::Vec3 look = {0.f, -20.f, 0.f};
    ngl::Vec3 up = {0.f, 0.1f, 0.f};

    m_view=ngl::lookAt(eye,look,up);
    ngl::VAOPrimitives::createSphere("box", box.size, box.subdivision);
    ngl::VAOPrimitives::createLineGrid("grid", 10.f,10.f,5);

    startTimer(10);
}

void NGLScene::loadMatricesToShader()
{
    auto MVP = m_perspective * m_view * m_model;

    ngl::ShaderLib::setUniform("MVP",MVP);
}
void NGLScene::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    ngl::ShaderLib::use(ngl::nglColourShader);

    ngl::ShaderLib::setUniform("Colour",0.940f, 0.502f, 0.502f, 1.0f);
    m_model.translate(line.point2[0], line.point2[1], 0);
    loadMatricesToShader();
    ngl::VAOPrimitives::draw("box");

    m_model.identity();
    ngl::ShaderLib::setUniform("Colour",0.940f, 0.502f, 0.502f, 1.0f);
    m_model.translate(line.point3[0], line.point3[1], 0);
    loadMatricesToShader();
    ngl::VAOPrimitives::draw("box");

    //m_position = line.point1;

    m_model.identity();
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    m_model.translate(0.f, 0.f, 0.f);
    loadMatricesToShader();
    ngl::VAOPrimitives::draw("grid");

    ngl::ShaderLib::setUniform("Colour",1.0f,1.0f,1.0f,1.0f);
    m_model.identity();
    std::vector<ngl::Vec3> points(2);
    points[0]=line.point1;
    points[1]=line.point2;
    ngl::ShaderLib::setUniform("Colour",0.0f,0.0f,0.0f,0.0f);
    m_model.identity();
    loadMatricesToShader();
    std::unique_ptr<ngl::AbstractVAO> vao(ngl::VAOFactory::createVAO("simpleVAO",GL_LINES));
    vao->bind();
    vao->setData(ngl::AbstractVAO::VertexData(2*sizeof(ngl::Vec3),points[0].m_x));
    vao->setNumIndices(2);
    vao->setVertexAttributePointer(0,3,GL_FLOAT,0,0);
    vao->draw();
    vao->unbind();


    std::vector<ngl::Vec3> points2(2);
    points2[0]=line.point2;
    points2[1]=line.point3;
    ngl::ShaderLib::setUniform("Colour",0.0f,0.0f,0.0f,0.0f);
    m_model.identity();
    loadMatricesToShader();
    std::unique_ptr<ngl::AbstractVAO> vao2(ngl::VAOFactory::createVAO("simpleVAO",GL_LINES));
    vao2->bind();
    vao2->setData(ngl::AbstractVAO::VertexData(2*sizeof(ngl::Vec3),points2[0].m_x));
    vao2->setNumIndices(2);
    vao2->setVertexAttributePointer(0,3,GL_FLOAT,0,0);
    vao2->draw();
    vao2->unbind();

}
void NGLScene::timerEvent(QTimerEvent *)
{
    line.simulate();
    update();
}

 /*
void setXPosition(double _x)
{
  _x = m_position[0];
  update();
}*/
