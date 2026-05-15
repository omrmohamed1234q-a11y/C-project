#include "LoginWidget.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent) {
    loginBackend = new Login("C:/Users/HP/CLionProjects/C-project-1/data/users.txt");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    
    QLabel *title = new QLabel("<h2>Welcome to Booked & Beyond</h2>", this);
    title->setAlignment(Qt::AlignCenter);

    usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("Username");
    
    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Password");
    passwordEdit->setEchoMode(QLineEdit::Password);

    roleCombo = new QComboBox(this);
    roleCombo->addItem("Customer");
    roleCombo->addItem("Owner");

    loginButton = new QPushButton("Login", this);
    registerButton = new QPushButton("Register", this);

    mainLayout->addStretch();
    mainLayout->addWidget(title);
    mainLayout->addWidget(usernameEdit);
    mainLayout->addWidget(passwordEdit);
    mainLayout->addWidget(roleCombo);
    
    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addWidget(loginButton);
    btnLayout->addWidget(registerButton);
    
    mainLayout->addLayout(btnLayout);
    mainLayout->addStretch();

    connect(loginButton, &QPushButton::clicked, this, &LoginWidget::onLoginClicked);
    connect(registerButton, &QPushButton::clicked, this, &LoginWidget::onRegisterClicked);
}

void LoginWidget::onLoginClicked() {
    std::string user = usernameEdit->text().toStdString();
    std::string pass = passwordEdit->text().toStdString();
    std::string selectedRole = roleCombo->currentText().toStdString();
    std::string fileRole;

    if (loginBackend->login(user, pass, fileRole)) {
        if (QString::fromStdString(fileRole).toLower() != QString::fromStdString(selectedRole).toLower()) {
            QMessageBox::warning(this, "Access Denied", "Role mismatch! You cannot log in as " + QString::fromStdString(selectedRole) + ".");
            return;
        }

        emit loginSuccess(QString::fromStdString(user), QString::fromStdString(fileRole));
        usernameEdit->clear();
        passwordEdit->clear();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

void LoginWidget::onRegisterClicked() {
    std::string user = usernameEdit->text().toStdString();
    std::string pass = passwordEdit->text().toStdString();
    std::string role = roleCombo->currentText().toStdString();

    if (user.empty() || pass.empty()) {
        QMessageBox::warning(this, "Registration Failed", "Username and password cannot be empty.");
        return;
    }

    if (loginBackend->registerUser(user, pass, role)) {
        QMessageBox::information(this, "Success", "Registration successful. Please login.");
        usernameEdit->clear();
        passwordEdit->clear();
    } else {
        QMessageBox::warning(this, "Error", "Failed to register user. File error.");
    }
}
