#include "mainwindow.h"

#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

#include <QTimer>
#include <QToolBar>

MainWindow::MainWindow()
{
    QLabel *l = new QLabel(this);
    l->setText("Hello World!");
    setCentralWidget(l);

    QToolBar* bar = addToolBar("Foo");

    QAction *a = new QAction(tr("Add"), this);
    connect(a, SIGNAL(triggered()), SLOT(addObject()));
    bar->addAction(a);

    a = new QAction(tr("Remove"), this);
    connect(a, SIGNAL(triggered()), SLOT(removeObject()));
    bar->addAction(a);
}

MainWindow::~MainWindow()
{}

void MainWindow::addObject()
{
    m_objects << new MyObject;
}

void MainWindow::removeObject()
{
    if (m_objects.isEmpty())
        return;

    // remove last element
    delete m_objects.last();
    m_objects.resize(m_objects.size()-1);
}

#include "mainwindow.moc"
