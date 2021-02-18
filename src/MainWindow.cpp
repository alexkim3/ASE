#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), m_ui(new Ui::MainWindow)
{
  m_ui->setupUi(this);

  m_gl=new NGLScene(this);

  m_ui->s_mainWindowGrid->addWidget(m_gl,0,0,2,1);
  //connect(m_ui->m_spring1PosX,SIGNAL(valueChanged(double)),m_gl,SLOT(setXPosition()));
  //connect(m_ui->m_spring1PosY,SIGNAL(valueChanged(double)),m_gl,SLOT(setYPosition()));
}


MainWindow::~MainWindow()
{
    delete m_ui;
}
