#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMetaType>
#include <QVector>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    virtual ~MainWindow();

private Q_SLOTS:
    void addObject();
    void removeObject();

private:
    QVector<QObject*> m_objects;
};

class MyObject : public QObject
{
    Q_OBJECT

    int a[32];
};

Q_DECLARE_METATYPE(MyObject*);

#endif // MAINWINDOW_H
