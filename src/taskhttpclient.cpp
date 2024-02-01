#include "taskhttpclient.h"
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include "mapper/taskjsonmapper.h"

TaskHttpClient::TaskHttpClient()
{

}

Task* TaskHttpClient::GetSingleTaskById(const QUrl &url, const int id) {
    return TaskJSONMapper::FromJSON(MakeGetRequest(BASIC_URL));
}

QList<Task*> TaskHttpClient::GetAllTasks() {
    //QString GET_ALL_TASKS_URL = BASIC_URL + "/task";
    QByteArray ByteArray = MakeGetRequest(BASIC_URL);
    QList<Task*> tasks = TaskJSONMapper::ListFromJSON(ByteArray);
    return tasks;
}

// this method is more generic - it returns some byte array but not specifically one task or list of tasks
QByteArray TaskHttpClient::MakeGetRequest(const QUrl &url)
{
    QNetworkAccessManager manager;
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        return reply->readAll();
    } else {
        qWarning() << "Request failed:" << reply->errorString();
        return QByteArray();
    }
}
