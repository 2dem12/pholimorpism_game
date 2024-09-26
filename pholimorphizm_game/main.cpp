#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QThread>
#include <QLineEdit>
#include <QMovie>
#include <QTimer>
#include <QProcess>

#include <ctime>
#include <string>
#include <iostream>

#include "draw_dragon.hpp"
#include "draw_hero.hpp"
#include "write_text.hpp"
#include "class.hpp"
#include "show_gif.hpp"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Мое главное окно");

    // icon
    QLabel *label_inf_dragon = new QLabel(&mainWindow);
    QLabel *label_inf_hero = new QLabel(&mainWindow);
    QLabel *label_level = new QLabel(&mainWindow);
    QLabel *label_que = new QLabel(&mainWindow);
    QLabel *label_dragon = new QLabel(&mainWindow);

    mainWindow.resize(1400, 800);

    QPalette palette = mainWindow.palette();
    QColor customColor(85, 121, 158);
    palette.setColor(QPalette::Window, customColor);
    mainWindow.setPalette(palette);

    // gif
    QLabel *gifLabel = new QLabel(&mainWindow);
    QLabel *gifLabel2 = new QLabel(&mainWindow);



    draw_hero(mainWindow);

    // play_music("path_to_your_mp3_file.mp3");



    // butten
    QLineEdit *lineEdit = new QLineEdit(&mainWindow);

    lineEdit->setGeometry(720, 300, 450, 80);

    QFont font;
    font.setPointSize(50);
    lineEdit->setFont(font);

    QPushButton *button = new QPushButton("Сохранить ответ", &mainWindow);
    button->setGeometry(850, 400, 200, 50);

    QString savedText;
    Hero hero;
    srand(time(0));
    int level = 1;

    Dragon* dragons[] = {new RedDragon, new GreenDragon, new BlackDragon};

    for (Dragon* dragon: dragons) {
        std::string hp_dragon;
        std::string hp_hero;
        std::string que = dragon->question(rand()%15 + 1, rand()%15 + 1);
        std::string show_level = "Level " + std::to_string(level);


        auto handler = [&]() {
            if (dragon->check_answer(lineEdit->text().toStdString()) && dragon->is_alive() && hero.is_alive()) {
                hero.attack(*dragon);
                hero_shot(gifLabel2);
                show_blood(gifLabel, 'd');
                QProcess::startDetached("afplay", QStringList() << "../mp3/AAA.mp3");
            } else if (dragon->is_alive() && hero.is_alive() && lineEdit->text().toStdString().size() != 0) {
                dragon->attack(hero);
                dragon_shot(gifLabel2);
                show_blood(gifLabel, 'h');
                QProcess::startDetached("afplay", QStringList() << "../mp3/AAA.mp3");
            }
            if (lineEdit->text().toStdString().size() != 0) que = dragon->question(rand()%15 + 1, rand()%15 + 1);
            lineEdit->clear();

        };

        QObject::connect(button, &QPushButton::clicked, handler);
        QObject::connect(lineEdit, &QLineEdit::returnPressed, handler);

        while (dragon->is_alive() && hero.is_alive()) {
            hp_dragon = "Sergeychik\nHP: " + dragon->get_hp() + "\nDamage: 10";
            hp_hero = "HERO: Alexey \nHP: " + hero.get_hp() + "\nDamage: 10";



            write(label_inf_dragon, QString::fromStdString(hp_dragon), 0, 0, false);
            write(label_inf_hero, QString::fromStdString(hp_hero), 1000, 700, false);
            write(label_level, QString::fromStdString(show_level), 0, 700, false);
            write(label_que, QString::fromStdString(que), 800, 50, true);

            draw_dragon(label_dragon, dragon->get_color());
            dragon->set_answer(savedText, lineEdit);



            QApplication::processEvents();
            mainWindow.show();
        }
        level++;

        if (hero.is_alive() == false) {
            edd_text(mainWindow, "YOU LOST");
        }
    }
    if (hero.is_alive()) {
        edd_text(mainWindow, "YOU WIN");
        show_blood(gifLabel, 'f');
    }

    return app.exec();
}
