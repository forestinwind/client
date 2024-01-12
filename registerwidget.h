#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QWidget>

namespace Ui {
class registerWidget;
}

class registerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit registerWidget(QWidget *parent = nullptr);
    ~registerWidget();

private slots:
    void on_pushButton_clicked();
    void on_checkBox_stateChanged(int arg1);

signals:
    void sendMessageSignal(QString);

private:
    Ui::registerWidget *ui;
};

#endif // REGISTERWIDGET_H
