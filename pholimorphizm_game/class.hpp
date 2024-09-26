class Attacker {
public:
    Attacker() : heals_(30), damage_(10) {}
    Attacker(int hp, int dam) : heals_(hp), damage_(dam) {}

    void attack(Attacker& breack) {
        breack.heals_ = std::max(breack.heals_ - damage_, 0);
    }
    bool is_alive() {
        if (heals_ != 0) {
            return true;
        } else {
            return false;
        }
    }

    std::string get_hp() {
        return std::to_string(heals_);
    }

    int cout_hp() {
        return heals_;
    }
protected:
    int heals_, damage_;
};

class Hero : public Attacker {
public:
    Hero() : Attacker(50, 10) {}
};

class Enemy : public Attacker {

};

class  Dragon : public Enemy {
public:
    Dragon(char clr) : color_(clr) {}
    virtual ~Dragon() {}


    void set_answer(QString& savedText, auto& lineEdit) {
        if (color_ == 'r') {
            try_answer_ = std::to_string(x_ + y_);
        } else if (color_ == 'g') {
            try_answer_ = std::to_string(std::max(x_, y_) - std::min(x_, y_));
        } else if (color_ == 'b') {
            try_answer_ = std::to_string(x_ * y_);
        }

    }


    bool check_answer(std::string ans) {
        answer_ = ans;
        if (answer_ == try_answer_) {
            return true;
        } else {
            return false;
        }
    }

    std::string question(int x, int y) {
        x_ = x;
        y_ = y;
        if (color_ == 'g' && x_ < y_) std::swap(x_, y_);
        std::string num_str = std::to_string(x_);
        num_str += ' ';
        if (color_ == 'r') {
            num_str += '+';
        } else if (color_ == 'g') {
            num_str += '-';
        } else if (color_ == 'b') {
            num_str += '*';
        }
        num_str += ' ';
        num_str += std::to_string(y_);
        num_str += ' ';
        num_str += '=';
        return num_str;
    }

    char get_color() {
        return color_;
    }

private:
    char color_;
    std::string quest_, try_answer_, answer_;
    int x_, y_;
};

class RedDragon : public Dragon {
public:
    RedDragon() : Dragon('r') {}
    char get_color() {
        return 'r';
    }
};

class GreenDragon : public Dragon {
public:
    GreenDragon() : Dragon('g') {}
    char get_color() {
        return 'g';
    }
};

class BlackDragon : public Dragon {
public:
    BlackDragon() : Dragon('b') {}
    char get_color() {
        return 'b';
    }
};