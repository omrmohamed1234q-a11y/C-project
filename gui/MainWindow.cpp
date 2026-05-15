#include "MainWindow.hpp"
#include "LoginWidget.hpp"
#include "CustomerWidget.hpp"
#include "OwnerWidget.hpp"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Booked & Beyond");
    resize(800, 600);

    mainWorkspace = new Workspace("Main Workspace", "C:/Users/HP/CLionProjects/C-project-1/data/rooms.txt");
    mainWorkspace->loadRooms();

    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    loginWidget = new LoginWidget(this);
    customerWidget = new CustomerWidget(mainWorkspace, this);
    ownerWidget = new OwnerWidget(mainWorkspace, this);

    stackedWidget->addWidget(loginWidget);
    stackedWidget->addWidget(customerWidget);
    stackedWidget->addWidget(ownerWidget);

    connect(loginWidget, &LoginWidget::loginSuccess, this, &MainWindow::onLoginSuccess);
    connect(customerWidget, &CustomerWidget::logoutRequested, this, &MainWindow::onLogout);
    connect(ownerWidget, &OwnerWidget::logoutRequested, this, &MainWindow::onLogout);

    stackedWidget->setCurrentWidget(loginWidget);
}

MainWindow::~MainWindow() {
    delete mainWorkspace;
}

void MainWindow::onLoginSuccess(const QString& username, const QString& role) {
    QString r = role.toLower();
    if (r == "customer") {
        customerWidget->setupCustomer(username);
        stackedWidget->setCurrentWidget(customerWidget);
    } else if (r == "owner") {
        ownerWidget->setupOwner(username);
        stackedWidget->setCurrentWidget(ownerWidget);
    }
}

void MainWindow::onLogout() {
    stackedWidget->setCurrentWidget(loginWidget);
}
