#include "window.h"
QString filename="names.txt";

int getRand(){
    unsigned int ms = static_cast<unsigned>(QDateTime::currentMSecsSinceEpoch());
    std::mt19937 gen(ms);
    std::uniform_int_distribution<> uid(1, 20);
    return uid(gen);
}

Window::Window()
{
    QWidget::setFixedSize(QSize(300, 400));
    QWidget::setWindowTitle ( "Név Valasztó" );
    gridLayout = new QGridLayout();
    boxLayout = new QHBoxLayout();
    boxLayout2 = new QHBoxLayout();
    mainText = new QLabel("Nyomd a gombot, és láss csodát!");
    gridLayout->addWidget(mainText,0,0);

    //label = new QLabel("Enter Name:");
    //lineedit = new QLineEdit();
    //gridLayout->addWidget(label,0,0);
    //gridLayout->addWidget(lineedit,0,1);

    button = new QPushButton("Random Name");
    boros = new QPushButton();
    welcome = new QLabel("Csak nyomd meg a gombot bruh");
    plainText = new QPlainTextEdit();
    boros->setIcon(QIcon("boros.png"));
    boros->setIconSize(QSize(100, 100));
    boros->setMinimumHeight(80);
    boros->setMaximumHeight(80);
    boros->setMinimumWidth(100);
    boros->setMaximumWidth(100);
     button->setMinimumHeight(80);
     button->setMaximumHeight(80);
     button->setMinimumWidth(100);
     button->setMaximumWidth(100);

     boxLayout->addWidget(button);
     boxLayout->addWidget(boros);
    gridLayout->addLayout(boxLayout,1,0);
    gridLayout->addWidget(welcome,2,0);
    gridLayout->addWidget(plainText,3,0);

    save = new QPushButton("Osztály mentése");
    get = new QPushButton("Osztály kérése");
    boxLayout2->addWidget(save);
    boxLayout2->addWidget(get);
    gridLayout->addLayout(boxLayout2,4,0);



    this->setLayout(gridLayout);

    QObject::connect(button, &QPushButton::clicked, this, &Window::handleButtonClicked1);
    QObject::connect(boros, &QPushButton::clicked, this, &Window::handleButtonClicked2);
    QObject::connect(save, &QPushButton::clicked, this, &Window::saveButtonClicked);
    QObject::connect(get, &QPushButton::clicked, this, &Window::getButtonClicked);

}

Window::~Window()
{
    delete label;
    delete lineedit;
    delete gridLayout;
    delete welcome;
}

void Window::handleButtonClicked1()
{

    QFile inputFile(filename);
    inputFile.open(QIODevice::ReadOnly);

    if (!inputFile.isOpen())
    {
        welcome->setText("A file nem létezik!");
        return;
    }
    QVector<QString> stringVector;
    QAtomicInteger i=0;
    QTextStream stream(&inputFile);
    for (QString line = stream.readLine();!line.isNull();line = stream.readLine())
    {
        stringVector.push_back(line);
        i++;
    };
    if(getRand()==5)
    {
        welcome->setText("Te vagy a SOROS: " + stringVector[QRandomGenerator::global()->bounded(i)]);
    }
    else if(getRand()==4)
    {
        welcome->setText("Te vagy a BOROS: " + stringVector[QRandomGenerator::global()->bounded(i)]);
    }
    else
    {
        welcome->setText("Te jössz: " + stringVector[QRandomGenerator::global()->bounded(i)]);
    }
    inputFile.close();
}
void Window::handleButtonClicked2()
{
    welcome->setText("Te jössz: Boros Bálint" );
}
void Window::getButtonClicked()
{
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "title", "A file nem létezik");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    plainText->setPlainText(text);
    file.close();
}
void Window::saveButtonClicked()
{
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "title", "A file nem létezik");
    }
    QTextStream out(&file);
    QString text = plainText->toPlainText();
    out << text;
    file.flush();
    file.close();
}
