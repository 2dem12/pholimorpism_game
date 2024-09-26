void draw_hero(QMainWindow& mainWindow) {
    // Создаем вторую метку для изображения hero.png
    QLabel *label2 = new QLabel(&mainWindow);
    QPixmap pixmap2(":/hero.png");
    label2->setPixmap(pixmap2);
    label2->setGeometry(700, 480, 400, 400);
}
