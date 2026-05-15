#pragma once
#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QLabel>
#include "../core/Workspace.hpp"
#include "../Owner/Owner.h"

class OwnerWidget : public QWidget {
    Q_OBJECT

public:
    OwnerWidget(Workspace *ws, QWidget *parent = nullptr);
    void setupOwner(const QString& username);

signals:
    void logoutRequested();

private slots:
    void refreshTable();
    void onAddRoom();
    void onEditRoom();
    void onDeleteRoom();
    void onLogout();

private:
    Workspace *workspace;
    Owner *currentOwner;

    QLabel *welcomeLabel;
    QTableWidget *roomTable;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *logoutButton;
};
