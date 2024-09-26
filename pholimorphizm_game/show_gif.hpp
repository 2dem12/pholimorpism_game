void dragon_shot(QLabel* gifLabel) {
    gifLabel->setAlignment(Qt::AlignCenter);
    gifLabel->setGeometry(50, 100, 500, 500);
    QMovie *movie = new QMovie(":/shot(1).gif");
    gifLabel->setMovie(movie);
    movie->start();

    QTimer::singleShot(1000, [movie, gifLabel]() {
        movie->stop();
        gifLabel->clear();
        delete movie;
    });
}

void hero_shot(QLabel* gifLabel) {
    gifLabel->setAlignment(Qt::AlignCenter);
    gifLabel->setGeometry(150, 200, 500, 500);
    QMovie *movie = new QMovie(":/shot(2).gif");
    gifLabel->setMovie(movie);
    movie->start();

    QTimer::singleShot(1000, [movie, gifLabel]() {
        movie->stop();
        gifLabel->clear();
        delete movie;
    });
}

void show_blood(QLabel* gifLabel, char person) {
    gifLabel->setAlignment(Qt::AlignCenter);
    if (person == 'h') {
        gifLabel->setGeometry(550, 500, 200, 200);
    } else {
        gifLabel->setGeometry(50, 100, 200, 200);
    }

    QMovie *movie = new QMovie(":/blood(2).gif");
    gifLabel->setMovie(movie);
    movie->start();

    QTimer::singleShot(1600, [movie, gifLabel]() {
        movie->stop();
        gifLabel->clear();
        delete movie;
    });
}
