void write(QLabel *label, QString text, int x, int y, bool zakrep) {
    label->setText(text);
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(x, y, 400, 100);

    if (zakrep) {
        label->setFixedSize(300, 150);
    }

    QFont font;
    font.setPointSize(30);
    label->setFont(font);

    label->setStyleSheet("QLabel { background-color : white; color : black; }");

}

void edd_text(QMainWindow& mainWindow, QString str) {
    QWidget *centralWidget = new QWidget(&mainWindow);
    mainWindow.setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QLabel *label = new QLabel(str, centralWidget);
    label->setAlignment(Qt::AlignCenter);

    QFont font = label->font();
    font.setPointSize(50);
    label->setFont(font);
    label->setStyleSheet("QLabel { color : white; }");
    layout->addWidget(label);

    QLabel *gifLabel = new QLabel(centralWidget);
    gifLabel->setAlignment(Qt::AlignCenter);



    if (str == "YOU WIN") {
        centralWidget->setStyleSheet("background-color: green;");
        QMovie *movie = new QMovie(":/banana-cheerer.gif");
        gifLabel->setMovie(movie);
        movie->start();
        layout->addWidget(gifLabel);

    } else {
        centralWidget->setStyleSheet("background-color: red;");
        QMovie *movie = new QMovie(":/cry_frog.gif");
        gifLabel->setMovie(movie);
        movie->start();
        layout->addWidget(gifLabel);
    }
}
