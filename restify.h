#ifndef RESTIFY_H
#define RESTIFY_H

#include <QtGui>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
class QHBoxLayout;
class QVBoxLayout;
class QTabWidget;
class QComboBox;
class QLineEdit;
class QPushButton;
class QTextEdit;
QT_END_NAMESPACE

class Restify : public QWidget
{
	Q_OBJECT

	public:
		Restify();
		QString getMethod();
		QString getUrl();

	private slots:
		void _request();
		void _requestReply(QNetworkReply *reply);
		void _toggleConfig();

	private:
		void _setupRequest();
		void _setupResponse();
		void _setHeaders(const QList<QPair<QByteArray, QByteArray> > headers, QTableWidget *table);

		QHBoxLayout *requestLayout;
		QVBoxLayout *layout;
		QComboBox *method;
		QLineEdit *url;
		QPushButton *submit;

		QPushButton *settings;
		QTextEdit *configHeaders;
		QTabWidget *configLayout;

		QTabWidget *responseLayout;
		QTextEdit *responseContent;
		QTableWidget *responseHeadersReceived, *responseHeadersSent;
		QNetworkAccessManager *networkAccess;
		QNetworkReply *requestReply;
};

#endif
