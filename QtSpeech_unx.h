/*  QtSpeech -- a small cross-platform library to use TTS
    Copyright (C) 2010-2011 LynxLine.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General
    Public License along with this library; if not, write to the
    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301 USA */

#ifndef QtSpeech_unx_H
#define QtSpeech_unx_H

#include <QObject>
#include <QtSpeech>
#include <QStringList>

namespace QtSpeech_v1 { // API v1.0

class QtSpeech_th : public QObject {
Q_OBJECT
public:
    QtSpeech_th(QObject * p =0L);
    QtSpeech_th(const QString language, QObject * p =0L);
    virtual ~QtSpeech_th() {}

public slots:
    void say(const QString text);
    void setLanguage(const QString lang);
    QStringList getLanguages();

signals:
    void logicError(QtSpeech::LogicError);
    void finished();

private:
    friend class QtSpeech;
    QtSpeech::LogicError err;
    bool has_error;
    static bool init;
    QStringList languages;
    QString language;

    void initFestival();
};

}; // namespace QtSpeech_v1
#endif // QtSpeech_unx_H

