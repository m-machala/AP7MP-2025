#include "image.h"

void Image::setName(QString name) {
    if(m_name == name) {
        return;
    }

    m_name = name;
    emit nameChanged(name);
}

void Image::setUrl(QString url) {
    if(m_url == url) {
        return;
    }

    m_url = url;
    emit urlChanged(url);
}
