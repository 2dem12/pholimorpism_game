void draw_dragon(QLabel *label_dragon, char clr) {
    QPixmap pixmap1(":/green_dragon.png");
    QPixmap pixmap2(":/red_dragon.png");
    QPixmap pixmap3(":/black_dragon.png");

    if (clr == 'r') {
        label_dragon->setPixmap(pixmap2);
    } else if (clr == 'g') {
        label_dragon->setPixmap(pixmap1);
    } else {
        label_dragon->setPixmap(pixmap3);
    }

    label_dragon->setGeometry(0, 200, 350, 350);
}
