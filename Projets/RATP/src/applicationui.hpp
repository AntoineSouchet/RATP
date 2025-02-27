/*
 * Copyright (c) 2011-2015 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
    #include <QVariant>

#include <QtLocationSubset/QGeoPositionInfo>
#include <QtLocationSubset/QGeoPositionInfoSource>
#include <QtNetwork>
#include <bb/platform/bbm/Context>
#include <bb/platform/bbm/MessageService>
#include <bb/platform/bbm/UserProfile>

using namespace QtMobilitySubset;
namespace bb
{
    namespace cascades
    {
        class LocaleHandler;
    }
}

class QTranslator;
class QPoint;

/*!
 * @brief Application UI object
 *
 * Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class ApplicationUI : public QObject
{
    Q_OBJECT
public:
    ApplicationUI();
    virtual ~ApplicationUI() {}
    Q_INVOKABLE void Map(double latitude,double longitude,QString adresse);
    Q_INVOKABLE void MoreNear(double latitude,double longitude,QString adresse);
    Q_INVOKABLE void positionUpdated(QGeoPositionInfo geoPositionInfo);
    Q_INVOKABLE QString startGPS();
    Q_INVOKABLE void BBWorld();
    Q_INVOKABLE void facebookOpen();
//    Q_INVOKABLE
//        void inviteUserToDownloadViaBBM();
//        Q_INVOKABLE
//        void updatePersonalMessage(const QString &message);
private slots:
    void onSystemLanguageChanged();
private:

    QTranslator* m_pTranslator;
    bb::cascades::LocaleHandler* m_pLocaleHandler;
    QGeoPositionInfoSource *locationDataSource;
    QString lat;
    QString longi;
//    bb::platform::bbm::UserProfile * m_userProfile;
//           bb::platform::bbm::Context *m_context;
//           bb::platform::bbm::MessageService *m_messageService;
//           Q_SLOT
//           void registrationStateUpdated(
//                   bb::platform::bbm::RegistrationState::Type state);
};

#endif /* ApplicationUI_HPP_ */
