#ifndef TASKHTTPCLIENT_H
#define TASKHTTPCLIENT_H

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class TaskHttpClient
{
public:
    TaskHttpClient();
    QByteArray GetAllTasks();
    QByteArray GetSingleTaskById(const QUrl &url, const int id);

private:
    QByteArray MakeGetRequest(const QUrl &url);
    QString BASIC_URL = "https://jsonplaceholder.typicode.com/todos"; // "http://localhost:8080/task-manager";
};

#endif // TASKHTTPCLIENT_H
