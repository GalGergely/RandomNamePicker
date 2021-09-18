#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QString>
#include <QVector>
#include <QString>
#include <QAtomicInteger>
#include <QRandomGenerator>
#include <QIODevice>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QRandomGenerator>
#include <random>
#include "QDateTime"

class Window : public QWidget
{
    Q_OBJECT
public:
    Window();
    ~Window();

private:
    QLabel* label;
    QLabel* mainText;
    QLabel* welcome;
    QLineEdit* lineedit;
    QPushButton* button;
    QPushButton* boros;
    QPushButton* save;
    QPushButton* get;
    QGridLayout* gridLayout;
    QHBoxLayout* boxLayout;
    QHBoxLayout* boxLayout2;
    QPlainTextEdit* plainText;
private slots:
    void handleButtonClicked1();
    void handleButtonClicked2();
    void saveButtonClicked();
    void getButtonClicked();

};
#endif // WINDOW_H
