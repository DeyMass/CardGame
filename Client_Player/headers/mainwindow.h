#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define WINDOW_BASE_WIDTH 720
#define WINDOW_BASE_HEIGHT 720

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
