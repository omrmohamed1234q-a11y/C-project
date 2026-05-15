#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include "../core/Login.hpp"

class LoginWidget : public QWidget {
    Q_OBJECT

public:
    LoginWidget(QWidget *parent = nullptr);

signals:
    void loginSuccess(const QString& username, const QString& role);

private slots:
    void onLoginClicked();
    void onRegisterClicked();

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QComboBox *roleCombo;
    QPushButton *loginButton;
    QPushButton *registerButton;

    Login *loginBackend;
};
