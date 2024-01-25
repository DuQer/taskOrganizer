#ifndef TASKHTTPCLIENT_H
#define TASKHTTPCLIENT_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>

class TaskHttpClient
{
public:
    TaskHttpClient();
    QByteArray makeGetRequest(const QUrl& url);
};

#endif // TASKHTTPCLIENT_H
