#ifndef IMAGE_H
#define IMAGE_H

#include <QObject>

class Image : public QObject
{
    Q_OBJECT

    QString m_name;
    QString m_url;


public:
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged FINAL)

    Image(const QString &name, const QString &url) : m_name(name), m_url(url) {;}

    QString name() const {
        return m_name;
    }

    QString url() const {
        return m_url;
    }

public slots:
    void setName(QString name);
    void setUrl(QString url);

signals:
    void nameChanged(QString name);
    void urlChanged(QString url);
};

#endif // IMAGE_H
