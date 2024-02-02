// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "app_environment.h"
#include "import_qml_components_plugins.h"
#include "import_qml_plugins.h"
#include "src/task.h"
#include "src/taskhttpclient.h"
#include "src/taskmodel.h"

int main(int argc, char *argv[])
{
    set_qt_environment();

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/qt/qml/Main/main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
    engine.addImportPath(":/");

    TaskHttpClient *client = new TaskHttpClient();
    QList<Task*> tasks = client->GetAllTasks();

    qmlRegisterType<TaskModel>("TaskModel", 1, 0, "TaskModel"); // zarejestrowanie typu po nazwie klasy do modułu MyModule o wersji 1.0

    for(int i = 0; i < tasks.length(); i++) {
        qDebug() << tasks.at(i)->id() << " " << tasks.at(i)->name();
    }
    engine.load(url);

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
