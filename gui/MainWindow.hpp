#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include "../core/Workspace.hpp"

class LoginWidget;
class CustomerWidget;
class OwnerWidget;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onLoginSuccess(const QString& username, const QString& role);
    void onLogout();

private:
    QStackedWidget *stackedWidget;
    LoginWidget *loginWidget;
    CustomerWidget *customerWidget;
    OwnerWidget *ownerWidget;

    Workspace *mainWorkspace;
};
